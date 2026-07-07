#ifndef ENGINEUNIT_H
#define ENGINEUNIT_H
#include "Engine.h"
#include "CarPart.h"

#define MAX_ENGINE_POWER 255
#define MIN_ENGINE_POWER 0 

#define DEFAULT_TURN_SPEED 150
#define TIME_FOR_90_DEG 600

// Define locations to help the Unit know how to steer
#define LOC_LEFT 1
#define LOC_RIGHT 2

template <int _memberCount>
class EngineUnit : public CarPart {
private:
    Engine* engines[_memberCount];
    int _currentEngineCount;
    
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
    
    ~EngineUnit() override { 
        Serial.println("EngineUnit cleaned up.");
    }
    
    bool addEngine(Engine& engine) {
        if (_currentEngineCount < _memberCount) {
            engines[_currentEngineCount] = &engine;
            _currentEngineCount++;
            return true;
        }
        return false;
    }

    bool addEngines(Engine* newEngines, int numberOfEngines) {
        bool success = true;
        for (int i = 0; i < numberOfEngines; ++i) {
            if (!addEngine(newEngines[i])) {
                success = false;
            }
        }
        return success;
    }

    bool setUnitPowerLevel(int power) {
        // Constrain power mathematically before applying to avoid redundant checks in the loop
        int constrainedPower = constrain(power, MIN_ENGINE_POWER, MAX_ENGINE_POWER);
        
        for (int i = 0; i < _currentEngineCount; ++i) {
            engines[i]->setPowerLevel(constrainedPower);
        }
        return true;
    }

    // Stops all engines
    void stopAll() {
        for (int i = 0; i < _currentEngineCount; ++i) {
            engines[i]->brake();
        }
    }

    bool isReady() override {
        // Check if the array is fully populated up to the expected _memberCount
        if (_currentEngineCount != _memberCount) return false;
        
        for (int i = 0; i < _currentEngineCount; i++) {
            if (engines[i] == nullptr || !engines[i]->isReady()) {
                return false;
            }
        }
        return true;
    }

    // Initiates the turn sequence
    bool turn(int angle) {
        if (_isTurning) return false; // Prevent overlapping turn commands

        int true_angle = abs(angle % 360);
        bool turnRight = (angle > 0);

        _turnDurationMs = (true_angle / 90.0) * TIME_FOR_90_DEG;
        _turnStartTime = millis();
        _isTurning = true;

        // Command the engines based on their location
        for (int i = 0; i < _currentEngineCount; i++) {
            engines[i]->setPowerLevel(DEFAULT_TURN_SPEED);
            
            // Skid-steer logic: 
            // Turning Right: Left wheels go forward, Right wheels go backward
            if (engines[i]->getLocation() == LOC_LEFT) {
                engines[i]->setDirection(turnRight ? true : false); 
            } else if (engines[i]->getLocation() == LOC_RIGHT) {
                engines[i]->setDirection(turnRight ? false : true);
            }
        }
        return true;
    }

    // MUST be called inside the main loop() to handle the timer
    void update() {
        if (_isTurning) {
            // Check if the elapsed time exceeds the target duration
            if (millis() - _turnStartTime >= _turnDurationMs) {
                stopAll();
                _isTurning = false;
            }
        }
    }
};

#endif