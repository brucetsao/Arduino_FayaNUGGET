// Faya-Nugget Sample Code 
// Date: 2015/1/28
// Module Name: 4-digit 7-segment Display
// Module Number: #ngt-dp-4d7seg-1A
// Description: Show a number on 4-digit 7-segment display
//              The subroutine in this program can used for future development of this module.  

// Wiring: Module Pin ==> Arduino Pin
//                 S2 ==> D10
//                 S1 ==> D11
//                 EN ==> D12
//                  A ==> D2
//                  B ==> D3
//                  C ==> D4
//                  D ==> D5
//                  E ==> D6
//                  F ==> D7
//                  G ==> D8
//                 DP ==> D9

//define pins
int S2=10;
int S1=11;
int EN=12;
int A=2;
int B=3;
int C=4;
int D=5;
int E=6;
int F=7;
int G=8;
int DP=9;

void setup()
{
  // initialize the digital pin as an output.
  for(int pin=DP;pin<=S2;pin++)
    pinMode(pin,OUTPUT);
  //reset pin function.
  PinReset();
  
}


void loop()
{
    digitalWrite(EN,LOW);  // set S1=0, S2=0, EN=0
    digitalWrite(S1,LOW);  // to light up first digit
    digitalWrite(S2,LOW);
    PrintNumber(4);        // print number 4
    delay(2);
    PinReset();            // all pin reset(low)
    delay(2);
  
    digitalWrite(EN,LOW);  // set S1=0, S2=1, EN=0
    digitalWrite(S1,LOW);  // to light up 2nd digit
    digitalWrite(S2,HIGH);
    PrintNumber(5);        // print number 5
    delay(2);
    PinReset();            // all pin reset(low)
    delay(2);
    
    digitalWrite(EN,LOW);  // set S1=1, S2=0, EN=0
    digitalWrite(S1,HIGH); // to light up 3rd digit
    digitalWrite(S2,LOW);
    PrintNumber(6);        // print number 6
    delay(2);
    PinReset();            // all pin reset(low)
    delay(2);
    
    digitalWrite(EN,LOW);  // set S1=1, S2=1, EN=0
    digitalWrite(S1,HIGH); // to light 4th digit
    digitalWrite(S2,HIGH);
    PrintNumber(7);        // print number 7
    delay(2);
    PinReset();            // all pin reset(low)
    delay(2);

}

void PrintNumber(int num)  // print number subroutine
{
  switch(num)
  {
    case 1:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(DP,LOW);
      break;
    case 2:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,LOW);
      digitalWrite(G,HIGH);
      digitalWrite(DP,LOW);
      break;
    case 3:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,HIGH);
      digitalWrite(DP,LOW);
      break;
    case 4:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      digitalWrite(E,LOW);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
      digitalWrite(DP,LOW);
      break;
    case 5:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,LOW);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
      digitalWrite(DP,LOW);
      break;
    case 6:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
      digitalWrite(DP,LOW);
      break;
    case 7:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(DP,LOW);
      break;  
    case 8:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
      digitalWrite(DP,LOW);
      break;
    case 9:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,LOW);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
      digitalWrite(DP,LOW);
      break;
    case 0:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,HIGH);
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,LOW);
      digitalWrite(DP,LOW);
      break;
  }
}


void PinReset()
{
  for(int pin=DP;pin<=S2;pin++)
    digitalWrite(pin,LOW);

}
