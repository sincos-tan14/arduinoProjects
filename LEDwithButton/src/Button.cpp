#include "Button.h"
#include "LED.h"
#include <Arduino.h>


Button::Button(int pin) : _pin(pin) {
    pinMode(pin, INPUT_PULLUP);
    _state = HIGH;
    _lastState = HIGH;
    _lastDebounceTime = 0;
}

Button::Button(int pin, Button& twinButton) : _pin(pin) {
    pinMode(pin, INPUT_PULLUP);
    _state = HIGH;
    _lastState = HIGH;
    _lastDebounceTime = 0;
    this->addTwinButton(twinButton);
}

void Button::begin() {
    pinMode(_pin, INPUT_PULLUP);
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

bool Button::isHeldDown() const {
    return digitalRead(_pin) == LOW;
}

void Button::update(LED& led) {
    
    if (isPressed()) {
        if (_twinButton == nullptr) {
            led.setState(!led.getState());
        } 
        else if (_twinButton->isHeldDown()) {
            led.setState(!led.getState());
        }
    }
}

bool Button::addTwinButton(Button& button) {
    if (_twinButton != nullptr) return false;
    _twinButton = &button;
    button.addTwinButton(*this);
    return true;
}

Button* Button::getTwinButton() const {
    return _twinButton;
}

