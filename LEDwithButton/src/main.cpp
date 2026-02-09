#include <Arduino.h>
#include "LED.h"
#include "Button.h"

LED led(LED_BUILTIN, false);
Button button(2);

void setup() {
  Serial.begin(9600);

}

void loop() {
  if ( button.isPressed() ) {
    button.pressed(led);
  };
}
