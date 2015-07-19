/*
 fayalab leaf sample code for leaf-encoder

 This example shows 3 function of this encoder module
 1.Rotate clockwise
 2.Rotate counter-clockwise
 3.Push button
 
 Also, I demostrate the interrupt usage of fayaduino UNO. 
 
 Auther : welly 
 Date : 2015/03/18
 
 Wiring Guide :
fayaduino pin   2 <-----> leaf pin "PUSH"
fayaduino pin   3 <-----> leaf pin "A"
fayaduino pin   4 <-----> leaf pin "B"
fayaduino pin  5V <-----> leaf pin "VCC"
fayaduino pin GND <-----> leaf pin "GND"
 
 */

//First, define the pins of your connection
//define pin for fayalab leaf-encoder
const int pin_Push = 2;  
const int pin_A = 3;  
const int pin_B = 4;   

//define the modes
unsigned char push_mode;

unsigned char status_A;
unsigned char status_B;
unsigned char status_A_last=0;

int switch_counter;
int currentTime;
int loopTime = 0;

void setup()  {
  //declare a serial debug interface, you can use "Serial Monitor" to find the secret behind the code !
  Serial.begin (9600);
  //for mode switch, we need to use interrupt here!
  //the pin "0" is mapping to UNO digital pin 2, you can find more information here : http://arduino.cc/en/Reference/attachInterrupt
  attachInterrupt(0, stateChange, CHANGE);
  //declare the INPUT devices
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  
  currentTime = millis();
  loopTime = currentTime; 
  push_mode = 0;
  switch_counter = 0;
} 

//trigger by attachInterrupt
void stateChange(){
  //when you push the encoder controller, the status will change to 0
  //it back to 1 when you release the push controller, so we response only when states 1 > 0 > 1
  //(a mode change will trigger stateChange twice)
  if(switch_counter==1){
    Serial.println ("StateChange!!");  
    delay(500);
    if(push_mode==2){
      push_mode = 0;
    }
    else{
      push_mode++;
    }
    Serial.print ("Switch to mode : ");
    Serial.println (push_mode);
    switch_counter = 0;
  }else{
    switch_counter++;
  }
}
void loop()  {
  // get the current elapsed time
  currentTime = millis();
  if(currentTime >= (loopTime + 5)){
    // 5ms since last check of encoder = 200Hz  
    status_A = digitalRead(pin_A);    // Read encoder pins
    status_B = digitalRead(pin_B);  
    //mode 2 : close the LED
    if(push_mode==2){
      Serial.println("mode 2 action!");
    }
    else if(push_mode==1){ //mode 1 : blinking with R/G/B
      Serial.println("mode 1 action!");
    }
    else{
      Serial.println("mode 0 action = show the action of encoder control!");
      // Begin to check the encoder state(CW/Counter CW)
      if((!status_A) && (status_A_last)){
        // A has gone from high to low 
        if(status_B) {
          // B is high so clockwise
          Serial.println("");
          Serial.println("encoder clockwise!");
          Serial.println("");
        }   
        else {
          // B is low so counter-clockwise
           Serial.println("");
           Serial.println("encoder counter-clockwise!");
           Serial.println("");
        }
      }
      // Store value of A for next time
      status_A_last = status_A;
    }
    loopTime = currentTime;  // Updates loopTime
  }                       
}

