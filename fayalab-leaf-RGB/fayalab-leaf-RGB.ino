/*
 fayalab leaf RGB led sample code (Fade)

 This example shows how to fade fayalab LED on pin 9,10 and 11
 using the analogWrite() function.

 Auther : welly 
 Date : 2015/03/18
 
 Wiring Guide :
fayaduino pin   9 <-----> leaf pin  "R"
fayaduino pin  10 <-----> leaf pin  "G"
fayaduino pin  11 <-----> leaf pin  "B"
fayaduino pin GND <-----> leaf pin "GND"
 
 */

int R_pin = 9;           // the pin that the LED is attached to
int G_pin = 10;
int B_pin = 11;
int led;
int state = 0;
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9,10,11 to be an output:
  pinMode(R_pin, OUTPUT);
  pinMode(G_pin, OUTPUT);
  pinMode(B_pin, OUTPUT);
  led = R_pin;
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
  
  if (brightness == 0 && state == 0) {
    led = 10;
    state++;
  } else if (brightness == 0 && state == 1) {
    led = 11;
    state++;
  } else if (brightness == 0 && state == 2) {
    led = 9;
    state = 0;
  }
}  

