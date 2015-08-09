#include <SoftwareSerial.h>   // 引用程式庫

#define motor1a 4 
#define motor1b 5 
#define motor2a 6 
#define motor2b 7 

#define Led1Pin 8 
#define Led2Pin 9 
#define Led3Pin 10 
#define Led4Pin 13 

int Motor1direction = 1 ;
char BTChar ;
// 定義連接藍牙模組的序列埠
SoftwareSerial BT(11, 12); // 接收腳, 傳送腳



void initall()
{
  
 // init motor pin as output 
   pinMode(motor1a,OUTPUT);
   pinMode(motor1b,OUTPUT);
   pinMode(motor2a,OUTPUT);
   pinMode(motor2b,OUTPUT);

   pinMode(Led1Pin,OUTPUT);
   pinMode(Led2Pin,OUTPUT);
   pinMode(Led3Pin,OUTPUT);
   pinMode(Led4Pin,OUTPUT);

   
}
 void setup()
 {
  initall();
   //init serial for debug
Serial.begin(9600);
Serial.println("Program Start Here ");

  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  BT.begin(9600);

 
 }
  
 void loop()
 {
  if (BT.available() >0)
      {
        BTChar = BT.read() ;
        if (BTChar == 70 )
            Forward() ;
        if (BTChar == 66 )
            Backward() ;
        if (BTChar == 82 )
            TurnRight() ;
        if (BTChar == 76 )
            TurnLeft() ;
        if (BTChar == 83 )
            CarStop() ;
      }
      delay(150);
 }

 void RightForward()
 {
   digitalWrite(motor1a,HIGH);
   digitalWrite(motor1b,LOW);
 }
 void RightBackward()
 {
   digitalWrite(motor1a,LOW );
   digitalWrite(motor1b,HIGH);
 }

 void RightStop()
 {
   digitalWrite(motor1a,LOW );
   digitalWrite(motor1b,LOW);
 }


 void LeftForward()
 {
   digitalWrite(motor2a,HIGH);
   digitalWrite(motor2b,LOW);
 }
 void LeftBackward()
 {
   digitalWrite(motor2a,LOW );
   digitalWrite(motor2b,HIGH);
 }

 void LeftStop()
 {
   digitalWrite(motor2a,LOW );
   digitalWrite(motor2b,LOW);
 }

void TurnRight()
{
  LeftForward() ;
  RightBackward() ;
}


void TurnLeft()
{
  RightForward() ;
  LeftBackward() ;
}
void Forward()
{
  LeftForward() ;
  RightForward() ;
}

void Backward()
{
  LeftBackward() ;
  RightBackward() ;
}


void CarStop()
{
  LeftStop() ;
  RightStop() ;
}

void RightFrontLight()
{
    digitalWrite(Led1Pin, HIGH) ;
}

void LeftFrontLight()
{
    digitalWrite(Led2Pin, HIGH) ;
}

void RightBackLight()
{
    digitalWrite(Led3Pin, HIGH) ;
}

void LeftBackLight()
{
    digitalWrite(Led4Pin, HIGH) ;
}

void FrontLight()
{
  RightFrontLight() ;
  LeftFrontLight() ;
  
}

void BackLight()
{
  RightBackLight() ;
  LeftBackLight() ;
  
}

void RightLight()
{
  RightFrontLight() ;
  RightBackLight() ;
  
}

void LeftLight()
{
  LeftFrontLight() ;
  LeftBackLight() ;
  
}

