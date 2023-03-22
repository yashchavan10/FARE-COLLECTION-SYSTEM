//include the RFID libs
#include <SPI.h>
#include <MFRC522.h>
 
//include the LCD lib
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
 
 //declear the reset and SDA pins of RFID
#define SS_PIN 10
#define RST_PIN 9


 
// Create MFRC522 instance.
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
//declear what LCD pins u are sending data
LiquidCrystal_I2C lcd(0x27,20,4);
 
 
 
String pass1 = "Welcome";
String acct1 = "";
String pass2 = "Welcome";
String acct2 = "";
String pass3 = "Welcome";
String acct3 = "";
String pass4 = "Welcome";
String acct4 = "";
int balance1 = 1000;
int balance2 = 1000;
int balance3 = 1000;
int balance4 = 1000;
int rate = 1000;
 
 
void setup() 
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  // Initiate  SPI bus  
  SPI.begin();
  // Initiate MFRC522      
  mfrc522.PCD_Init();
  //begin the LCD
  lcd.begin(16, 2);
  //state your actuator pins 
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
   
//display a welcome note
  lcd.setCursor(0, 0);
  lcd.print("B.E.S.T ");
  delay(4000);
  lcd.setCursor(0, 0);
  lcd.print("   BUS TICKET       ");
    lcd.setCursor(0, 1);
  lcd.print(" PAYMENT SYSTEM  ");
  delay(2000);
    lcd.clear();
 
    //mfrc522.PCD_Init(); // Init MFRC522 
    lcd.setCursor(0, 2);
  lcd.print("                                  ");
  lcd.setCursor(0, 3);
  lcd.print("                                  ");
   
}
 
void unregisted(){
   tone(A0, 1000);
delay(500);
noTone(A0);
delay(500);
 
tone(A0, 1000);
delay(500);
noTone(A0);
delay(500);
 
tone(A0, 1000);
delay(500);
noTone(A0);
delay(500);
   
  lcd.setCursor(0, 0);
              lcd.print(" UNREGISTERED              "); 
              delay(2000);
              lcd.setCursor(0, 1);
              lcd.print("KAL AANA");
                             
                  for (int positionCounter = 0; positionCounter < 43; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
         // wait a bit:
    delay(150);
  }
  
  //lcd.clear();
}
 
