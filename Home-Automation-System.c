#include<SoftwareSerial.h>
#include<LiquidCrystal.h>
SoftwareSerial mSerial(13,A0);//13=rx <>  bt=tx, A0=tx <> bt=rx
LiquidCrystal lcd(3,4,5,6,7,8);
void setup() 
{
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   HOME");
  lcd.setCursor(0,1);
  lcd.print("AUTOMATION");
  Serial.begin(9600);
  mSerial.begin(9600);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A5,OUTPUT);
  delay(3000);
  lcd.clear();
  
  
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("LOAD 1 - LOAD 2");
 if(mSerial.available())
 {
  char c=mSerial.read();
  Serial.println(c);
  if(c=='1')
  {
   Serial.println("on");
   digitalWrite(A4,HIGH); 
   lcd.setCursor(0,1);
   lcd.print("ON ");
  }
  else if(c=='2')
  {
    Serial.println("off");
    digitalWrite(A4,LOW);
   lcd.setCursor(0,1);
   lcd.print("OFF");    
  }
  else if(c=='3')
  {
   Serial.println("on");
   digitalWrite(A5,HIGH); 
   lcd.setCursor(10,1);
   lcd.print("ON ");
  }
  else if(c=='4')
  {
    Serial.println("off");
    digitalWrite(A5,LOW);
   lcd.setCursor(10,1);
   lcd.print("OFF");    
  }
    else if(c=='5')
  {
   Serial.println("on");
   digitalWrite(A2,HIGH); 
  }
  else if(c=='6')
  {
    Serial.println("off");
    digitalWrite(A2,LOW);
  }
    else if(c=='7')
  {
   Serial.println("on");
   digitalWrite(A3,HIGH); 
  }
  else if(c=='8')
  {
    Serial.println("off");
    digitalWrite(A3,LOW);
  }
 }
}