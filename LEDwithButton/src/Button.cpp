#include "Button.h"

class Button {
private:
    int _pin;
    bool _state;

public:
    Button(int i) : _pin(i) {  };

    bool isPressed() {return _state;};
};




