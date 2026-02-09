#include "BlinkUtils.h"
#include <Arduino.h>

void buttonPressed(bool& state, int LED) {
    state = state == true ? false : true;
    if (state) digitalWrite(LED, HIGH);
    else digitalWrite(LED, LOW);
}