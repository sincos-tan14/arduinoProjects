#ifndef BUTTON_H
#define BUTTON_H
#include "CarPart.h"

class Button : public CarPart {
private:
    int _pin;
    bool _state;
    bool _lastState;
    int _lastDebounceTime;


public:
    Button(int i);

    void begin();
    bool isPressed();
    bool isHeldDown() const;
    bool isReady() override;
};




#endif
