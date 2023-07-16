#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RtcDS1302.h>

#define DHTPIN 7       // Pin connected to the DHT11 sensor
#define DHTTYPE DHT11  // DHT sensor type (DHT11)

DHT dht(DHTPIN, DHTTYPE);  // Create a DHT object for working with the DHT11 sensor

ThreeWire myWire(5, 4, 6);
RtcDS1302<ThreeWire> Rtc(myWire);  // Create an Rtc object for working with the DS1302 RTC module

LiquidCrystal_I2C lcd(0x3F, 16, 2);  // I2C module address and display dimensions

void setup() {
  Serial.begin(9600);  // Initialize the Serial Monitor
  dht.begin();         // Initialize the DHT11 sensor

  lcd.init();
  lcd.begin(16, 2);  // Initialize the LCD1602
  lcd.backlight();

  Rtc.Begin();
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);  // Get the compilation date and time
  Rtc.SetDateTime(compiled);                               // Set the date and time for the DS1302 module
}

void loop() {
  // Display temperature and humidity for 10 seconds
  for (int i = 0; i < 10; i++) {
    delay(1000);
    float humidity = dht.readHumidity();        // Read humidity
    float temperature = dht.readTemperature();  // Read temperature in degrees Celsius

    // Check if the data reading was successful
    if (isnan(humidity) || isnan(temperature)) {
      Serial.println("Error reading data from the DHT11 sensor!");
      lcd.clear();  // Clear the LCD1602 screen
      lcd.setCursor(0, 0);
      lcd.print("DHT11 Error");
      return;
    }

    // Display temperature and humidity on the LCD1602
    lcd.clear();  // Clear the LCD1602 screen
    lcd.setCursor(0, 0);
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature);
    lcd.print("C");

    // Display temperature and humidity in the Serial Monitor
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%  Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
  }

  // Display date and time for 5 seconds
  for (int i = 0; i < 5; i++) {
    RtcDateTime now = Rtc.GetDateTime();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Date: ");
    lcd.print(now.Month());
    lcd.print("/");
    lcd.print(now.Day());
    lcd.print("/");
    lcd.print(now.Year());
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(now.Hour());
    lcd.print(":");
    lcd.print(now.Minute());
    lcd.print(":");
    lcd.print(now.Second());

    // Display date and time in the Serial Monitor
    Serial.print("Date: ");
    Serial.print(now.Month());
    Serial.print("/");
    Serial.print(now.Day());
    Serial.print("/");
    Serial.print(now.Year());
    Serial.print("  Time: ");
    Serial.print(now.Hour());
    Serial.print(":");
    Serial.print(now.Minute());
    Serial.print(":");
    Serial.println(now.Second());
    delay(1000);
  }
}
