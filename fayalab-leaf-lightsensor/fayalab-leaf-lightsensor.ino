/*
 fayalab leaf sample code for leaf-Light sensor
 
 This example will show the light sensor value in serial monitor.
 
 Auther : welly 
 Date : 2015/03/18
 
 Wiring Guide :
fayaduino pin  A0 <-----> leaf pin "OUT"
fayaduino pin  5V <-----> leaf pin "VCC"
fayaduino pin GND <-----> leaf pin "GND"
 
 */

// First, define the pin depends on your connection
// define pin for fayalab leaf-Light and leaf-Buzzer
int pin_Lightsensor = A0;   
   
// variable to store the value coming from the sensor
int sensorValue = 0;  

void setup() {
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(pin_Lightsensor);
  Serial.print("Sensor value = ");  
  Serial.println(sensorValue);  
  delay(1000);
}