void loop() { 
  //turn off the actuators
  digitalWrite(A0, LOW);
  analogWrite(A1, 0);
  analogWrite(A2, 0);
   
    lcd.setCursor(0, 0);
  lcd.print("Bus Fare is #");
  lcd.println(rate);
  lcd.println("     ");
  lcd.setCursor(0, 1);
  lcd.print("  Tap To Pay     ");
   
   
    // Look for new cards  
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
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
  Serial.print("Message : ");
  content.toUpperCase();
  //this is where u put the UID of the card that you want to give access
     if (content.substring(1) == "7C c3 2C 6E") {
      analogWrite(A2, 255);
        delay(250);
        analogWrite(A2, 0);
         delay(250);
        analogWrite(A2, 255); 
        static int r;
          if (balance1 >= rate){
              balance1 -= rate;
              lcd.setCursor(0, 0);
              lcd.print("     Hi User     ");
              lcd.setCursor(0, 1);
              lcd.print("___Payment Done___      ");
               }
              else{
              lcd.setCursor(0, 0);
              lcd.print("   Sorry User   ");
              lcd.setCursor(0, 1);
              lcd.print("Insuficient Fund");
              delay(2000);
              lcd.clear();
              int input=500;
              Serial.println();
              Serial.println(input);
              Serial.println();
              Serial.print("Recharged amount: ");
              lcd.setCursor(0, 0);
              lcd.print("Recharged amount:");
              r = input;
              lcd.println(r);
              balance1=balance1+r;
              Serial.println(r);
              Serial.println();
              Serial.print("New Balance: ");
              Serial.println(balance1);
              lcd.setCursor(0, 1);
              lcd.print("Recharged amount:");
              lcd.println(balance1);
 
               }
              delay(4000);
              lcd.setCursor(0, 1);
              lcd.print("_Balance is #"); 
              lcd.println(balance1);
              lcd.println(".      .");
              delay(4000);
             return;
            }
 
             
     if (content.substring(1) == "7C 03 2C 6E") {
      analogWrite(A2, 255);
        delay(250);
        analogWrite(A2, 0);
         delay(250);
        analogWrite(A2, 255); 
        static int r;
          if (balance2 >= rate){
              balance2 -= rate;
              lcd.setCursor(0, 0);
              lcd.print("     Hi User     ");
              lcd.setCursor(0, 1);
              lcd.print("___Payment Done___      ");
               }
              else{
              lcd.setCursor(0, 0);
              lcd.print("   Sorry User   ");
              lcd.setCursor(0, 1);
              lcd.print("Insuficient Fund");
              delay(2000);
              lcd.clear();
              int input=500;
              Serial.println();
              Serial.println(input);
              Serial.println();
              Serial.print("Recharged amount: ");
              lcd.setCursor(0, 0);
              lcd.print("Recharged amount:");
              lcd.println(r);
              r = input;
              balance2=balance2+r;
              Serial.println(r);
              Serial.println();
              Serial.print("New Balance: ");
              Serial.println(balance2);
              lcd.setCursor(0, 1);
              lcd.print("Recharged amount:");
              lcd.println(balance2);
 
               }
              delay(4500);
              lcd.setCursor(0, 1);
              lcd.print("_Balance is #"); 
              lcd.println(balance2);
              lcd.println(".      .");
              delay(4000);
             return;
            }
     if (content.substring(1) == "7C 03 2C 6E") {
      analogWrite(A2, 255);
        delay(250);
        analogWrite(A2, 0);
         delay(250);
        analogWrite(A2, 255); 
        static int r;
          if (balance3 >= rate){
              balance3 -= rate;
              lcd.setCursor(0, 0);
              lcd.print("     Hi User     ");
              lcd.setCursor(0, 1);
              lcd.print("___Payment Done___      ");
               }
              else{
              lcd.setCursor(0, 0);
              lcd.print("   Sorry User   ");
              lcd.setCursor(0, 1);
              lcd.print("Insuficient Fund");
              delay(2000);
              lcd.clear();
              int input=500;
              Serial.println();
              Serial.println(input);
              Serial.println();
              Serial.print("Recharged amount: ");
              lcd.setCursor(0, 0);
              lcd.print("Recharged amount:");
              lcd.println(r);
              r = input;
              balance3=balance3+r;
              Serial.println(r);
              Serial.println();
              Serial.print("New Balance: ");
              Serial.println(balance3);
              lcd.setCursor(0, 1);
              lcd.print("Recharged amount:");
              lcd.println(balance3);
 
               }
              delay(4500);
              lcd.setCursor(0, 1);
              lcd.print("_Balance is #"); 
              lcd.println(balance3);
              lcd.println(".      .");
              delay(4000);
             return;
            }
     if (content.substring(1) == "7C c3 2C 6E") {
      analogWrite(A2, 255);
        delay(250);
        analogWrite(A2, 0);
         delay(250);
        analogWrite(A2, 255); 
        static int r;
          if (balance4 >= rate){
              balance4 -= rate;
              lcd.setCursor(0, 0);
              lcd.print("     Hi User     ");
              lcd.setCursor(0, 1);
              lcd.print("___Payment Done___      ");
               }
              else{
              lcd.setCursor(0, 0);
              lcd.print("   Sorry User   ");
              lcd.setCursor(0, 1);
              lcd.print("Insuficient Fund");
              delay(2000);
              lcd.clear();
              int input=500;
              Serial.println();
              Serial.println(input);
              Serial.println();
              Serial.print("Recharged amount: ");
              lcd.setCursor(0, 0);
              lcd.print("Recharged amount:");
              r = input;
              lcd.println(r);
              balance4=balance4+r;
              Serial.println(r);
              Serial.println();
              Serial.print("New Balance: ");
              Serial.println(balance4);
              lcd.setCursor(0, 1);
              lcd.print("Recharged amount:");
              lcd.println(balance1);
 
               }
              delay(4000);
              lcd.setCursor(0, 1);
              lcd.print("_Balance is #"); 
              lcd.println(balance4);
              lcd.println(".      .");
              delay(4000);
             return;
            }
     
       else{
        lcd.clear();
        analogWrite(A1, 255);
        delay(250);
        analogWrite(A1, 0);
         delay(250);
        analogWrite(A1, 255); 
       unregisted();
         
         
          
       }
       lcd.clear();
             }
