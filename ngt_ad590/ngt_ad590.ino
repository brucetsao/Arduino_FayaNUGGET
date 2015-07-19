// Faya-Nugget Sample Code 
// Date: 2015/1/27
// Module Name: AD-590 Temperature Sensor
// Module Number: #ngt-ss-ad590-1A
// Description: Show current temperature in serial monitor

// Wiring: Module Pin ==> Arduino Pin
//               Vout ==> A0


void setup()
{
  Serial.begin(9600);          //setup uart baud rate
}

int Celsius=0;
int KelvinScale=0;

void loop()
{
    KelvinScale=analogRead(A0);
    Celsius=KelvinScale-273;             //KelvinScale(K) - 273 = Celsius(C)
    Serial.print("KelvinScale= ");
    Serial.print(KelvinScale);           //show Kelvin Scale vaule in serlial monito
    Serial.print(" K");
    
    Serial.print("    ");
    
    Serial.print("Celsius= ");
    Serial.print(Celsius);               //show Celsius vaule in serial monitor
    Serial.println(" C");
    delay(1000);
}
