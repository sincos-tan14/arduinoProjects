#ifndef CAR_H
#define CAR_H
#include "Button.h"
#include "EngineUnit.h"

class Car {
private:
    const Button* const _startButton;
    EngineUnit<4>* const _unit;
    CarPart* carParts[1];

public:
    Car(EngineUnit<4>* unit, Button* startButton);
    bool setCarSpeed(int i);
    bool isCarReady();
};


#endif