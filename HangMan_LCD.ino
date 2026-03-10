#include <LiquidCrystal_I2C.h>
#define PIN_NEXT 4
#define PIN_PREV 2
#define PIN_SEL 3
bool screen = 0;
byte selected = 0;
LiquidCrystal_I2C lcd(0x27,16,2);
char letters[26] = "abcdefghijklmnopqrstuvwxyz";
void printLetters(){
const char* words[] = {"hello\0","cool\0", "frog\0", "idk\0"};
// char PlayWord[32] = words[random(0,3)];
void printWord(){
  // for(int i = 0; i < 31; i++){
  //   if(PlayWord[i] == "\0"){
  //     break;
  //   }
  //   lcd.print(PlayWord[i]);
  //   if(i == 15) lcd.setCursor(0,1);
  // }
}
void printLetters(){
  for(int i = 0;i < 26;i++){
    lcd.print(letters[i]);
    if(i == 15) lcd.setCursor(0,1);
  }
  lcd.setCursor(selected % 16, selected/16);
}
void handleInput(){
    if(digitalRead(PIN_NEXT)){
      if(digitalRead(PIN_PREV)){
        screen = !screen;
      }
      else{
        selected++;
        selected %= 26;;
      }
    }
    else if(digitalRead(PIN_PREV)){
      selected--;
      if(selected < 0) selected = 25;
    }
    else if(digitalRead(PIN_SEL)){
      //placeholder
    }
}
const char* words[] = {"hello","cool", "cool", "idk"};
void setup() {
  randomSeed(analogRead(A0));
  lcd.init();
  lcd.backlight();
  lcd.blink();
  pinMode(PIN_NEXT, INPUT);
  pinMode(PIN_PREV, INPUT);
  pinMode(PIN_SEL, INPUT);
}
void loop() {
  lcd.clear();
  handleInput();
  if(screen){
    printLetters();
  }
  else{
    //printWord();
  }

  delay(1000);
}
