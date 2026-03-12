//nqkvo premestig go v drug fail prosto
extern LiquidCrystal_I2C lcd;
extern const char* PlayWord;
extern char letters_guessed[26];
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