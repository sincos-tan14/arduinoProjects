#include "Engine.h"
#include "EngineUnit.h"
#include <Arduino.h>

// Left side motors (L298N Channel A), Location ID: 1 (LOC_LEFT)
Engine engineLeft(3, 4, 5, 1);
// Right side motors (L298N Channel B), Location ID: 2 (LOC_RIGHT)
Engine engineRight(6, 7, 8, 2);

// FIXED: The controller only has 2 channels
EngineUnit<2> unit;

void haltSystem() {
  Serial.println("CRITICAL ERROR: The Unit is not ready. System halted.");
  pinMode(LED_BUILTIN, OUTPUT);
  while (true) {
    digitalWrite(LED_BUILTIN, HIGH); delay(100);
    digitalWrite(LED_BUILTIN, LOW); delay(100);
  }
}

// --- Non-blocking test variables ---
unsigned long testStartTime = 0;
bool isTestRunning = false;

void startTestRun() {
  Serial.println("Starting test run (2 seconds)...");
  unit.setUnitPowerLevel(50);
  testStartTime = millis();
  isTestRunning = true;
}

void updateTestRun() {
  // If the test is running and 2000 milliseconds have passed (without delay)
  if (isTestRunning && (millis() - testStartTime >= 2000)) {
    unit.setUnitPowerLevel(0);
    isTestRunning = false;
    Serial.println("Test run completed.");
  }
}

void setup() {
  Serial.begin(9600);
  delay(1000);

  // STEP 1: Set up pins and stop motors
  engineLeft.init();
  engineRight.init();

  // STEP 2: Assign motors to the Unit
  unit.addEngine(engineLeft);
  unit.addEngine(engineRight);

  // STEP 3: Verification
  if (!unit.isReady()) {
    haltSystem();
  }

  Serial.println("System successfully initialized. Starting...");
  
  // todo
  // Run test once at startup
  startTestRun(); 
}

void loop() {
  // todo
  // FIXED: Must be updated continuously for the turn() timer to work
  unit.update(); 
  
  // todo
  // FIXED: Non-blocking test process check without delay()
  updateTestRun(); 
}