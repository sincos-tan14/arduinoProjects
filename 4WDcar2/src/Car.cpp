#include "Car.h"

Car::Car(EngineUnit<2>* unit, Button* startButton) : _startButton(startButton), _unit(unit) {
    carParts[0] = _startButton;
    carParts[1] = _unit;
}

bool Car::setCarSpeed(int i) { 
    return _unit->setUnitPowerLevel(i);
}

bool Car::isCarReady() {
    int numParts = sizeof(carParts) / sizeof(carParts[0]); 
    
    for (int i = 0; i < numParts; ++i) {
        if (carParts[i] == nullptr || !(carParts[i]->isReady())) {
            return false;
        }
    }
    return true;
}