#include "Engine.h"
#define MAX_ENGINE_POWER 100
#define MIN_ENGINE_POWER 0

Engine::Engine(int pin) : _pin(pin) {

}
Engine::~Engine() { Serial.println("Engine cleaned up.");}

bool Engine::setPowerLevel(int power) {
        if (power <= MAX_ENGINE_POWER && power >= MIN_ENGINE_POWER) {
            _powerLevel = power;
        } else if (power < MIN_ENGINE_POWER) {
            _powerLevel = MIN_ENGINE_POWER;
        } else if (power > MAX_ENGINE_POWER) {
            _powerLevel = MAX_ENGINE_POWER;
        }
        return true;
}

bool Engine::isReady() {return true;}
