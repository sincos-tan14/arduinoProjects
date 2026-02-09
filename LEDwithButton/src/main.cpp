#include <Arduino.h>
#include "BlinkUtils.h"
#include "Button.h"


// put function declarations here:
bool LEDstate;
Button button(2);

void setup() {
  // put your setup code here, to run once:
  int LEDstate = false;
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}

// put function definitions here:
