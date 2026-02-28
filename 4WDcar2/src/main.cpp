
#include "Engine.h"
#include "EngineUnit.h"
#include <Arduino.h>

Engine engineFL(3);
Engine engineFR(4);
Engine engineRL(5);
Engine engineRR(6);

Engine engines[4] = {engineFL, engineFR, engineRL, engineRR};
int sizeOfEngines = sizeof(engines)/sizeof(engines[0]);
EngineUnit<4> unit;


void setup() {
  Serial.begin(9600);
  unit.isReady();
}

void loop() {

}

