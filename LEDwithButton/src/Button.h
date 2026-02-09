#ifndef BUTTON_H
#define BUTTON_H

class Button {
private:
    int _pin;
    bool _state;

public:
    Button(int i);

    bool isPressed();
};




#endif
