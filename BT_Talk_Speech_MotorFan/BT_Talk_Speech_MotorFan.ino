//  ref HC-05與HC-06藍牙模組補充說明（三）：使用Arduino設定AT命令
// ref http://swf.com.tw/?p=712

#include <SoftwareSerial.h>   // 引用程式庫
#define MotorPin 2
char getdata ;  // 儲存接收資料的變數

// 定義連接藍牙模組的序列埠
SoftwareSerial BT(11, 12); // 接收腳, 傳送腳

void setup() {
  
  pinMode(MotorPin , OUTPUT) ;    // set Button pin as input data
  
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");

  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  BT.begin(9600);
   MotorOn() ;
   delay(2000);
   MotorOff() ;
}

void loop() {
     
    getdata = '@'; 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    getdata = BT.read();
    Serial.print(getdata, HEX);
  }

    if (getdata == 'L')
        {
          MotorOff() ;
        }

    if (getdata == 'H')
        {
          MotorOn() ;
        }

}

void MotorOn()
{
            digitalWrite(MotorPin, HIGH) ;
}

void MotorOff()
{
         digitalWrite(MotorPin, LOW) ;
}


