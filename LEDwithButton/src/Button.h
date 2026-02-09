#ifndef BUTTON_H
#define BUTTON_H
#include "LED.h"

class Button {
private:
    int _pin;
    bool _state;

public:
    Button(int i);

    bool isPressed();
    void pressed(LED& led);
};




#endif
