/*
 fayalab leaf sample code for leaf-hall
 
 This example will show the hall sensor status in serial monitor.
 When you take a magnet near the sensor, the status will change 1 to 0.
 
 Then you can combine this code with other modules that you want to control!
 
 Auther : welly 
 Date : 2015/03/18
 
 Wiring Guide :
fayaduino pin   2 <-----> leaf pin "OUT"
fayaduino pin  5V <-----> leaf pin "VCC"
fayaduino pin GND <-----> leaf pin "GND"
 
 */

//First, define the pin depends on your connection
//define pin for fayalab leaf-encoder
const int pin_HallSensor= 2;  

// variables will change:
int HallSensorState = 0;         // variable for reading the pushHallSensor status       

void setup()  {
  Serial.begin (9600);
  //declare the INPUT devices
  pinMode(pin_HallSensor, INPUT);
} 

void loop()  {
  HallSensorState = digitalRead(pin_HallSensor);
  Serial.print("OUT status = ");
  Serial.println(HallSensorState);
}
