#include <LiquidCrystal_I2C.h>
#define PIN_NEXT 4
#define PIN_PREV 2
#define PIN_SEL 3
bool screen = 0;
byte selected = 14;
LiquidCrystal_I2C lcd(0x27,16,2);
char letters[26] = "abcdefghijklmnopqrstuvwxyz";
const char* words[] = {"hello\0","cool\0", "frog\0", "idk\0"};
const char* PlayWord = words[random(0,3)];
char letters_guessed[3] = "oca";
void printWord(){
  lcd.clear();
  for(int i = 0; i < 31; i++){
    if(PlayWord[i] == '\0'){
      break;
    }
    for(int j = 0; j < 26; j++){
      if(letters_guessed[j] == PlayWord[i]) lcd.print(PlayWord[i]);
    }
    if(i == 15) lcd.setCursor(0,1);
  }
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
      lcd.clear();
      selected--;
      
      if(selected < 0) selected = 25;
    }
    else if(digitalRead(PIN_NEXT)){
      lcd.clear();
      selected++;
      if(selected > 25) selected = 0;
    }
    else if(digitalRead(PIN_SEL)){
      //placeholder
    }
}
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
  if(screen){
    handleInput();
    printLetters();
  }
  else{
    printWord();

  }

  delay(1000);
}
