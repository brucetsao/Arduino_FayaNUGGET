// Faya-Nugget Sample Code
// Date: 2015/1/26
// Module Name: 8-bit Red LED
// Module Number: #ngt-dp-led8r-1A
// Description: Make a shift-left running LED.

// Wiring: Module Pin ==> Arduino Pin
//                 D0 ==> D2
//                 D1 ==> D3
//                 D2 ==> D4
//                 D3 ==> D5
//                 D4 ==> D6
//                 D5 ==> D7
//                 D6 ==> D8
//                 D7 ==> D9


// define pins
#define Led0_Pin 2
#define delaysec 500 
int dirway = 1 ;
int ledpos = 0 ;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
 for(int i=Led0_Pin; i<=Led0_Pin+7; i+=1)
      pinMode(i, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {

        digitalWrite(ledpos+Led0_Pin, HIGH);
        delay(delaysec);
        digitalWrite(ledpos+Led0_Pin, LOW);
        delay(delaysec/3);
      ledpos +=dirway ;
      if (ledpos > 7)
      {
          ledpos = 6 ;
          dirway = -1 ;
      }
      if (ledpos < 0)
      {
          ledpos = 1 ;
          dirway = +1 ;
      }
          
}

