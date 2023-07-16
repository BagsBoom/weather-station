# Weather Station
This repository contains the code for a weather station built using Arduino. The weather station measures temperature, humidity, and displays the readings on an LCD screen. It also includes a real-time clock module for displaying the current date and time.
## Components used
- Arduino board (UNO or similar)
- DHT11 temperature and humidity sensor
- DS1302 real-time clock module
- LCD1602 display with I2C interface
## Installation
1. Clone or download the repository: git clone https://github.com/BagsBoom/weather-station.git
2. Connect the Arduino board to your computer.
3. Open the Arduino IDE.
4. Open the weather-station.ino file in the IDE.
5. Select the appropriate board and port from the Tools menu and also you NEED to download libraries.
6. Click the Upload button to upload the code to the Arduino board.
## Usage
1. Connect the DHT11 sensor to the designated pin on the Arduino board.
2. Connect the DS1302 real-time clock module to the corresponding pins on the Arduino board.
3. Connect the LCD1602 display to the I2C interface on the Arduino board.
4. Power up the Arduino board.
5. The weather station will start displaying temperature, humidity, date, and time on the LCD screen.


