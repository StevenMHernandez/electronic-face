#include "Arduino.h"

class Button {
public:
        Button(int pin);
        bool isNewPress();
        bool isPressed();
        bool state;
private:
        bool update();
        int pin;
};
