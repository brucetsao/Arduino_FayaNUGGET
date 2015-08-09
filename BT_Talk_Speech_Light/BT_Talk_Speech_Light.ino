#include <SoftwareSerial.h>   // 引用程式庫
#define LedPinD0 2
#define LedPinD1 3
#define LedPinD2 4
#define LedPinD3 5
#define LedPinD4 6
#define LedPinD5 7
#define LedPinD6 8
#define LedPinD7 9
#define ascStart 48
char getdata ;  // 儲存接收資料的變數

// 定義連接藍牙模組的序列埠
SoftwareSerial BT(11, 12); // 接收腳, 傳送腳

void setup() {
  
  pinMode(LedPinD0 , OUTPUT) ;    // set Button pin as input data
  pinMode(LedPinD1 , OUTPUT) ;    // set Button pin as input data
  pinMode(LedPinD2 , OUTPUT) ;    // set Button pin as input data
  pinMode(LedPinD3 , OUTPUT) ;    // set Button pin as input data
  pinMode(LedPinD4 , OUTPUT) ;    // set Button pin as input data
  pinMode(LedPinD5 , OUTPUT) ;    // set Button pin as input data
  pinMode(LedPinD6 , OUTPUT) ;    // set Button pin as input data
  pinMode(LedPinD7 , OUTPUT) ;    // set Button pin as input data
  
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");

  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  BT.begin(9600);
   allLightOn() ;
   delay(1000);
   allLightOff() ;
}

void loop() {
     
    getdata = '@'; 
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    getdata = BT.read();
    Serial.print(getdata, HEX);
  }

    if (getdata == '0')
        {
          allLightOff() ;
        }

    if (getdata == '9')
        {
          allLightOn() ;
        }

    if (getdata == '1')
        {
          digitalWrite(LedPinD0, HIGH) ;
        }

    if (getdata == '2')
        {
          digitalWrite(LedPinD1, HIGH) ;
        }

    if (getdata == '3')
        {
          digitalWrite(LedPinD2, HIGH) ;
        }

    if (getdata == '4')
        {
          digitalWrite(LedPinD3, HIGH) ;
        }

    if (getdata == '5')
        {
          digitalWrite(LedPinD4, HIGH) ;
        }

    if (getdata == '6')
        {
          digitalWrite(LedPinD5, HIGH) ;
        }

    if (getdata == '7')
        {
          digitalWrite(LedPinD6, HIGH) ;
        }

    if (getdata == '8')
        {
          digitalWrite(LedPinD7, HIGH) ;
        }

    if (getdata == 'T')
        {
          delay(1000);
        }

}

void allLightOn()
{
            digitalWrite(LedPinD0, HIGH) ;
          digitalWrite(LedPinD1, HIGH) ;
          digitalWrite(LedPinD2, HIGH) ;
          digitalWrite(LedPinD3, HIGH) ;
          digitalWrite(LedPinD4, HIGH) ;
          digitalWrite(LedPinD5, HIGH) ;
          digitalWrite(LedPinD6, HIGH) ;
          digitalWrite(LedPinD7, HIGH) ;
}

void allLightOff()
{
         digitalWrite(LedPinD0, LOW) ;
          digitalWrite(LedPinD1, LOW) ;
          digitalWrite(LedPinD2, LOW) ;
          digitalWrite(LedPinD3, LOW) ;
          digitalWrite(LedPinD4, LOW) ;
          digitalWrite(LedPinD5, LOW) ;
          digitalWrite(LedPinD6, LOW) ;
          digitalWrite(LedPinD7, LOW) ;
}


