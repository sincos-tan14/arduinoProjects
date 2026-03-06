#ifndef MOTOR_H
#define MOTOR_H
#include "CarPart.h"

class Engine : public CarPart {
private:
    const int _pin;
    bool _state;
    int _powerLevel;
    int _location; // 1-4 engine location, FL; RL; FR; RR

public:
    Engine(int pin, int location);
    ~Engine() override;

    bool isReady() override;
    bool setPowerLevel(int power);

};



#endif