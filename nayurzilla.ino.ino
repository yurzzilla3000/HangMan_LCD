//nqkvo premestig go v drug fail prosto
extern LiquidCrystal_I2C lcd;
extern const char* PlayWord;
extern char letters_guessed[26];
extern bool screen;
extern bool is_full_guessed;
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
    if(guessed) {
      lcd.print(PlayWord[i]);
      is_full_guessed = true;
      }
    else{ 
      lcd.print("_");
      is_full_guessed = false;
    }
  }
}
void guess_letter(char id){
  bool found = false;
  char letter_s = id+97;
    for(int i = 0; i < 31; i++){
      if(PlayWord[i] == letter_s){
        letters_guessed[count_guessed] = letters[id];
        count_guessed += 1;
        Serial.println(letters_guessed);
        found = true;
      }
      if(PlayWord[i] == '\0') break;
      
    }
  letters[id] = " ";
  if(!found) lives--; 
  screen = 0;
  }