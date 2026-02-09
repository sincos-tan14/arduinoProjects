#include "LED.h"
#include <Arduino.h>

LED::LED(int pin, bool state) : _pin(pin), _state(state) {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, _state ? HIGH : LOW);
}

int LED::getPin() const { return _pin; }
bool LED::getState() const { return _state; }

void LED::setState(bool state) {
    _state = state;
    digitalWrite(_pin, _state ? HIGH : LOW);
}