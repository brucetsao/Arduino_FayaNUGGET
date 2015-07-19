/*
 fayalab leaf sample code for leaf-RTC
 
 This example will show the usage of RTC module.
 1.You need unmark the line 32 , and set up time value in function setDateTime()
 2.Mark setDateTime of line 32. Enjoy your real-time clock!
 
 Auther : welly 
 Date : 2015/03/18
 
 Wiring Guide :
fayaduino pin  A4 <-----> leaf pin "SDA"
fayaduino pin  A5 <-----> leaf pin "SCL"
fayaduino pin  5V <-----> leaf pin "VCC"
fayaduino pin GND <-----> leaf pin "GND"
 
*/

#include <Wire.h>
#define DS1307_ADDRESS 0x68

byte zero = 0x00; //workaround for issue #527

void setup()  {
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  printDate();
  //First you need to setting the current time! then comment it like this afterward !
  //setDateTime();  //SETtime
}

byte bcdToDec(byte val)  {
// Convert binary coded decimal to normal decimal numbers
  return ( (val/16*10) + (val%16) );
}

byte decToBcd(byte val){
// Convert normal decimal numbers to binary coded decimal
  return ( (val/10*16) + (val%10) );
}


void printDate(){
  // Reset the register pointer
  Wire.beginTransmission(DS1307_ADDRESS);

  byte zero = 0x00;
  Wire.write(zero);
  Wire.endTransmission();

  Wire.requestFrom(DS1307_ADDRESS, 7);

  int second = bcdToDec(Wire.read());
  int minute = bcdToDec(Wire.read());
  int hour = bcdToDec(Wire.read() & 0b111111); //24 hour time
  int weekDay = bcdToDec(Wire.read()); //0-6 -> sunday - Saturday
  int monthDay = bcdToDec(Wire.read());
  int month = bcdToDec(Wire.read());
  int year = bcdToDec(Wire.read());
  int sp ;
  
  sp = hour*100 + minute;
  
  Serial.print(year);
  Serial.print("/");
  Serial.print(month);
  Serial.print("/");
  Serial.print(monthDay);
  Serial.print(" ");
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.print(second);
  Serial.println("");
}


void setDateTime(){

  byte second =      00; //0-59
  byte minute =      23; //0-59
  byte hour =        12; //0-23
  byte weekDay =     4; //1-7
  byte monthDay =    19; //1-31
  byte month =       3; //1-12
  byte year  =       15; //0-99

  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); //stop Oscillator

  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(weekDay));
  Wire.write(decToBcd(monthDay));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));

  Wire.write(zero); //start 
  Wire.endTransmission();

}
