void printLetters(){
  lcd.setCursor(0, 0);
  for(int i = 0; i < 26; i++){
    lcd.print(letters[i]);
    if(i == 15) lcd.setCursor(0,1);
  }
  lcd.setCursor(selected.x, selected.y);
}