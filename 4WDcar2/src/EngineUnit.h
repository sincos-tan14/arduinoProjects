#ifndef ENGINEUNIT_H
#define ENGINEUNIT_H
#include "Engine.h"
#include "CarPart.h"

#define MAX_ENGINE_POWER 100
#define MIN_ENGINE_POWER 0

template <int _memberCount>
class EngineUnit : public CarPart{
private:
    Engine* engines[_memberCount];
    int _currentEngineCount;
    int enginesPowerLevel[_memberCount];


public:
    EngineUnit() {}
    ~EngineUnit() override { Serial.println("EngineUnit cleaned up.");};
    
    bool addEngine(Engine& engine) {
        if (_currentEngineCount < _memberCount) {
            engines[_currentEngineCount] = &engine;
            _currentEngineCount++;
            return true;
        }
        return false;
    }

    bool addEngines(Engine* engines, int numberOfEngines) {
        for (int i = 0; i < numberOfEngines; ++i) {
            addEngine(engines[i]);
        }
        return true;
    }

    bool setUnitPowerLevel(int power) {
        if (power <= 100 && power >= 0) {
            for (int i = 0; i < _memberCount; ++i) {
                engines[i].setPowerLevel(power);
            }
        } else if (power < 0) {
            for (int i = 0; i < _memberCount; ++i) {
                engines[i].setPowerLevel(MIN_ENGINE_POWER);
            }            
        } else if (power > 100) {
            for (int i = 0; i < _memberCount; ++i) {
                engines[i].setPowerLevel(MAX_ENGINE_POWER);
            }            
        }
        return true;
    }

    bool isReady() override {
        for (int i = 0; i < _memberCount; i++) {
            if (engines[i] == 0) {
                return false;
            }
        }
        return true;
    }



};

#endif