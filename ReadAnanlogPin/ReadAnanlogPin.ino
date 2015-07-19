int potpin=0;   //定義模擬接口0
int ledpin=13;  //定義數字接口13
int val=0;      //將定義變量val,並賦初值0
void setup()
{
pinMode(ledpin,OUTPUT);  //定義數字接口為輸出接口
Serial.begin(9600);     //設置波特率為9600
}
void loop()
{
digitalWrite(ledpin,HIGH);//點亮數字接口13 的LED
delay(50);               //延時0.05 秒
digitalWrite(ledpin,LOW);//熄滅數字接口13 的LED
delay(50);               //延時0.05 秒

val=analogRead(potpin);  //讀取模擬接口0 的值，並將其賦給val
Serial.println(val);    //顯示出val 的值
}

