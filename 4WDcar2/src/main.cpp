#include "Engine.h"
#include "EngineUnit.h"
#include <Arduino.h>

// Left side motors wired in parallel to L298N Channel A (ENA, IN1, IN2)
Engine engineLeft(3, 4, 5, 1); 

// Right side motors wired in parallel to L298N Channel B (ENB, IN3, IN4)
Engine engineRight(6, 7, 8, 2);

EngineUnit<4> unit;

// Error handling function to halt the system in case of critical errors
void haltSystem() {
  Serial.println("CRITICAL ERROR: The unit is not ready. System halted.");
  
  pinMode(LED_BUILTIN, OUTPUT);
  
  
  while (true) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}

void testRun() {
  if (!unit.isReady()) {
    Serial.println("Halting system called from testRun() due to unit not being ready.");
    haltSystem();
  }

  unit.setUnitPowerLevel(50);
  delay(2000); // Run for 2 seconds

  unit.setUnitPowerLevel(0);
}

void setup() {
  Serial.begin(9600);
  delay(1000); 

  // Syntax error fixed, and safe shutdown called
  if (!unit.isReady()) {
    haltSystem();
  }

  Serial.println("System initialized successfully. Starting...");
}

void loop() {
  testRun();
  return;
}