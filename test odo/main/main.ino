#include <EEPROM.h>
#include <Wire.h> 
#define i2caddr 0x50

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("serial initiated");
Wire.begin();
Serial.println("wire initiated");
Serial.print("total odo :");
Serial.println(readTotalOdometr());
Serial.print("trip odo :");
Serial.println(readTripOdometr());
}

void loop() {
  // put your main code here, to run repeatedly:

}

byte readData(unsigned int addr) {
  byte result;
  Wire.beginTransmission(i2caddr);
  // set the pointer position
  //Wire.write((int)(addr >> 8));
  Wire.write((int)(addr & 0xFF));
  Wire.endTransmission(1);
  Wire.requestFrom(i2caddr, 1);  // get the byte of data
  result = Wire.read();
  return result;
}

String readTotalOdometr() {
  int addr;
  char tmp;
  String result = "";
  for (addr = 0x70; addr < 0x78; addr++) {
    tmp = readData(addr);
    result += String(&tmp);
  }
  return result;
}

String readTripOdometr() {
  int addr;
  char tmp;
  String result = "";
  for (addr = 0x78; addr < 0x7D; addr++) {
    tmp = readData(addr);
    result += String(&tmp);
  }
  return result;
}
