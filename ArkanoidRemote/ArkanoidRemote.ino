#include "DigiKeyboard.h"

String movingStatus = "static";

void setup() {}
void loop() {
  bool leftValue = digitalRead(1);
  bool rightValue = digitalRead(2);
  bool fire = digitalRead(0);
  bool pressFire = false;
  bool pressLeft = false;
  bool pressRight = false;
  if(leftValue && movingStatus == "static") {
    pressLeft = true;
    pressRight = false;
  }
  if(movingStatus=="left" && !leftValue) {
    pressRight = false;
    pressLeft = false;
  }
  if(rightValue && movingStatus == "static") {
    pressRight = true;
    pressLeft = false;
  }
  if(movingStatus=="right" && !rightValue) {
    pressRight = false;
    pressLeft = false;
  }

  pressFire = fire;

  int i=1;
  uchar keybuffer[7] = {0,0,0,0,0,0,0};
  if(pressLeft==true) { keybuffer[i]=80; i++; }
  if(pressRight==true) { keybuffer[i]=79; i++; }
  if(pressFire==true) { keybuffer[0] = MOD_CONTROL_LEFT; }
  DigiKeyboard.setReportBuffer(keybuffer);
}

