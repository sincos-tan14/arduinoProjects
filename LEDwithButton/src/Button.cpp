#include "Button.h"
#include "LED.h"
#include <Arduino.h>


Button::Button(int pin) : _pin(pin) {
    pinMode(pin, INPUT_PULLUP);
    _state = HIGH;
    _lastState = HIGH;
    _lastDebounceTime = 0;
}

bool Button::isPressed() {
    bool detectedPress = false;
    int reading = digitalRead(_pin);

    if (reading != _lastState) {
        _lastDebounceTime = millis();
    }

    if ((millis() - _lastDebounceTime) > 50) {
        
        if (reading != _state) {
            _state = reading;

            if (_state == LOW) {
                detectedPress = true;
            }
        }
    }
    _lastState = reading;
    return detectedPress;
} 

void Button::pressed(LED& led) {
    if (isPressed()) {
        led.setState(!led.getState());
    }
}