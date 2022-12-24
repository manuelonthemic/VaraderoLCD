

#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <Wire.h> // for I2C

#define i2caddr 0x50
#define Wire Wire

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {

  Serial.println("I2C start");
  // wake up the I2C
  Wire.begin();         

  Serial.println("LCD start");
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Varadero 125");

}

void loop() {

  //setEngineTemp(i);
  //setOdometr(readTotalOdometr());
  //setTrip(readTripOdometr());

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
