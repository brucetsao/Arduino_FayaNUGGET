// Faya-Nugget Sample Code 
// Date: 2015/1/28
// Module Name: 5.625deg Step Motor
// Module Number: #ngt-mt-step5.625d-1A
// Description: Use arduino code to control the speed and direction of step motor.  

// Wiring: Module Pin ==> Arduino Pin
//                  A ==> D11
//                  B ==> D10
//                 /A ==> D9
//                 /B==> D8

//define pins
int motorPin_A  = 11;
int motorPin_B = 10;
int motorPin_AP  = 9;
int motorPin_BP = 8;

int delayTime = 300; // set delay time (unit: m sec)
                     // change delay time to control motor speed

void setup() 
{
  // initialize the digital pin as an output.
  pinMode(motorPin_A,  OUTPUT);
  pinMode(motorPin_B,  OUTPUT);
  pinMode(motorPin_AP,  OUTPUT);
  pinMode(motorPin_BP, OUTPUT);
  //reset pin function.
  PinRester();
}

void loop()
{
 CounterClockwise();
}

void Clockwise()  //Clockwise function
{
  digitalWrite(motorPin_A, HIGH);
  digitalWrite(motorPin_B, HIGH);
  digitalWrite(motorPin_AP, LOW);
  digitalWrite(motorPin_BP, LOW); 
  delay(delayTime);
  
  digitalWrite(motorPin_A, LOW);
  digitalWrite(motorPin_B,HIGH);
  digitalWrite(motorPin_AP, HIGH);
  digitalWrite(motorPin_BP,LOW); 
  delay(delayTime);
  
  digitalWrite(motorPin_A, LOW);
  digitalWrite(motorPin_B,LOW);
  digitalWrite(motorPin_AP, HIGH);
  digitalWrite(motorPin_BP,HIGH);
  delay(delayTime);
  
  digitalWrite(motorPin_A, HIGH);
  digitalWrite(motorPin_B,LOW);
  digitalWrite(motorPin_AP, LOW);
  digitalWrite(motorPin_BP,HIGH);
  delay(delayTime);
}

void CounterClockwise()    //AntiClockwise function
{
  digitalWrite(motorPin_A, LOW);
  digitalWrite(motorPin_B,LOW);
  digitalWrite(motorPin_AP, HIGH);
  digitalWrite(motorPin_BP,HIGH);
  delay(delayTime);
  
  digitalWrite(motorPin_A, LOW);
  digitalWrite(motorPin_B,HIGH);
  digitalWrite(motorPin_AP, HIGH);
  digitalWrite(motorPin_BP,LOW); 
  delay(delayTime);
  
  digitalWrite(motorPin_A, HIGH);
  digitalWrite(motorPin_B,HIGH);
  digitalWrite(motorPin_AP, LOW);
  digitalWrite(motorPin_BP,LOW); 
  delay(delayTime);
  
  digitalWrite(motorPin_A, HIGH);
  digitalWrite(motorPin_B,LOW);
  digitalWrite(motorPin_AP, LOW);
  digitalWrite(motorPin_BP,HIGH);
  delay(delayTime);
}

void PinRester()
{
  digitalWrite(motorPin_A, LOW);
  digitalWrite(motorPin_B,LOW);
  digitalWrite(motorPin_AP, LOW);
  digitalWrite(motorPin_BP,LOW); 
}

