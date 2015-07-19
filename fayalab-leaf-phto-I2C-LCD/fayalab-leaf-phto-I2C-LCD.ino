#include <Servo.h>//library
#include <Wire.h> //library
#include <LiquidCrystal_I2C.h>//library

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Servo myServo;
const int pin_Servo=0; //servo pin0 control
const int pin_Photointerrupter = 13;  //photointerrupter pin13 control

//the status of photointerrupter sensor
int StatusPI = 0;
int pre_StatusPI =1;
int counter = 0;
int in_out = 0;// store in/out status
int angle = 0;// the angle for servo

boolean rotate_direction = 0;// the rotation direction of servo

void setup(){     
  myServo.attach(pin_Servo); //setup servo
  pinMode(pin_Photointerrupter,INPUT);
  // initialize the lcd 
  lcd.init();                     
  lcd.backlight();
  // Print a message to the LCD.
  lcd.print("Triggered times :");
  lcd.setCursor(8, 1); //set Starting position
  lcd.print("times"); //print counter
}

void loop(){
  if(angle >= 180){  //Change the direction when angle = 180
    rotate_direction = 1;
  }else if(angle <=0){
    rotate_direction = 0;
  }
  if(rotate_direction)
    angle--;
  else
    angle++;
  myServo.write(angle);
  //determine how many times the servo arms wave.
  StatusPI = digitalRead(pin_Photointerrupter);
  if(StatusPI != pre_StatusPI){
    in_out++;
    if(in_out==2){
      //Serial.println(in_out);
      counter++;
      in_out = 0;
    }
  }
  //Print the number with i2c
  //====================================//
  lcd.setCursor(0, 1); //set Starting position
  lcd.print(counter); //print counter
  //====================================//
  pre_StatusPI = StatusPI;
}
