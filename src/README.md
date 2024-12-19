# Code Overview

## Files

- **src/spark.c**: Handles communication with the CO2 sensor and processes CO2 data.
- **src/sparkBLE.cpp**: Manages the Bluetooth Low Energy (BLE) setup and communication, broadcasting CO2 and temperature data over BLE to a connected device.

## Code Explanation

### 1. spark.c
This file contains the logic for:
- Interfacing with the SparkFun STC3x CO2 sensor using the I2C communication protocol.
- Reading CO2 concentration and temperature data from the sensor.
- Handling the sensor's initialization and error checking.

### 2. sparkBLE.cpp
This file contains the logic for:
- Setting up the Bluetooth Low Energy (BLE) communication on the Arduino.
- Advertising the device as a BLE peripheral that sends CO2 concentration and temperature data to a central device.
- Handling BLE connections and disconnections with visual feedback using an LED.'

### 3. readAirSense.py
This file contains the logic for:
- Searching for nerby the AirSenseCO2 using BLE, using its MAC-adress.
- Saves the read data in 2 seperate .csv files for later analyze of data in excel.
  
The BLE service includes two main characteristics:
- **CO2 Concentration Characteristic**: Sends the CO2 concentration in percentage.
- **Temperature Characteristic**: Sends the temperature in Celsius.

## Software Setup

### Prerequisites
1. Install the [Arduino IDE](https://www.arduino.cc/en/software) if not already installed.
2. Install the necessary libraries via the Arduino Library Manager:
   - **SparkFun STC3x**: For interfacing with the CO2 sensor.
   - **ArduinoBLE**: For enabling BLE communication.

### Uploading Code
1. Clone or download this repository and open it in the Arduino IDE.
2. Open the `sparkBLE.cpp` and `spark.c` files in the Arduino IDE.
3. Ensure the correct board and port are selected in the IDE.
4. Click the **Upload** button to upload the code to your Arduino.

### Running the Project
1. Once the code is uploaded, the Arduino will begin measuring CO2 levels.
2. The LED will pulse when the device is advertising BLE and will stay solid when a BLE device is connected.
3. Use a BLE-compatible device to connect to the Arduino and receive CO2 and temperature data.

## Dependencies
- **ArduinoBLE**: For handling BLE communication.
- **Wire**: For I2C communication with the CO2 sensor.
- **SparkFun STC3x**: For working with the CO2 sensor.

## Contributing
Contributions are welcome! Feel free to fork this project and make improvements. If you have any suggestions or enhancements, please submit a pull request or open an issue.
