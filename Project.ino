#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int Contrast=50;
const int red_pin = 9;
const int green_pin = 8;
const int yellow_pin = 7;
const int hygrometer = A0;
int value;

void setup() {
  Serial.begin(9600);
  
  lcd.begin(16, 2);
  analogWrite(6,Contrast);
  lcd.setCursor(0,0);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(yellow_pin, OUTPUT);
  lcd.print("Salutare (^_^)");
  lcd.setCursor(2, 1);
  lcd.print("quick check->");
  delay(3000);
}

void loop() {
  value = analogRead(hygrometer);
  value = constrain(value,400,1023);
  value = map(value,400,1023,100,0);
  lcd.clear();
  lcd.print("Umiditatea este:");
  lcd.setCursor(2, 1);
  char s[4];
  itoa(value, s, 10);
  lcd.print(s);
  lcd.setCursor(6, 1);
  lcd.print("->");
  if (value < 110) {
    digitalWrite(yellow_pin, HIGH);
    lcd.setCursor(9, 1);
    lcd.print("MICA");
  } else {
    digitalWrite(yellow_pin, LOW);
  }
  if ((value > 110) && (value < 160)) {
    digitalWrite(green_pin, HIGH);
    lcd.setCursor(9, 1);
    lcd.print("OK");
  } else {
    digitalWrite(green_pin, LOW);
  }
  if (value > 160) {
    digitalWrite(red_pin, HIGH);
    lcd.setCursor(9, 1);
    lcd.print("MARE");
  } else {
    digitalWrite(red_pin, LOW);
  }
  delay(2000);
}
