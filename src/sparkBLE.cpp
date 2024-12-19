#include <Wire.h>
#include <ArduinoBLE.h>  // Includes the BLE library for handling Bluetooth Low Energy on Nano 33 BLE
#include "SparkFun_STC3x_Arduino_Library.h"  // Includes the library for using the STC3x CO2 sensor

STC3x mySensor;  // Creates an object for the CO2 sensor

// Define BLE service and characteristics for CO2 and temperature
BLEService sensorService("180C");  // Defines a custom BLE service with a specific UUID (180C in hex)
BLECharacteristic co2Characteristic("2A6E", BLERead | BLENotify, 20);  // Defines a characteristic for CO2 levels (read and notify) as a string (20 bytes max)
BLECharacteristic tempCharacteristic("2A6F", BLERead | BLENotify, 20); // Defines a characteristic for temperature (read and notify) as a string (20 bytes max)

// Variables for LED pulsing when not connected
const int yellowLedPin = 13;  // Built-in yellow/orange LED pin
unsigned long previousMillis = 0;
const long pulseInterval = 500;  // Interval at which to blink (500 ms)
bool ledState = LOW;

void setup() {
  Serial.begin(115200);  
  if (Serial) {
  while (!Serial);  
}
  
  // Initialize the CO2 sensor
  Wire.begin();  // Starts I2C communication
  if (mySensor.begin() == false) {  // Checks if the sensor is connected properly
    Serial.println(F("Sensor not detected. Please check wiring. Freezing..."));  // If not, print error message and halt the program
    while (1);
  }

  // Set the sensor's binary gas (CO2 in air, 25% range)
  if (mySensor.setBinaryGas(STC3X_BINARY_GAS_CO2_AIR_25) == false) {  // Configures the sensor to measure CO2
    Serial.println(F("Could not set the binary gas! Freezing..."));  // If it fails, print error message and halt the program
    while (1);
  }

  // Initialize BLE
  if (!BLE.begin()) {  // Checks if the BLE module starts correctly
    Serial.println("* Starting BluetoothÂ® Low Energy module failed!");  // If not, print error message and halt the program
    while (1);
  }

  // Set BLE name and advertising
  BLE.setDeviceName("AirSenseCO2");  // Sets the name of the BLE device shown in the BLE terminal
  BLE.setLocalName("AirSenseCO2");
  BLE.setAdvertisedService(sensorService);  // Associates the defined service with advertising

  // Add CO2 and temperature characteristics to the service
  sensorService.addCharacteristic(co2Characteristic);  // Adds the CO2 characteristic to the service
  sensorService.addCharacteristic(tempCharacteristic); // Adds the temperature characteristic to the service
  BLE.addService(sensorService);  // Adds the service to BLE

  // Start advertising
  BLE.advertise();  // Starts advertising so devices can find this unit via BLE
  Serial.println("BLE is now advertising...");  // Prints a message indicating that BLE advertising is active
}

void loop() {
  // Wait for a connection from a central device (e.g., BLE terminal)
  BLEDevice central = BLE.central();  // Waits for a central device to connect
  if (central) {  // When a device connects
  
    digitalWrite(yellowLedPin, HIGH); //Yellow led lamp

    Serial.print("Connected to central: ");
    Serial.println(central.address());  // Prints the address of the connected device

    // Measure and send sensor data while the device is connected
    while (central.connected()) {  // As long as the central device is connected
    
      if (mySensor.measureGasConcentration()) {  
        float co2_percent = mySensor.getCO2();  
        float temp = mySensor.getTemperature();  

        // Convert CO2 from % to ppm
        float co2_ppm = co2_percent * 10000.0;

        // Print data to the Serial Monitor in ppm
        Serial.print(F("CO2(ppm): "));
        Serial.print(co2_ppm, 2);
        Serial.print(F("\tTemperature(C): "));
        Serial.println(temp, 2);

        // Create buffers for the formatted strings
        char co2Str[20];
        char tempStr[20];

        // Format CO2 in ppm and temperature
        snprintf(co2Str, sizeof(co2Str), "CO2: %.2f PPM", co2_ppm);
        snprintf(tempStr, sizeof(tempStr), "Temp: %.2f C", temp);

        // Send data via BLE
        co2Characteristic.writeValue(co2Str);
        tempCharacteristic.writeValue(tempStr);
      
       }
        delay(1000);  // Waits one second before the next measurement
      }
      
    Serial.println("Disconnected from central.");  // Prints a message when the central device disconnects 
  }  else {
    // If not connected, pulse the yellow/orange LED
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= pulseInterval) {  
      previousMillis = currentMillis;

      // If the LED is off, turn it on, and vice versa
      ledState = !ledState;
      digitalWrite(yellowLedPin, ledState);
    }
  }
}
