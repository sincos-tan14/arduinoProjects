#ifndef BUTTON_H
#define BUTTON_H
#include "LED.h"

class Button {
private:
    int _pin;
    bool _state;
    bool _lastState;
    int _lastDebounceTime;

    Button* _twinButton = nullptr;

public:
    Button(int i);
    Button(int i, Button& twinButton);

    bool isPressed();
    void update(LED& led);
    bool addTwinButton(Button& button);
    Button* getTwinButton() const;
};




#endif
