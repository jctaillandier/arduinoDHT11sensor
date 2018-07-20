#include <LiquidCrystal.h>
#include <DHT.h>
#include <math.h>
#include "DHT.h"

#define DHTPIN 8     // what digital pin tempSensor is connected to


#define DHTTYPE DHT11   // DHT 11
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


void setup() {
  Serial.begin(9600);
  Serial.println("Temperature Recorder");

  dht.begin();

  // Now LiquidCrystal led monitor stuff
  lcd.begin(16,2);
  lcd.setCursor(2,0);
  lcd.print("** Wanet **");
  delay(1500);
  lcd.setCursor(1,1);
  lcd.print("Motherfuckers.");
  delay(3000);
  lcd.clear();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C     ");
  Serial.print(f);
  Serial.print(" *F\t");
//  Serial.print(" | Heat index: ");
//  Serial.print(hic);
//  Serial.print(" *C ");
//  Serial.print(hif);
//  Serial.print(" *F");
//  Serial.print("| Time:");
//  Serial.println();
  Serial.println("------------------------------------");

  //led screen printing
  lcd.setCursor(0,0);
  lcd.print("Temp:  Humidity:");
  lcd.setCursor(0,1);
  lcd.print(t);
  lcd.print("   ");
  lcd.print(round(h));
  lcd.print("%");
}





