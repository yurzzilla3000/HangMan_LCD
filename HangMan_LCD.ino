//aide az mergnah
#include <LiquidCrystal_I2C.h>
bool is_full_guessed = false;
bool screen = 1;
struct Cursor{
  signed char x;
  signed char y;
  };
Cursor selected;
byte lives = 9;
LiquidCrystal_I2C lcd(0x27,16,2);
char letters[26] = "abcdefghijklmnopqrstuvwxyz";
const char* words[] = {"hello\0","cool\0", "frog\0", "idk\0"};
const char* PlayWord = "apple\0";
char letters_guessed[26] = "                          ";
byte length;
byte count_guessed = 0;
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A6, OUTPUT);  
  pinMode(A7, OUTPUT);  
  Serial.begin(9600);
  randomSeed(analogRead(0));
  lcd.init();
  lcd.backlight();
  lcd.cursor();
}

void loop() {
  if(lives){    
    if(screen){
      printLetters();
    }
    else{
      printWord();
      if(is_full_guessed == true){
        lcd.clear();
        lcd.print("You Win!");
        delay(1000);
      }
    }
  }else{
    lcd.clear();
    lcd.print("Game Over!");
  }
  while(!handleInput());
  delay(50);
}
