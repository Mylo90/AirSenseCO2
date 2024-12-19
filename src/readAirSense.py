import asyncio
from bleak import BleakScanner, BleakClient

DEVICE_NAME = "AirSenseCO2"
CO2_CHARACTERISTIC_UUID = "2A6E"
TEMP_CHARACTERISTIC_UUID = "2A6F"

async def main():
    print("Scanning for BLE devices...")
    devices = await BleakScanner.discover()
    target_device = None

    for d in devices:
        if d.name == DEVICE_NAME:
            target_device = d
            break

    if not target_device:
        print(f"Device named '{DEVICE_NAME}' not found.")   
        return

    print(f"Found {DEVICE_NAME} with address {target_device.address}. Attempting to connect...")

    async with BleakClient(target_device.address) as client:
        connected = await client.is_connected()
        if connected:
            print(f"Connected to {DEVICE_NAME}")

            services = await client.get_services()
            co2_char = None
            temp_char = None

            for service in services:
                for char in service.characteristics:
                    if char.uuid.endswith(CO2_CHARACTERISTIC_UUID.lower()):
                        co2_char = char
                    elif char.uuid.endswith(TEMP_CHARACTERISTIC_UUID.lower()):
                        temp_char = char

            if not co2_char:
                print(f"CO2 characteristic {CO2_CHARACTERISTIC_UUID} not found.")
                return
            if not temp_char:
                print(f"Temperature characteristic {TEMP_CHARACTERISTIC_UUID} not found.")
                return

            print("Reading data (press Ctrl+C to stop)...")
            try:
                while True:
                    co2_data = await client.read_gatt_char(co2_char.uuid)
                    temp_data = await client.read_gatt_char(temp_char.uuid)

                    co2_str = co2_data.decode('utf-8').strip()
                    temp_str = temp_data.decode('utf-8').strip()

                    print(f"Received CO2: {co2_str}, Temp: {temp_str}")
                    await asyncio.sleep(2.0)
            except KeyboardInterrupt:
                print("Stopping read loop...")
        else:
            print("Failed to connect to the device.")

if __name__ == "__main__":
    asyncio.run(main())
