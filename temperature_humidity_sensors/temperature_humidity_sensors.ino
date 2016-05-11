/* 
 * Code for reading temperature and humidity using AM2302 + UNO    
 * 
 *  Thejesh GN <thejeshgn.com>, 2016, GNU GPL v 3.0
 * 
 * 
 * 
 * Uses:
 * 1. DHT Library by Adafruit Industries, Available under MIT License
 *    https://github.com/adafruit/DHT-sensor-library
 * 2. 
 * 
 */
#include "DHT.h"


/***********************CONTANTS*******************************************/
#define LOOP_DELAY 2000
 
/**************************START of Temp Sensor Setup*********************/
#define DHTTYPE DHT22      // DHT22 or AM2302
#define DHTPIN 2           // Digital pin that we have the output of AM2302 connected to.
DHT dht(DHTPIN, DHTTYPE);  //setup
/*************************END of Temp Sensor Setup**********************/

 
void setup() {
  Serial.begin(9600); 
  dht.begin(); //Start the DHT
}
 
void loop() {
  delay(LOOP_DELAY); //Loop Delay
  
 
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity(); //Read humidity as %
  float t = dht.readTemperature(); // Read temperature as Celsius


  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read Temp and humidity from DHT sensor!");
    return;
  }
  



    
  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print(" *C \n");
}
