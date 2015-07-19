int potpin=0;   //定義類比介面0
int ledpin=13;  //定義數位介面13
int val=0;      //將定義變數val,並賦初值0
int v;
void setup()
{
  pinMode(ledpin,OUTPUT);  //定義數位介面為輸出介面
  Serial.begin(9600);     //設置串列傳輸速率為9600
}
void loop()
{
  digitalWrite(ledpin,HIGH);//點亮數位介面13 的LED
  delay(50);               //延時0.05 秒
  digitalWrite(ledpin,LOW);//熄滅數位介面13 的LED
  delay(50);               //延時0.05 秒
  
  val=analogRead(potpin);  //讀取類比介面0 的值，並將其賦給val
  v=map(val,0,1023,0,500);
//函數說明map(x,Amin,Amax,Bmin,Bmax)
//  返回值 long型
//把0-1023區間的數映射到0-500的數，其實可以理解成比例關係。

  Serial.println((float)v/100.00);    //顯示出v 的值
}

