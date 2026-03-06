
#include "Engine.h"
#include "EngineUnit.h"
#include <Arduino.h>

Engine engineFL(1, 1);
Engine engineRL(2, 2);
Engine engineFR(3, 3);
Engine engineRR(4, 4);

Engine engines[4] = {engineFL, engineFR, engineRL, engineRR};
int sizeOfEngines = sizeof(engines)/sizeof(engines[0]);
EngineUnit<4> unit;


void setup() {
  Serial.begin(9600);
  unit.isReady();
}

void loop() {

}

