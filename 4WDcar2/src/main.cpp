
#include "Engine.h"
#include "EngineUnit.h"
#include <Arduino.h>

Engine engineFL(3, 1);
Engine engineRL(5, 2);
Engine engineFR(4, 3);
Engine engineRR(6, 4);

Engine engines[4] = {engineFL, engineFR, engineRL, engineRR};
int sizeOfEngines = sizeof(engines)/sizeof(engines[0]);
EngineUnit<4> unit;


void setup() {
  Serial.begin(9600);
  unit.isReady();
}

void loop() {

}

