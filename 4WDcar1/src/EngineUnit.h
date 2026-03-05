#ifndef ENGINEUNIT_H
#define ENGINEUNIT_H
#include "Engine.h"

#define MAX_ENGINE_POWER 100
#define MIN_ENGINE_POWER 0

template <int _memberCount>
class EngineUnit {
private:
    Engine* engines[_memberCount];
    int _currentEngineCount;
    int enginesPowerLevel[_memberCount];


public:
    EngineUnit() {}
    
    bool addEngine(Engine& engine) {
        if (_currentEngineCount < _memberCount) {
            engine[_currentEngineCount] = engine;
            _currentEngineCount++;
            return true;
        }
        return false;
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
    }

    bool isReady() {
        for (int i = 0; i < _memberCount; i++) {
            if (engines[i] == 0) {
                return false;
            }
        }
        return true;
    }



};

#endif