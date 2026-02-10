#ifndef BUTTON_H
#define BUTTON_H
#include "LED.h"

class Button {
private:
    int _pin;
    bool _state;
    bool _lastState;
    int _lastDebounceTime;

public:
    Button(int i);

    bool isPressed();
    void update(LED& led);
};




#endif
