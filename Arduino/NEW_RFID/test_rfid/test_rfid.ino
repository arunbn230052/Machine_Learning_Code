#include<Wire.h>
#include<LiquidCrystal.h>
#include<SoftwareSerial.h>

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
SoftwareSerial SIM900(9, 10);
int motor_for=7;
int motor_back=8;
String a;
int buzzer=13;
void setup() {
  pinMode(motor_for,OUTPUT);
  pinMode(motor_back,OUTPUT);
  pinMode(buzzer,OUTPUT);

  Serial.begin(9600);
  SIM900.begin(9600);
  delay(100);
  Serial.println("GSM RFID BASED SECURITY SYSTEM");
  delay(1000);
  Serial.println("INITIALIZING GSM MODEM....");
  delay(1000);
  Serial.println("Enter the user ID :");
  lcd.begin(0,1);
lcd.print("Security_System");
  // put your setup code here, to run once:

}

void loop() {
Serial.println("Enter data:");
  while (Serial.available() == 0) {}     //wait for data available
  String teststr = Serial.readString();  //read until timeout
  teststr.trim();                        // remove any \r \n whitespace at the end of the String
  if (teststr == "a") {
    sms();
    Serial.println("THE user is valid");
     lcd.begin(1,1);
lcd.print("USER1 LOGGED IN");
delay(1000);
digitalWrite(motor_for,HIGH);   //door_open
delay(1000);
digitalWrite(motor_for,LOW);
digitalWrite(motor_back,HIGH);  //door_closed
delay(1000);
digitalWrite(motor_back,LOW);

  } 
   if (teststr == "b") {
    sms1();
    Serial.println("THE user is valid");
     lcd.begin(1,1);
lcd.print("USER2 LOGGED IN");
delay(1000);
digitalWrite(motor_for,HIGH);  //door_open
delay(1000);
digitalWrite(motor_for,LOW);
digitalWrite(motor_back,HIGH);  //door_closed
delay(1000);
digitalWrite(motor_back,LOW);

  }
  
  else {
       err_sms();
    Serial.println("THE user is not valid");
 lcd.begin(1,1);
lcd.print("INVALID USER");
delay(1000);
digitalWrite(buzzer,HIGH);
delay(1000);
digitalWrite(buzzer,LOW);
  }
  // put your main code here, to run repeatedly:

}
void sms()

{
SIM900.print("AT+CMGF=1\r"); 
SIM900.println("AT + CMGS = \"+977972645872\"");// recipient's mobile number
Serial.println("AT + CMGS = \"+977972645872\"");// recipient's mobile number
SIM900.println("The user1"); // message to send
Serial.println("THE USER1 IS LOGGED IN");
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
SIM900.println();
}
void sms1()

{
SIM900.print("AT+CMGF=1\r"); 
SIM900.println("AT + CMGS = \"+977972645872\"");// recipient's mobile number
Serial.println("AT + CMGS = \"+977972645872\"");// recipient's mobile number
SIM900.println("The user1"); // message to send
Serial.println("THE USER2 IS LOGGED IN");
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
SIM900.println();
}

void err_sms()

{
SIM900.print("AT+CMGF=1\r"); 
SIM900.println("AT + CMGS = \"+977972645872\"");// recipient's mobile number
Serial.println("AT + CMGS = \"+977972645872\"");// recipient's mobile number
SIM900.println("The user1"); // message to send
Serial.println("UN_IDENTIFIED USER IS TRYING TO LOG IN");
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
Serial.println((char)26);
SIM900.println();
}
