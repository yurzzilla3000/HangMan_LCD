//aide ti shte mergvash
#include <LiquidCrystal_I2C.h>
bool screen = 1;
struct Cursor{
  signed char x;
  signed char y;
  };
Cursor selected;
LiquidCrystal_I2C lcd(0x27,16,2);
char letters[26] = "abcdefghijklmnopqrstuvwxyz";
const char* words[] = {"hello","cool","frog","idk"};
void printLetters(){
  lcd.setCursor(0, 0);
  for(int i = 0; i < 26; i++){
    lcd.print(letters[i]);
    if(i == 15) lcd.setCursor(0,1);
  }
  lcd.setCursor(selected.x, selected.y);
}
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);  
  pinMode(A7, OUTPUT);  
  Serial.begin(9600);
  randomSeed(analogRead(A0));
  lcd.init();
  lcd.backlight();
  lcd.cursor();
}

void loop() {
  delay(100);
  if(screen){
    printLetters();
  }
  while(!handleInput());
}