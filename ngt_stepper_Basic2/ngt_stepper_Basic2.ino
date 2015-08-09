
// Author :BruceTsao 2014.3.6

#include <Stepper.h>
#define PinA 4
#define PinB 5
#define PinAP 6
#define PinBP 7

int MaxSpeed = 600 ;   // max speed of motor
int RunSpeed =  200 ;   //  speed of motor
int  AccSpeed = 250   ; // accelerate for motor
int  PulseWidth = 600  ;  // pulse width for each pulse
int  shiftsteps = 100  ;//　move motor back when init to avoid motor collision
int microsteps = 2;
int revolution = 200;
double  ratio = 2;
int Motor1direction = 1 ;
int rundelay = 200 ;


Stepper stepper1(64,PinA, PinB ,PinAP ,PinBP);



int previous = 0;
void setup()
{ 
initall();
initcontroller();
//initmotor();


}
void loop()
{
  stepper1.step(64);
  delay(100);
  // remember the previous value of the sensor
 
}
void initall()
{
  pinMode(PinA,OUTPUT) ;
  pinMode(PinB,OUTPUT) ;
  pinMode(PinAP,OUTPUT) ;
  pinMode(PinBP,OUTPUT) ;

  Serial.begin(9600);
  
}
void initcontroller()
{
// motor1 init
stepper1.setSpeed(RunSpeed);    // set Max Speed of Motor


Serial.println(RunSpeed);
//stepper1.runSpeed();

}


