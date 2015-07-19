// Faya-Nugget Sample Code 
// Date: 2015/1/28
// Module Name: 3V DC Motor
// Module Number: #ngt-mt-dc3v-1A
// Description: Using Arduino code to control DC motor.

// Wiring: Module Pin ==> Arduino Pin
//                SIG ==> D9
//                DIR ==> D8

//define pins
int SIG = 9;
int DIR = 8;

void setup() 
{
  // initialize the digital pin as an output.
  pinMode(SIG,OUTPUT);
  pinMode(DIR,OUTPUT);

  //reset pin function.
  PinRester();
}

void loop()
{
  analogWrite(SIG,100);    //control motor speed, pwm = 0~255
  digitalWrite(DIR,LOW);   //LOW = Clockwise, HIGH = CounterClockwise
}

void PinRester()
{
  digitalWrite(SIG,LOW);
  digitalWrite(DIR,LOW);

}
