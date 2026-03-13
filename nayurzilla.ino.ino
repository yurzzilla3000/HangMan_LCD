//nqkvo premestig go v drug fail prosto
extern LiquidCrystal_I2C lcd;
extern const char* PlayWord;
extern char letters_guessed[26];
extern bool screen;
extern bool is_full_guessed;
void printWord(){
  lcd.clear();
  lcd.noCursor();

  is_full_guessed = true;

  for(int i = 0; i < 31; i++){
    bool guessed = false;

    if(i == 16) lcd.setCursor(0,1);
    if(PlayWord[i] == '\0') break;

    for(int j = 0; j < count_guessed; j++){
      if(letters_guessed[j] == PlayWord[i]){
        guessed = true;
        break;
      }
    }

    if(guessed){
      lcd.print(PlayWord[i]);
    }
    else{
      lcd.print("_");
      is_full_guessed = false;
    }
  }
}
void guess_letter(char id){
  bool found = false;
  char letter_s = id + 97;

  for(int i = 0; i < 31; i++){
    if(PlayWord[i] == '\0') break;

    if(PlayWord[i] == letter_s){
      found = true;
    }
  }

  if(found){
    letters_guessed[count_guessed] = letter_s;
    count_guessed++;
  } 
  else{
    lives--;
  }

  letters[id] = " ";
  screen = 0;
}