// Date and time functions using a DS1307 RTC connected 

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

//variable and functions for fayalab-nugget-7seg
#define Numpin 9  // define the start pin for show number, need to link to "A" pin in the fayalab-nugget
#define Digitpin 10  // define the start pin for digits, need to link to "S1" pin in the fayalab-nugget

int digit[4][3]={{0,0,0},  //units digit
                 {1,0,0},  //tens digit
                 {0,1,0},  //hundreds digit
                 {1,1,0}}; //thousands digit

int Num[10][8]={{1,1,1,1,1,1,0,0},  //0
                {0,1,1,0,0,0,0,0},  //1
                {1,1,0,1,1,0,1,0},  //2
                {1,1,1,1,0,0,1,0},  //3
                {0,1,1,0,0,1,1,0},  //4
                {1,0,1,1,0,1,1,0},  //5
                {1,0,1,1,1,1,1,0},  //6
                {1,1,1,0,0,0,0,0},  //7
                {1,1,1,1,1,1,1,0},  //8
                {1,1,1,1,0,1,1,0}};  //9

void PriNum(int number) //function for show number
{
  int temp;
  temp=number%10;
  SetNum(temp,0);
  delay(1);
  
  temp=(number/10)%10;
  SetNum(temp,1);
  delay(1);
  
  temp=(number/100)%10;
  SetNum(temp,2);
  delay(1);
   
  temp=number/1000;    
  SetNum(temp,3);
  delay(1);
}
                
//function for setting the number
void SetNum(int num,int digitnum) 
{
  PinReset();
  int pin=Numpin;
  int pin2=Digitpin;
  for(int j=0;j<3;j++)
    {
     if(digit[digitnum][j]==1)
        digitalWrite(pin2,HIGH);
      else
        digitalWrite(pin2,LOW);
     pin2++;
    }
        
    for(int i=0;i<8;i++)
    {
      if (Num[num][i]==1)
        digitalWrite(pin,HIGH);
      pin--; 
    } 
}

void PinReset()
{
  for(int i=2;i<13;i++)
    digitalWrite(i,LOW);
  //  delay(1);

}    

void setup () {
  Serial.begin(9600);
  rtc.begin();
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); // Shield I2C pins connect to alt I2C bus on Arduino Due
#endif
  /*if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }*/
  for(int pin=2;pin<13;pin++)  
    pinMode(pin,OUTPUT);
  PinReset();
}

void loop () {
    DateTime now = rtc.now();
    //Serial.print(now.year(), DEC);
    /*Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();*/
    int a = 1234;
    PriNum(a);
   
    delay(3000);
}
