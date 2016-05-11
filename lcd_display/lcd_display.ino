#include <LiquidCrystal.h>

/* Connections:
 *  STEP 0. SETUP BREADBOARD
 *  Arduino 5v (pin 3)        -> plus column on breadboard
 *  Arduino GND (pin 4 or 5)  -> min column on breadboard
 *  
 *  STEP 1. POWER UP
 *  Connect: GND row (min) on breadboard > pin 1 on LCD (VSS)
 *  Connect: +5v row (plus) on breadboard > pin 2 on LCD (VDD)
 *  Connect: +5v row (plus) on breadboard > pin 15 on LCD (A)
 *  Connect: GND row (min) on breadboard > pin 16 on LCD (K)
 *  Now connect Arduino to power, LCD should light up and show boxes
 *  
 *  STEP 2. POT FOR CONTRAST
 *  Connect: 1st pin of the pot > GND (min) of the breadboard
 *  Connect: 2nd pin of the pot > pin 3 of the LCD display (VO)
 *  Connect: 3rd pin of the pot > +5v (plus) of bread board
 *  Now by changing the pot value you should be able to change the contrast
 *  
 *  STEP 3. CONNECT DATA Lines
 *  Connect: pin 4 of the LCD display (RS) > pin 7 of the Arduino (PWM)
 *  Connect: pin 5 of the LCD display (RW) > GND row of the breadboard
 *  Connect: pin 6 of the LCD display  (E) > pin 8 of the Arduino (PWM)
 *  Connect: pin 11 of the LCD display (D4) > pin 9 of the Arduino (PWM)
 *  Connect: pin 12 of the LCD display (D5) > pin 10 of the Arduino (PWM)
 *  Connect: pin 13 of the LCD display (D6) > pin 11 of the Arduino (PWM)
 *  Connect: pin 14 of the LCD display (D7) > pin 12 of the Arduino (PWM)
 *  
  */
 


LiquidCrystal lcd(7, 8, 9, 10, 11 , 12);

void setup() { 
}

void loop() { 
  lcd.clear();
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.write("#ODCBLR2016");
  lcd.setCursor(0,1);
  lcd.setCursor(0,2);
  delay(1000);
  lcd.write("Have fun kids");
  delay(2000);
  
}
