
#include <SoftwareSerial.h>   // 引用程式庫
byte senddata=0 ;
byte oldsenddata=0 ;

// 定義連接藍牙模組的序列埠
SoftwareSerial BT(11, 12); // 接收腳, 傳送腳
unsigned char val;  // 儲存接收資料的變數

void setup() {
  Serial.begin(9600);   // 與電腦序列埠連線
  Serial.println("BT is ready!");

  // 設定藍牙模組的連線速率
  // 如果是HC-05，請改成38400
  BT.begin(9600);
}

void loop() {
      senddata = (unsigned char)(analogRead(A0)/4) ;
      if (abs(senddata - oldsenddata) > 5)
        { 
               BT.write(senddata);
               Serial.print("Sensor Data is :(");
               Serial.print(senddata,HEX);
               Serial.print(")\n");
               oldsenddata = senddata ;
        }
     delay(200) ;
     
  // 若收到藍牙模組的資料，則送到「序列埠監控視窗」
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
  }

  // 若收到「序列埠監控視窗」的資料，則送到藍牙模組
  if (Serial.available()) {
    val = Serial.read();
    BT.write(val);
  }
}
