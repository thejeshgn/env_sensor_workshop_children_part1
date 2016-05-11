#include <LiquidCrystal.h>
#include "DHT.h"
/*
 * This is just putting them together
 * Setup Sensor part
 * Setup LCD part
 * And Run this.
 * 
 */


/***********************CONTANTS*******************************************/
#define LOOP_DELAY 2000
 
/**************************START of Temp Sensor Setup*********************/
#define DHTTYPE DHT22      // DHT22 or AM2302
#define DHTPIN 2           // Digital pin that we have the output of AM2302 connected to.
DHT dht(DHTPIN, DHTTYPE);  //setup
/*************************END of Temp Sensor Setup**********************/


LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setup() { 
  Serial.begin(9600); 
  dht.begin(); //Start the DHT
}

void loop() { 
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity(); //Read humidity as %
  float t = dht.readTemperature(); // Read temperature as Celsius


  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read Temp and humidity from DHT sensor!");
    return;
  }

  lcd.clear();
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.write("Welcome to");
  lcd.setCursor(0,1);
  lcd.write("#ODCBLR2016");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  String humidity = "Humidity: "+String(h,3)+" %";
  lcd.print(humidity);
  String temp = "Temp: "+String(t,3)+"*C";
  lcd.setCursor(0,1);
  lcd.print(temp);
  delay(2000);
  lcd.clear();
  lcd.print("Have fun kids");
  delay(1000);
    
  //logging
  Serial.print(temp); 
  Serial.print(humidity);
  
}
