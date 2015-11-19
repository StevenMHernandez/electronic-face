#include "definitions.h"

void draw_circle_eye() {
        display.fillCircle(display.width()/2, display.height()/2, 18, WHITE);
}

void draw_circle_o_eye() {
        display.drawCircle(display.width()/2, display.height()/2, 18, WHITE);
        display.drawCircle(display.width()/2, display.height()/2, 17, WHITE);
}

void draw_heart_eye() {
        display.fillCircle(54, display.height()/2 - 2, 8, WHITE);
        display.fillCircle(70, display.height()/2 - 2, 8, WHITE);
        display.fillTriangle(46, 32, 78, 32, 62, 49, WHITE);
}

void draw_diamond_eye() {
        display.fillTriangle(46, 32, 78, 32, 62, 10, WHITE);
        display.fillTriangle(46, 32, 78, 32, 62, 54, WHITE);
}

void draw_eye(int eye_type) {
        display.clearDisplay();
        switch (eye_type) {
        case CIRCLE:
                draw_circle_eye();
                break;
        case CIRCLE_O:
                draw_circle_o_eye();
                break;
        case HEART:
                draw_heart_eye();
                break;
        case DIAMOND:
                draw_diamond_eye();
        default:
                break;
        }
        display.display();
}
