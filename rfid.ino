#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN); 

unsigned long startTime;
unsigned long endTime;
unsigned long duration;
byte timerRunning;
 
void setup() 
{ // Initiate a serial communication

  pinMode(8,OUTPUT);
  SPI.begin(); // Initiate SPI bus
  mfrc522.PCD_Init(); // Initiate MFRC522
  Serial.begin(57600);
  Serial.println("");
  Serial.println("SPEED DETECTION SYSTEM ACTIVE...              ");
  Serial.println("");
 
}
void loop() 
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("");
  content.toUpperCase();

  if (content.substring(1) == "13 3B E3 11"  ) 
  {
    
  endTime = millis();
  timerRunning = 0;
  delay(100);

  float pi;
  float di;
  float dis = 30;

  pi = dis/duration;
  di = pi*1000;
  
  Serial.print("SPEED IN cm/s:- ");
  Serial.print(di); 
  Serial.println("cm/s");
  Serial.println(" ");
  Serial.println(" ");
  }
  
  if (content.substring(1) == "D3 53 4D 13"  ) 
  {
    
    
  startTime = millis();
  timerRunning = 1;
    delay(100);
  }
    
  duration = endTime - startTime;
  Serial.println("");
  Serial.print ("TIME TAKEN: ");
  Serial.println("");
  Serial.println (duration);

 if(duration <= 1000)
 {
  digitalWrite(8,HIGH);
  
  Serial.println(" ");
  float pi;
  float di;
  float dis = 30;

  pi = dis/duration;
  di = pi*1000;
  
  Serial.print("SPEED IN cm/s:- ");
  Serial.print(di);  
  Serial.println("cm/s");

  Serial.println(" ");
  Serial.println(" ");
  Serial.println("THIS VEHICAL VIOLATED THE SPEED LIMIT");
  Serial.println(" ");
  Serial.println("OWNER NAME :- SAM WHITE ");
  Serial.println("OWNER ADDRESS :- JAM HOUSE NEAR REVA ");
  Serial.println("VEHICAL COLOUR :- WHITE ");
  Serial.println("VEHICAL MODEL :- TATA MAGNAM ");
  Serial.println("LICENSE NO :- 512345");
  Serial.println("TRUCK CODE :- L -21");
  Serial.println("SPOTTED AT :- JESSICO STEET 10 HEMMER AERA ");
  Serial.println(" ");
  
 
  Serial.println(" ");
  delay(200);
  digitalWrite(8,LOW);
  digitalWrite(8,HIGH);
  delay(200);
  digitalWrite(8,LOW);
  delay(200);
  digitalWrite(8,HIGH);
  delay(200);
  digitalWrite(8,LOW);
  delay(200);
  digitalWrite(8,HIGH);
  delay(200);
  digitalWrite(8,LOW);
  
 }
 
}
