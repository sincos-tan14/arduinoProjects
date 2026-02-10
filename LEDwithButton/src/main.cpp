#include <Arduino.h>
#include "LED.h"
#include "Button.h"

LED led(3, false);
Button button1(7);
Button button2(8, button1);



void setup() {
  Serial.begin(9600);

}

void loop() {
  button1.update(led);
}
