#include <Arduino.h>

// In standard C++, you must declare functions before using them
void myBlinkRoutine(); 

// Standard C++ entry point
// (If you define 'main', it overrides the hidden Arduino main function)
int main(void) {
    
    // Mandatory: Initialize Arduino hardware (timers, ADC, etc.)
    init(); 

    // Setup: Set the LED pin as output
    // LED_BUILTIN is usually pin 13 on Uno
    pinMode(LED_BUILTIN, OUTPUT);

    // The Infinite Loop
    while (true) {
        myBlinkRoutine();
        
        // If you need Serial to work, you often need this check inside the loop:
        if (serialEventRun) serialEventRun();
    }

    return 0; // Never reached
}

void myBlinkRoutine() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(3000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
}