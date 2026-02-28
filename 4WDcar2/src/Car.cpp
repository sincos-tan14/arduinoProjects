#include "Button.h"
#include "EngineUnit.h"
#include "Car.h"

Car::Car(EngineUnit<4>* unit, Button* startButton) : _startButton(startButton), _unit(unit) { }

bool Car::setCarSpeed(int i) { _unit->setUnitPowerLevel(i); }

bool Car::isCarReady() {
    for (int i = 0; i < (sizeof(carParts)/sizeof(carParts)); ++i) {
        carParts[i]->isReady();
    }

}