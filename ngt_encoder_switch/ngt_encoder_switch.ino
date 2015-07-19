// Faya-Nugget Sample Code 
// Date: 2015/1/27
// Module Name: Encoder Switch
// Module Number: #ngt-di-encdrsw-1A
// Description:Use encoder switch to count the number and show in serail monitor
//                 When rotate Clockwise => Number +1;
//                 When rotate Counterclockwise => Number -1;
//                 When button pressed, ==> Number reset to 0;


// Wiring: Module Pin ==> Arduino Pin
//                 PB ==> D2
//                  A ==> D3
//                  B ==> D4

//define pins
#define EnCoder_PB 2
#define EnCoder_A 3
#define EnCoder_B 4

void setup() 
{ 
  //setup uart baud rate.
  Serial.begin (9600);
  
  pinMode (EnCoder_PB,INPUT);
  pinMode (EnCoder_A,INPUT);
  pinMode (EnCoder_B,INPUT);
   
} 
 
 
int Count=0;
int encoderLast = LOW;
int temp = LOW;

void loop() 
{ 
   temp = digitalRead(EnCoder_A);

   if ((encoderLast == LOW) && (temp == HIGH)) 
   {
     if (digitalRead(EnCoder_B) == LOW)   //Count up
       Count++;
     else                                 //Count down
       Count--;
       
     Serial.print("Count= ");
     Serial.println(Count);
   }
   
   if (digitalRead(EnCoder_PB)==HIGH)    ////Count reset
   { 
     Count=0;
     Serial.print("Count= ");
     Serial.println(Count);
     delay(500);
   }
   encoderLast = temp;
} 
