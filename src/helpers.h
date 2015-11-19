#include "Arduino.h"

bool isValid(char parameter) {
        return (parameter != (char)255);
}

void draw_screen() {
        display.clearDisplay();
        for (int i = 0; i < 4; i++) {
                display.setCursor(0, i * 16);
                display.println(screen.lines[i]);
        }
        display.display();
}

void pause(int time) {
        if (time) {
                delay(time);
        } else {
                int i = -1000;
                Serial.println("waitpad");
                while (!button.isNewPress()) {
                        if (i > 1000) {
                                display.fillTriangle(119, 59, 127, 59, 123, 63, INVERSE);
                                display.display();
                                i = 0;
                        }
                        i++;
                        delay(1);
                };
                Serial.println("end-waitpad");
        }
}
