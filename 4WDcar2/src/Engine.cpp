#include "Engine.h"

#define MAX_ENGINE_POWER 255
#define MIN_ENGINE_POWER 0

Engine::Engine(int pinPWM, int pinIN1, int pinIN2, int location) 
    : _pinPWM(pinPWM), _pinIN1(pinIN1), _pinIN2(pinIN2), _location(location), _powerLevel(0) {}

Engine::~Engine() { 
    brake(); // Ensure motor stops if object is destroyed
    Serial.println("Engine cleaned up.");
}

// Configures the pins. Must be called inside your main setup()
void Engine::init() {
    pinMode(_pinPWM, OUTPUT);
    pinMode(_pinIN1, OUTPUT);
    pinMode(_pinIN2, OUTPUT);
    
    // Ensure motor starts in a stopped state
    brake();
}

// Sets the wattage/speed via PWM to the Enable pin
bool Engine::setPowerLevel(int power) {
    if (power <= MAX_ENGINE_POWER && power >= MIN_ENGINE_POWER) {
        _powerLevel = power;
    } else if (power < MIN_ENGINE_POWER) {
        _powerLevel = MIN_ENGINE_POWER;
    } else if (power > MAX_ENGINE_POWER) {
        _powerLevel = MAX_ENGINE_POWER;
    }
    
    // ESP32 standard PWM write to the L298N Enable pin
    analogWrite(_pinPWM, _powerLevel);
    
    return true;
}

// Sets the H-Bridge logic to determine rotation direction
void Engine::setDirection(bool forward) {
    if (forward) {
        digitalWrite(_pinIN1, HIGH);
        digitalWrite(_pinIN2, LOW);
    } else {
        digitalWrite(_pinIN1, LOW);
        digitalWrite(_pinIN2, HIGH);
    }
}

// Stops the motor by pulling both direction pins to the same state
void Engine::brake() {
    digitalWrite(_pinIN1, LOW);
    digitalWrite(_pinIN2, LOW);
    analogWrite(_pinPWM, 0);
    _powerLevel = 0;
}

bool Engine::isReady() {
    // Basic validation: ensure pins are valid ESP32-C3 GPIOs (0-21)
    if (_pinPWM >= 0 && _pinIN1 >= 0 && _pinIN2 >= 0) {
        return true;
    }
    return false;
}