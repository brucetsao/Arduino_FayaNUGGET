int val;//定義變數val
int ledpin=13;//定義digital pin 13
void setup()
{
  Serial.begin(9600);//設置傳輸率為9600，這裡要跟軟體設置相一致。當接入特定設備（如：藍牙）時，我們也要跟其他設備的傳輸率達到一致。
  pinMode(ledpin,OUTPUT);//設置digital pin 13 口為輸出接口，Arduino 上我們用到的I/O 口都要進行類似這樣的定義。
}
void loop()
{
  val=Serial.read();//讀取PC 機發送給Arduino 的指令或字元，並將該指令或字元賦給val
  if(val=='R')//判斷接收到的指令或字元是否是「R」。
  {  //如果接收到的是「R」字元
    digitalWrite(ledpin,HIGH);//點亮digital pin 13 LED。
    delay(500);
    digitalWrite(ledpin,LOW);//熄滅digital pin 13 LED
    delay(500);
    Serial.println("Hello World!");//顯示「Hello World！」字元串
  }
}

