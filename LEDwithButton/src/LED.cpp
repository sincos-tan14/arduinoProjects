
class LED {
private:
    int _pin;
    bool _state;


public:
    LED(int pin, bool state) : _pin(pin), _state(state) {}

    int getPin() { return _pin; }
    bool getState() { return _state; }
    void setState(bool state) {
        _state = state;
    };
};
