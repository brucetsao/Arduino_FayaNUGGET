#include <SoftwareSerial.h>   // 引用程式庫

#define motor1a 7 
#define motor1b 8 
#define motor2a 9 
#define motor2b 10 
//宣告L298N控制用

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
   digitalWrite(motor1a,HIGH );
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

}


void TurnLeft()     //車轉左邊
{
  RightForward() ;
  LeftBackward() ;

}
void Forward()        //車往前
{
  LeftForward() ;
  RightForward() ;

}

void Backward()       //車往後
{
  LeftBackward() ;
  RightBackward() ;

}


void CarStop()      //停車
{
  LeftStop() ;
  RightStop() ;
}






