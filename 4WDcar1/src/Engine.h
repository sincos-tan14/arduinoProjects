#ifndef MOTOR_H
#define MOTOR_H

class Engine {
private:
    const int _pin;
    bool _state;
    int powerLevel;


public:
    Engine(int pin);

    bool setPowerLevel(int power);
};



#endif