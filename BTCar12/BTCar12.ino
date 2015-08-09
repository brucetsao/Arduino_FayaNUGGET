#include <SoftwareSerial.h>   // 引用程式庫

#define motor1a 4 
#define motor1b 5 
#define motor2a 6 
#define motor2b 7 
//宣告L298N控制用

#define Led1Pin 8     //右前方燈
#define Led2Pin 9   //左前方燈
#define Led3Pin 10    //右後方燈
#define Led4Pin 13    //左後方燈

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
    //設定控制L298N
    
   pinMode(Led1Pin,OUTPUT);
   pinMode(Led2Pin,OUTPUT);
   pinMode(Led3Pin,OUTPUT);
   pinMode(Led4Pin,OUTPUT);
    //設定車燈控制pin
   
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
            Forward() ;     //前進
        if (BTChar == 66 )
            Backward() ;    //後退
        if (BTChar == 82 )
            TurnRight() ;   //右轉
        if (BTChar == 76 )
            TurnLeft() ;    //左轉
        if (BTChar == 83 )
            CarStop() ;     //停車
      }
      delay(150);
 }

 void RightForward()    //轉動右前方車輪
 {
   digitalWrite(motor1a,HIGH);
   digitalWrite(motor1b,LOW);
 }
 void RightBackward()   //轉動右後方車輪
 {
   digitalWrite(motor1a,LOW );
   digitalWrite(motor1b,HIGH);
 }

 void RightStop()       //停右輪
 {  
   digitalWrite(motor1a,LOW );
   digitalWrite(motor1b,LOW);
 }


 void LeftForward()     //轉動左前方車輪
 {
   digitalWrite(motor2a,HIGH);
   digitalWrite(motor2b,LOW);
 }
 void LeftBackward()      //轉動左後方車輪
 {
   digitalWrite(motor2a,LOW );
   digitalWrite(motor2b,HIGH);
 }

 void LeftStop()      //停左輪
 {
   digitalWrite(motor2a,LOW );
   digitalWrite(motor2b,LOW);
 }

void TurnRight()      //車轉右邊
{
  LeftForward() ;
  RightBackward() ;
  RightLight() ;
}


void TurnLeft()     //車轉左邊
{
  RightForward() ;
  LeftBackward() ;
  RightLight() ;
}
void Forward()        //車往前
{
  LeftForward() ;
  RightForward() ;
  FrontLight() ;
}

void Backward()       //車往後
{
  LeftBackward() ;
  RightBackward() ;
  BackLight() ;
}


void CarStop()      //停車
{
  LeftStop() ;
  RightStop() ;
}

void RightFrontLight()      //亮右前方燈
{
    digitalWrite(Led1Pin, HIGH) ;
}

void LeftFrontLight()       //亮左前方燈
{
    digitalWrite(Led2Pin, HIGH) ;
}

void RightBackLight()      //亮右後方燈
{
    digitalWrite(Led3Pin, HIGH) ;
}

void LeftBackLight()      //亮左後方燈
{
    digitalWrite(Led4Pin, HIGH) ;
}

void RightFrontLightOff()         //熄滅右前方燈
{
    digitalWrite(Led1Pin, LOW) ;
}

void LeftFrontLightOff()      //熄滅左前方燈
{
    digitalWrite(Led2Pin, LOW) ;
}

void RightBackLightOff()      //熄滅右後方燈
{
    digitalWrite(Led3Pin, LOW) ;
}

void LeftBackLightOff()       //熄滅左後方燈
{
    digitalWrite(Led4Pin, LOW) ;
}


void FrontLight()       //開前方燈(大燈)
{
  RightFrontLight() ;
  LeftFrontLight() ;
  
}

void BackLight()        //開倒車燈
{
  RightBackLight() ;
  LeftBackLight() ;
  
}

void FrontLightOff()       //關前方燈(大燈)
{
  RightFrontLightOff() ;
  LeftFrontLightOff() ;
  
}

void BackLightOff()       //關倒車燈
{
  RightBackLightOff() ;
  LeftBackLightOff() ;
  
}

void RightLight()       //開右轉燈
{
  RightFrontLight() ;
  RightBackLight() ;
  
}

void LeftLight()      //開左轉燈
{
  LeftFrontLight() ;
  LeftBackLight() ;
  
}
void RightLightOff()      //關右轉燈
{
  RightFrontLightOff() ;
  RightBackLightOff() ;
  
}

void LeftLightOff()     //關左轉燈
{
  LeftFrontLightOff() ;
  LeftBackLightOff() ;
  
}



void AllLightOff()        //關閉所有車燈
{
  RightFrontLightOff() ;
  RightBackLightOff() ;
  LeftFrontLightOff() ;
  LeftBackLightOff() ;
  
}


