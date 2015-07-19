/*
 fayalab leaf sample code for leaf-photointerrupter
 
 This example will show the photointerrupter status in serial monitor.
 Then you can combine this code with other modules that you want to control!
 
 Auther : welly 
 Date : 2015/03/18
 
 Wiring Guide :
fayaduino pin   2 <-----> leaf pin "OUT"
fayaduino pin  5V <-----> leaf pin "VCC"
fayaduino pin GND <-----> leaf pin "GND"
 
 */

//First, define the pin depends on your connection
//define pin
const int pin_photointerrupter= 2;  

// variables will change:
int photointerrupterState = 0;         // variable for reading the pushphotointerrupter status      

void setup()  {
  Serial.begin (9600);
  //declare the INPUT devices
  pinMode(pin_photointerrupter, INPUT);
} 

void loop()  {
  photointerrupterState = digitalRead(pin_photointerrupter);
  Serial.print("OUT status = ");
  Serial.println(photointerrupterState);
  delay(500);
}
