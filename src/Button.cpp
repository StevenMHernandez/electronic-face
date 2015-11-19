#include "Button.h"

Button::Button(int pin) {
        pinMode(pin, INPUT);
        this->pin = pin;
}

bool Button::isNewPress() {
        if (!state) {
                return this->update();
        } else {
                this->update();
                return false;
        }
}

bool Button::isPressed() {
        return this->update();
}

bool Button::update() {
        this->state = digitalRead(this->pin);
        return this->state;
}
