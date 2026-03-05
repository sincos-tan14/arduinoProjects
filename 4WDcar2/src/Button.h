#ifndef BUTTON_H
#define BUTTON_H
#include "CarPart.h"

class Button : public CarPart {
private:
    int _pin;
    bool _state;
    bool _lastState;
    int _lastDebounceTime;
    bool _isTestButton;


public:
    Button(int pin, bool isTestButton = false);
    ~Button() override;

    void begin();
    bool isPressed();
    bool isHeldDown() const;
    bool isReady() override;
    bool isTestButton();
};




#endif
