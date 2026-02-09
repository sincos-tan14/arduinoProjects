#include "Button.h"
#include "LED.h"

Button::Button(int pin) : _pin(pin) {

}

bool Button::isPressed() {
    return _state;
}

void Button::pressed(LED& led) {
    if (isPressed()) {
        led.setState(!led.getState());
    }
}