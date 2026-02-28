#ifndef CAR_PART_H
#define CAR_PART_H
#include <Arduino.h>

class CarPart {
public:
    virtual bool isReady() = 0;
    virtual ~CarPart() { Serial.println("CarPart cleaned up.");}
private:
    int _pin;

};

#endif