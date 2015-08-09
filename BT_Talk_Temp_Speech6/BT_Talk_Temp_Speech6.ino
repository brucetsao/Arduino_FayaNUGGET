//  ref HC-05與HC-06藍牙模組補充說明（三）：使用Arduino設定AT命令
// ref http://swf.com.tw/?p=712

#include <SoftwareSerial.h>   // 引用程式庫
#define SensorPin A0
char getdata ;  // 儲存接收資料的變數
int nowdata = 0 ;
// 定義連接藍牙模組的序列埠
SoftwareSerial BT(11, 12); // 接收腳, 傳送腳

void setup() {
  
  
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");

  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  BT.begin(9600);
   delay(2000);

}

void loop() {
    if (Serial.available())
    {
      getdata = Serial.read() ;
                  if (getdata == '@')
                  {
                    Serial.println("Get Console Request and Send Sensor Data") ;
                    sendData();
                  }
    }

      if (BT.available())
          {
            getdata = BT.read() ;
            Serial.print("Now get data:(");
            Serial.print(getdata,HEX);
            Serial.print("/");
            Serial.print(getdata);
            Serial.print(")\n");
                     
            if (getdata == '@')
                  {
                    Serial.println("Get Request and Send Sensor Data") ;
                    sendData();
                  }
          }
  }

  void sendData()
  {
          int d1 = 0 ;
          int d2 = 0 ;
          int d3 = 0 ;
          
     //   getdata = "@" && String(analogRead(SensorPin)) &&"/" ; 
      // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
          nowdata = analogRead(SensorPin)-273 ;
          if (nowdata >= 0) 
          {
                d1 = (nowdata % 10 );
                d2 = ((int)(nowdata /10) % 10) ;
                d3 = ((int)(nowdata /100) % 10);
        
                Serial.print(nowdata);     
                Serial.print("/");     
          //     BT.print("@");
                Serial.print(d3);     
                Serial.print("/");     
               BT.write(d3+48);
                Serial.print(d2);     
                Serial.print("/");     
               BT.write(d2+48);
                Serial.print(d1);     
                Serial.print("/");     
               BT.write(d1+48);
            }
          else
              {
                d1 = (abs(nowdata) % 10 ) ;
                d2 = ((int)(abs(nowdata) /10) % 10);
                d3 = ((int)(abs(nowdata) /100) % 10);
        
                Serial.print(nowdata);     
                Serial.print("/");     
          //     BT.print("@");
               BT.write(45);    // send - sign
           //     BT.print("@");
                Serial.print(d3);     
                Serial.print("/");     
               BT.write(d3+48);
                Serial.print(d2);     
                Serial.print("/");     
               BT.write(d2+48);
                Serial.print(d1);     
                Serial.print("/");     
               BT.write(d1+48);
          }
      //   BT.print("/");
        Serial.print("\n");
          delay(5000);    
  }

