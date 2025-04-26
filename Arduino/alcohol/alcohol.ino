

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2 ,a=7 , b=8 ,c=9 ,d =10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
void setup() {
  pinMode(a, INPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  // set up the LCD's number of columns and rows:
  digitalWrite(b,HIGH);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Alcohol_detector");
}

void loop() {
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
 
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
if (digitalRead(a)){
  digitalWrite(d,HIGH);
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Detected");
}
  else
  {
    digitalWrite(c,HIGH);
   lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Not_Detected");
  }
}
