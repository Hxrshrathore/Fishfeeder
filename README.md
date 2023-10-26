# 🐟 Arduino Fish Feeder with IoT 🤖

Welcome to the Arduino Fish Feeder project! This is a complete guide to building an automated fish feeder with IoT capabilities. With this project, you can feed your fish remotely, monitor water quality, and receive low battery alerts right from your smartphone.

## Features

🎚️ **Adjustable Portion Control**: Control the amount of food dispensed based on your preference.

🌊 **Water Quality Sensor Integration**: Monitor the health of your fish by checking water quality.

📈 **Data Logging**: Log feeding and environmental data to EEPROM or a cloud service.

📲 **Remote Feeding**: Trigger feeding cycles from your mobile app.

🔌 **Manual Override**: Manually trigger feedings when needed.

🔋 **Battery Monitoring**: Receive alerts when the battery is running low.

## Hardware Requirements

- Arduino board (e.g., Arduino MKR1000)
- Servo motor
- Water quality sensor (specific type may vary)
- LEDs
- Battery (if not using external power)
- Mobile device with Blynk app

## Installation

1. Clone this repository to your local machine.

```bash
git clone https://github.com/Hxrshrathore/fishfeeder.git
```

2. Open the Arduino IDE and load the project.

3. Make sure to install the necessary libraries:

   - Servo library
   - ESP8266WiFi library
   - Blynk library
   - TimeLib library

4. Connect your hardware components according to the wiring instructions.

5. Configure the Wi-Fi and Blynk settings in the Arduino code.

6. Upload the code to your Arduino board.

7. Open the Blynk app on your mobile device and load the project QR code or input the authentication token.

## Usage

1. The feeder operates based on the schedule you set or manual feeding from the app.

2. Water quality data is displayed in the Blynk app for monitoring.

3. Check the mobile app for low battery alerts.

4. You can manually trigger feedings and adjust the portion from the app.

## Contributing

We welcome contributions! Feel free to fork this repository, make changes, and submit pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by fish enthusiasts everywhere.
- Thank you to the Arduino and Blynk communities.

Happy fish feeding! 🐠🐟
