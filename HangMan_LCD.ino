#include <LiquidCrystal_I2C.h>
#define PIN_NEXT 4
#define PIN_PREV 2
#define PIN_SEL 3

LiquidCrystal_I2C lcd(0x27,16,2);
char letters[26] = "abcdefghijklmnopqrstuvwxyz";
void printWord();
void printLetters(byte selected){
  for(int i = 0;i < 26;i++){
    lcd.print(letters[i]);
    if(i == 15) lcd.setCursor(0,1);
  }
  lcd.setCursor(selected % 16, selected/16);

}
void handleInput(){
    if(digitalRead(PIN_NEXT)){
      if(digitalRead())
    }
}
bool screen = 0;
char curr_position = 0;
const char* words[] = {"hello","cool", "cool", "idk"};
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.blink();
  pinMode(PIN_NEXT, INPUT);
  pinMode(PIN_PREV, INPUT);
  pinMode(PIN_SEL, INPUT);
}
void loop() {
  lcd.clear();
  if(screen){
    printLetters(23);
  }
  else{
    printWord();
  }

  delay(1000);
}
