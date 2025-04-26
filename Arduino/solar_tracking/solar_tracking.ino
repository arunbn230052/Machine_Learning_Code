// include the library code:
#include <LiquidCrystal.h>
int east1=0;
int west1=0;
int north1=0;
int south1=0;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = P2^4, en = P2^3, d4 = P2^5, d5 = P2^6, d6 = P2^7, d7 =P2^2;
Const int a=6 , b=3 ,c=4 ,d =5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int east=A0;
const int west=A1;
const int north=A2;
const int south=A3;
void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  //Analog pin mode
  pinMode(east, INPUT);
  pinMode(west, INPUT);
  pinMode(north, INPUT);
  pinMode(south, INPUT);
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Solar_Tracker");
  
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  east1=analogRead(east);
  west1=analogRead(west);
  north1=analogRead(north);
  south1=analogRead(south);

 
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
if (east1>1017){
  digitalWrite(a,HIGH);
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("east");
}
  if (west1>1017){
  digitalWrite(b,HIGH);
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("west");
}
if (north1>1017){
  digitalWrite(c,HIGH);
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("north");
}
if (south1>1017){
  digitalWrite(d,HIGH);
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("south");
}
}
