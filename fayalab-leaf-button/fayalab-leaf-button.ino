/*
 fayalab leaf sample code for leaf-button
 
 This example will show the button status in serial monitor.
 Then you can combine this code with other modules that you want to control!
 
 Auther : welly 
 Date : 2015/03/18
 
 Wiring Guide :
fayaduino pin   2 <-----> leaf pin "OUT1"
fayaduino pin   3 <-----> leaf pin "OUT2"
fayaduino pin  5V <-----> leaf pin "VCC"
fayaduino pin GND <-----> leaf pin "GND"
 
 */

//First, define the pin depends on your connection
//define pin for fayalab leaf-encoder
const int pin_Button= 2;  
const int pin_Button2= 3; 

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         

void setup()  {
  Serial.begin (9600);
  //declare the INPUT devices
  pinMode(pin_Button, INPUT);
} 

void loop()  {
  buttonState = digitalRead(pin_Button);
  buttonState2 = digitalRead(pin_Button2);
  Serial.print("OUT1 status = ");
  Serial.println(buttonState);
  Serial.print("---------------");
  Serial.print("OUT2 status = ");
  Serial.println(buttonState2);
}
