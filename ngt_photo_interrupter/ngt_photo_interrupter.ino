// Faya-Nugget Sample Code 
// Date: 2015/1/26
// Module Name: Photo Interrupter
// Module Number: #ngt-ss-photointr-1A
// Description: Detect the status of Photo Interrupter and show the results in serial monitor

// Wiring: Module Pin ==> Arduino Pin
//               Out  ==> A0
//               Out_ ==> A1

void setup()
{
  Serial.begin(9600);            //setup uart baud rate
}

void loop()
{
  int Out;
  int Out_;
  
  Out=analogRead(A0);
  Out_=analogRead(A1);
  
  Serial.print("Out= ");        
  Serial.println(Out);           //Show photo interrupter module out pin value

  Serial.print("Out_= ");        
  Serial.println(Out_);          //Show photo interrupter module out_ pin value
  
  if(Out==1023)                 //Out analog value == 1023 is on      
    Serial.println("Photo Interrupter Status: Blocking");
    else
    Serial.println("Photo Interrupter Status: Non-Blocking");
  
  Serial.println("---------------------------");
  delay(1000);
   
}
