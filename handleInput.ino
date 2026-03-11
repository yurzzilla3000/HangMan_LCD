#pragma once

extern Cursor selected;
static unsigned long lastMove = 0;
#define VRX A6
#define VRY A7
#define SW 3
#define SWSCREEN 2

#define UPPER_BOUND 700
#define LOWER_BOUND 300

#define MOVE_DELAY 200

bool handleInput() {


  if (millis() - lastMove < MOVE_DELAY) return 0;

  if(digitalRead(SW) && digitalRead(SWSCREEN)){

    int oldX = selected.x;
    int oldY = selected.y;

    int vrx = analogRead(VRX);
    int vry = analogRead(VRY);

    if (vrx > UPPER_BOUND) selected.x++;
    else if (vrx < LOWER_BOUND) selected.x--;

    if (vry > UPPER_BOUND) selected.y--;
    else if (vry < LOWER_BOUND) selected.y++;

    if (selected.x >= 16) selected.x = 0;
    else if (selected.x < 0) selected.x = 15;

    if (selected.y > 1) selected.y = 1;
    else if (selected.y < 0) selected.y = 0;

    if ((oldX != selected.x) || (oldY != selected.y)) {
      lastMove = millis();
      return 1;
    }
  }
  else if(!digitalRead(SW)){
    Serial.println("Sent letter");
    lastMove = millis();
  }
  else if(!digitalRead(SWSCREEN)){
    Serial.println("Switched screen");
    lastMove = millis();
  }

  return 0;
}