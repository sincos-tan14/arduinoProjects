#include <Arduino.h>
#include "LED.h"
#include "Button.h"

LED led(3, false);
Button button(7);

void setup() {
  Serial.begin(9600);

}

void loop() {
  button.update(led);
}
