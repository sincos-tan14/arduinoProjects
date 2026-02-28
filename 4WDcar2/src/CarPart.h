#ifndef CAR_PART.H
#define CAR_PART.H

class CarPart {
public:
    virtual bool isReady() = 0;
private:
    int _pin;
};

#endif