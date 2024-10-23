# AirsenseCO2: a CO2 and Temperature Sensing Mask for Athletes

This project aims to develop a smart mask for athletes to monitor CO2 levels and temperature in real-time, helping to track respiratory performance during physical activities. The sensor is embedded in a gas mask-like design and captures real-time data, providing athletes and fitness enthusiasts with insights into their CO2 exhalation and respiratory patterns.

The mask is particularly useful for monitoring breathing efficiency, CO2 combustion, and overall respiratory performance during exercise. By connecting the device to a Bluetooth-enabled phone or tablet, users can view real-time data on their CO2 levels and temperature via a dedicated app.

## Early prototype
  <a href="https://github.com/Mylo90/CO2-Mask/tree/main/docs/earlyPrototype" target="_blank">
    <img src="https://github.com/Mylo90/CO2-Mask/blob/main/docs/earlyPrototype/prototype.jpg" alt="Earlyprototype" style="border-radius: 50%; width: 400px; height: 400px; object-fit: cover; border: 2px solid white;">
</a>


## Table of contents 
- [Early Prototype](https://github.com/Mylo90/CO2-Mask/tree/main?tab=readme-ov-file#early-prototype)
- [Table of Contents](https://github.com/Mylo90/CO2-Mask/tree/main?tab=readme-ov-file#Table-of-contents)
- [Key Features](https://github.com/Mylo90/CO2-Mask/tree/main?tab=readme-ov-file#key-features)
- [Prerequisites](https://github.com/Mylo90/CO2-Mask/tree/main?tab=readme-ov-file#prerequisites)
- [Setup](https://github.com/Mylo90/CO2-Mask/tree/main?tab=readme-ov-file#setup)
- [Future Improvements](https://github.com/Mylo90/CO2-Mask/tree/main?tab=readme-ov-file#future-improvements)
- [Contributors](https://github.com/Mylo90/CO2-Mask/tree/main?tab=readme-ov-file#contributors)

### Folder Structure
#### [`docs`](https://github.com/Mylo90/CO2-Mask/tree/main/docs)
The `docs` contains the documentation files for the project ([first prototype](https://github.com/Mylo90/CO2-Mask/tree/main/docs/earlyPrototype)), including [Lean Canvas](https://github.com/Mylo90/CO2-Mask/blob/main/docs/leancanvas.pdf), diagrams and other resources to help users understand hardware connections and how to use the CO2 Mask system.

#### [`src`](https://github.com/Mylo90/CO2-Mask/tree/main/src)
The `src` folder contains the source code for the project. It includes the firmware that runs on the microcontroller to manage sensor data, perform CO2 and temperature monitoring, and handle Bluetooth communication for real-time data transmission.

## Key Features
- **Continuous CO2 and Temperature Monitoring**: Tracks exhaled CO2 concentration and breath temperature in real time for a comprehensive view of respiratory function.
- **Bluetooth Connectivity**: Seamlessly transmits real-time data to paired devices, allowing live monitoring via a smartphone or fitness tracker.
- **Compact and Lightweight Design**: Easily integrates into sportswear or fitness gear, ensuring comfort during any activity.

## Target Audience
- **Athletes** aiming to enhance respiratory efficiency and optimize breathing during physical exertion.
- **Fitness Enthusiasts** looking to improve their workout performance by monitoring and adjusting breathing techniques.

## Prerequisites
### Hardware
- **CO2 and temperature sensor**: [CO2 Click sensor](https://www.mikroe.com/co2-click)    cost: €137.91  <br />
- **Microcontroller**: [Arduino Nano 33 BLE](https://store.arduino.cc/en-se/products/nano-33-ble-rev2)   cost: €29,00  <br />
- **Gas mask**: [3M Series 6000 Mask](https://www.tradeinn.com/waveinn/en/3m-series-6000-mask/138958956/p?utm_source=google_products&utm_medium=merchant&id_producte=16274255&country=se)   cost: €30.51 <br />
- **Mask front attachment**: [3D printed 3M mask component](https://www.thingiverse.com/thing:4492721) <br />
- **PCB card**: [Airsense PCB](https://github.com/Mylo90/CO2-Mask/blob/main/docs/earlyPrototype/pcb)   <br />
- **9V battery** <br />
- **Breadboard, wires**

### Software
- Install [Arduino IDE](https://www.arduino.cc/en/software) on your development environment.
- Make sure to install the packages used in the codes:<br />
	- `Wire.h` <br />
  	- `ArduinoBLE.h` <br />
 	- `SparkFun_STC3x_Arduino_Library.h` <br />
- Install "LightBlue" to your moble device. Available for [Android](https://play.google.com/store/apps/details?id=com.punchthrough.lightblueexplorer&hl=en_US&pli=1) and [iOS](https://apps.apple.com/se/app/lightblue/id557428110)

## Setup <br />
1. **Prerequisites**: Ensure you have the correct [hardware](https://github.com/Mylo90/CO2-Mask/tree/main?tab=readme-ov-file#hardware) and [software](https://github.com/Mylo90/CO2-Mask/tree/main?tab=readme-ov-file#software) installed. 
   
2. **Clone the Repository**: <br />
   `git clone https://github.com/Mylo90/CO2-Mask.git`<br />
   `cd CO2-Mask`
3. **Upload Firmware to Microcontroller**: <br /> Connect the microcontroller to your computer, and upload the firmware

4. **Hardware Setup**: <br /> Connect the STC31 CO2 sensor to the microcontroller following the wiring diagram provided in the repository.

5. **Bluetooth Pairing**: <br /> Enable Bluetooth on your mobile device and pair your device to the Arduino using the phone applicaiton "LightBlue" (Available at [Android](https://play.google.com/store/apps/details?id=com.punchthrough.lightblueexplorer&hl=en_US&pli=1) and [iOS](https://apps.apple.com/se/app/lightblue/id557428110)).

6. **Start Monitoring**: <br /> Once paired, you can start your workout, and the CO2-Mask will monitor and transmit data such as CO2 concentration and temperature in real time to your mobile device.

## Future Improvements

1.	**Enhanced sensors**: Add more environmental sensors (humidity, oxygen levels, VOCs) for broader data analysis.

2.	**Data logging**: Implement onboard data storage (SD card or cloud) to analyze long-term trends without constant Bluetooth connection.

3.	**Mobile app**: Develop a dedicated mobile app for better real-time data visualization and user-friendly dashboards.

4.	**Comfort enhancements**: Improve the design for comfort and usability, particularly for athletes during physical activities.

5.	**Battery Optimization**: Introduce low-power modes or solar charging to extend battery life.

6.	**AI Integration**: Use machine learning models to analyze respiratory patterns and predict performance metrics or potential issues.
	
7.	**Real-time Alerts**: Add notifications for abnormal CO2 levels or temperature spikes during exercise to prevent health risks.
	
8.	**Cross-Platform Syncing**:Allow synchronization with fitness apps like Apple Health or Google Fit to aggregate data with other workout metrics.

## Contributors
<p align="left">
  <a href="https://github.com/RasmusHR" target="_blank">
    <img src="https://github.com/RasmusHR.png" alt="RasmusHR" style="border-radius: 50%; width: 40px; height: 40px; object-fit: cover; border: 2px solid white;">
  </a>
  <a href="https://github.com/Mylo90" target="_blank">
    <img src="https://github.com/Mylo90.png" alt="Mylo90" style="border-radius: 50%; width: 40px; height: 40px; object-fit: cover; border: 2px solid white;">
  </a>
  <a href="https://github.com/EmmaJson" target="_blank">
    <img src="https://github.com/EmmaJson.png" alt="EmmaJson" style="border-radius: 50%; width: 40px; height: 40px; object-fit: cover; border: 2px solid white;">
  </a>
  <a href="https://github.com/Lovathoren" target="_blank">
    <img src="https://github.com/Lovathoren.png" alt="Lovathoren" style="border-radius: 50%; width: 40px; height: 40px; object-fit: cover; border: 2px solid white;">
  </a>
 <a href="https://github.com/90dennis" target="_blank">
    <img src="https://github.com/90dennis.png" alt="90dennis" style="border-radius: 50%; width: 40px; height: 40px; object-fit: cover; border: 2px solid white;">
  </a>
</p>





