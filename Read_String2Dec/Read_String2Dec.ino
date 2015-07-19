int val;//定義變數val
int ledpin=13;//定義Led pin13
int incomingByte = 0;   // for incoming serial data

void setup()
{
Serial.begin(9600); 
//設置串列傳輸速率為9600 bps，這裏要跟Sketch IDE整合開發軟體設置一致。當使用特定設備（如：藍牙）時，我們也要跟其他設備的串列傳輸速率達到一致。
pinMode(ledpin,OUTPUT);
//設置數位接腳13為輸出介面，Arduino 上我們用到的I/O 口都要進行類似這樣的定義。
}
void loop()
{
  
          if (Serial.available() > 0) {
                // read the incoming byte:
                while (Serial.available() > 0)
                  {
                      incomingByte = Serial.read();
                     Serial.println(incomingByte,DEC);
                         //DEC　for arduino display data in Decimal format
                  }
            }

}



