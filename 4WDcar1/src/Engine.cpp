#include "Engine.h"
#define MAX_ENGINE_POWER = 100
#define MIN_ENGINE_POWER = 0

Engine::Engine(int pin) : _pin(pin) {

}

bool Engine::setPowerLevel(int power) {
        if (power <= 100 && power >= 0) {
            _powerLevel = power;
        } else if (power < 0) {
            _powerLevel = 0;
        } else if (power > 100) {
            _powerLevel = 100;
        }
}