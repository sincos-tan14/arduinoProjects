#ifndef CAR_PART.H
#define CAR_PART.H
#include <Arduino.h>

class CarPart {
public:
    virtual bool isReady() = 0;
    virtual ~CarPart() { Serial.println("CarPart cleaned up.");}
private:
    int _pin;

};

#endif