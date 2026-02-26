#ifndef ENGINEUNIT_H
#define ENGINEUNIT_H
#include "Engine.h"

template <int _memberCount>
class EngineUnit {
private:
    Motor* engines[_memberCount];
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

    bool setPowerLevel(int power) {
        if (power <= 100 && power >= 0) {
            for (int i = 0; i < _memberCount; ++i) {
                enginesPowerLevel[i] = power;
            }
        } else if (power < 0) {
            for (int i = 0; i < _memberCount; ++i) {
                enginesPowerLevel[i] = 0;
            }            
        } else if (power > 100) {
            for (int i = 0; i < _memberCount; ++i) {
                enginesPowerLevel[i] = 100;
            }            
        }
    }


};

#endif