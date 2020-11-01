#include "DHT.h"
#include "LiquidCrystal.h"

// DHT22 temp/humidity sensor on pin 13
#define DHTPIN 13
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// 16x2 LCD module
// Display Parameters: RS, E, D4, D5, D6, D7
LiquidCrystal lcd = LiquidCrystal(2, 3, 4, 5, 6, 7);

void setup() {
  lcd.begin(16,2);
  dht.begin();
}

void loop() {
  delay(2000);

  // read humidity
  float humidity = dht.readHumidity();
  // read temp
  float temperature = dht.readTemperature(true);

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print((char)223); // ref: https://www.openhacks.com/uploadsproductos/eone-1602a1.pdf
  lcd.print("F");

  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
}
