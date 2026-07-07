#ifndef ENGINE_H
#define ENGINE_H

#include <Arduino.h>

class Engine {
private:
    int _pinPWM;   // Connects to ENA or ENB on L298N
    int _pinIN1;   // Connects to IN1 or IN3
    int _pinIN2;   // Connects to IN2 or IN4
    int _location;
    int _powerLevel;

public:
    // Constructor now requires all 3 control pins
    Engine(int pinPWM, int pinIN1, int pinIN2, int location);
    ~Engine();

    void init(); // Call this in setup()
    bool setPowerLevel(int power);
    void setDirection(bool forward);
    void brake();
    bool isReady();
    int getLocation() const { return _location; }
};

#endif