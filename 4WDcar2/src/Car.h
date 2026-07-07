#ifndef CAR_H
#define CAR_H
#include "Button.h"
#include "EngineUnit.h"

class Car {
private:
    Button* _startButton;
    EngineUnit<2>* const _unit;
    CarPart* carParts[2];

public:
    Car(EngineUnit<2>* unit, Button* startButton);
    bool setCarSpeed(int i);
    bool isCarReady();
};


#endif