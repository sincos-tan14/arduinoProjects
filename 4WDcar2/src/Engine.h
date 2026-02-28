#ifndef MOTOR_H
#define MOTOR_H
#include "CarPart.h"

class Engine : public CarPart {
private:
    const int _pin;
    bool _state;
    int _powerLevel;


public:
    Engine(int pin);

    bool isReady() override;
    bool setPowerLevel(int power);

};



#endif