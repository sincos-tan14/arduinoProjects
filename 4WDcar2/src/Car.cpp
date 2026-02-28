#include "Button.h"
#include "EngineUnit.h"
#include "Car.h"

Car::Car(EngineUnit<4>* unit, Button* startButton) : _startButton(startButton), _unit(unit) { }

bool Car::setCarSpeed(int i) { return _unit->setUnitPowerLevel(i); }

bool Car::isCarReady() {
    for (unsigned int i = 0; i < (sizeof(carParts)/sizeof(carParts)); ++i) {
        if (!(carParts[i]->isReady())) return false;
    }
    return true;
}