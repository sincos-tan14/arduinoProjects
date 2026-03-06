#ifndef ENGINEUNIT_H
#define ENGINEUNIT_H
#include "Engine.h"
#include "CarPart.h"

#define MAX_ENGINE_POWER 255
#define MIN_ENGINE_POWER 0 

#define DEFAULT_TURN_SPEED 150
#define TIME_FOR_90_DEG 600


template <int _memberCount>
class EngineUnit : public CarPart{
private:
    Engine* engines[_memberCount];
    int _currentEngineCount;
    int enginesPowerLevel[_memberCount];

    bool _isTurning;
    unsigned long _turnStartTime;
    unsigned long _turnDurationMs;

public:
    EngineUnit() {
        _currentEngineCount = 0;
        _isTurning = false;
        _turnStartTime = 0;
        _turnDurationMs = 0;

    }
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
        if (power <= MAX_ENGINE_POWER && power >= MIN_ENGINE_POWER) {
            for (int i = 0; i < _memberCount; ++i) {
                engines[i]->setPowerLevel(power);
            }
        } else if (power < MIN_ENGINE_POWER) {
            for (int i = 0; i < _memberCount; ++i) {
                engines[i]->setPowerLevel(MIN_ENGINE_POWER);
            }            
        } else if (power > MAX_ENGINE_POWER) { 
            for (int i = 0; i < _memberCount; ++i) {
                engines[i]->setPowerLevel(MAX_ENGINE_POWER);
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


    // function is not ready, we have yet to give command to engines to move
    bool turn(int angle) {
        int true_angle;
        
        if (angle < 0) {
            true_angle = -(angle % 360);
        } else {
            true_angle = (angle % 360);
        }

        _turnDurationMs = (true_angle / 90.0) * TIME_FOR_90_DEG;


        _turnStartTime = millis();
        _isTurning = true;

        return true
    }



};

#endif