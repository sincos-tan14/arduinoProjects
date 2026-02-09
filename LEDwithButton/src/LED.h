#ifndef LED_H
#define LED_H

class LED {
private:
    int _pin;
    bool _state;


public:
    LED(int pin, bool state);
    int getPin();
    bool getState();
    void setState( bool state );
};

#endif