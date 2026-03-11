#include <LiquidCrystal_I2C.h>
#define PIN_NEXT 4
#define PIN_PREV 2
#define PIN_SEL 3



bool screen = 0;
byte lives = 9;
byte selected = 14;
LiquidCrystal_I2C lcd(0x27,16,2);
char letters[26] = "abcdefghijklmnopqrstuvwxyz";
const char* words[] = {"hello\0","cool\0", "frog\0", "idk\0"};
const char* PlayWord = "apple";
char letters_guessed[26] = "                          ";
byte count_guessed = 0;
void printWord(){
  lcd.clear();
  for(int i = 0; i < 31; i++){
    bool guessed = false;
    if(i == 16) lcd.setCursor(0,1);
    if(PlayWord[i] == '\0'){
      break;
    }
    for(int j = 0; j < count_guessed; j++){
      if(letters_guessed[j] == PlayWord[i]){
        guessed = true;
        break;
      }
    }
    if(guessed) lcd.print(PlayWord[i]);
    else lcd.print("_");
    
  }
}

void guess_letter(int id){
  bool found = false;
    for(int i = 0; i < 31; i++){
      if(PlayWord[i] == id){
        letters_guessed[count_guessed] = letters[id];
        count_guessed += 1;
        Serial.println(letters_guessed);
        found = true;
      }
      if(PlayWord[i] == '\0') break;
      
    }
   if(!found) lives--; 
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
  randomSeed(analogRead(A7));
  lcd.init();
  lcd.backlight();
  lcd.blink();
  pinMode(PIN_NEXT, INPUT);
  pinMode(PIN_PREV, INPUT);
  pinMode(PIN_SEL, INPUT);
  Serial.begin(9600);
}
void loop() {
  if(lives){    
    if(screen){
      handleInput();
      printLetters();
    }
    else{
      printWord();
      if(Serial.available() > 0){
        guess_letter((int)Serial.read());
      }
    }
  }else{
    lcd.clear();
    lcd.print("Game Over!");
  }
  delay(50);
}
