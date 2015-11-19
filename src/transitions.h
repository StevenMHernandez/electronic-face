#include "definitions.h"

void screen_clear() {
        display.clearDisplay();
        display.display();
}

void screen_wipe_left() {
        for (int i=0; i<SSD1306_LCDWIDTH; i++) {
                display.drawFastVLine(i, 0, SSD1306_LCDHEIGHT, INVERSE);
                if (!(i%12)) display.display();
        }
        for (int i=0; i<SSD1306_LCDWIDTH; i++) {
                display.drawFastVLine(i, 0, SSD1306_LCDHEIGHT, BLACK);
                if (!(i%9)) display.display();
        }
}

void screen_wipe_right() {
        for (int i = SSD1306_LCDWIDTH; i > 0; i--) {
                display.drawFastVLine(i, 0, SSD1306_LCDHEIGHT, INVERSE);
                if (!(i%12)) display.display();
        }
        for (int i = SSD1306_LCDWIDTH; i > 0; i--) {
                display.drawFastVLine(i, 0, SSD1306_LCDHEIGHT, BLACK);
                if (!(i%9)) display.display();
        }
}

void screen_wipe_top() {
        for (int i=0; i<SSD1306_LCDHEIGHT; i++) {
                display.drawFastHLine(0, i, SSD1306_LCDWIDTH, INVERSE);
                if (!(i%12)) display.display();
        }
        for (int i=0; i<SSD1306_LCDHEIGHT; i++) {
                display.drawFastHLine(0, i, SSD1306_LCDWIDTH, BLACK);
                if (!(i%9)) display.display();
        }
}

void screen_wipe_bottom() {
        for (int i = SSD1306_LCDHEIGHT; i > 0; i--) {
                display.drawFastHLine(0, i, SSD1306_LCDWIDTH, INVERSE);
                if (!(i%12)) display.display();
        }
        for (int i = SSD1306_LCDHEIGHT; i > 0; i--) {
                display.drawFastHLine(0, i, SSD1306_LCDWIDTH, BLACK);
                if (!(i%9)) display.display();
        }
}

void screen_circle_wipe() {
        for (int16_t i=0; i<(display.height() * 2.5); ) {
                display.fillCircle(display.width()/2, display.height()/2, i, WHITE);
                i++;
                if (!(i%12)) display.display();
        }
        for (int16_t i=0; i<(display.height() * 2.5); ) {
                display.fillCircle(display.width()/2, display.height()/2, i, BLACK);
                i++;
                if (!(i%9)) display.display();
        }
}
void screen_circle_wipe_reverse() {
        display.clearDisplay();
        display.display();
        for (int16_t i = (display.height()*1.25); i > 0; ) {
                display.drawCircle(display.width()/2, display.height()/2, i, WHITE);
                i--;
                if (!(i%12)) display.display();
        }
        for (int16_t i = (display.height()*1.25); i > 0; ) {
                display.drawCircle(display.width()/2, display.height()/2, i, BLACK);
                i--;
                if (!(i%9)) display.display();
        }
}

void screen_blink() {
        for (int i = 0; i < SSD1306_LCDHEIGHT/2; i++) {
                display.drawFastHLine(0, i, SSD1306_LCDWIDTH, BLACK);
                display.drawFastHLine(0, SSD1306_LCDHEIGHT - i, SSD1306_LCDWIDTH, BLACK);
                if (!(i%8)) display.display();
                delay(2);
        }
}

void transition(int transition) {
        switch (transition) {
        case WIPE_LEFT:
                screen_wipe_left();
                break;
        case WIPE_RIGHT:
                screen_wipe_right();
                break;
        case WIPE_TOP:
                screen_wipe_top();
                break;
        case WIPE_BOTTOM:
                screen_wipe_bottom();
                break;
        case CIRCLE_WIPE:
                screen_circle_wipe();
                break;
        case CIRCLE_WIPE_R:
                screen_circle_wipe_reverse();
                break;
        case BLINK:
                screen_blink();
                break;
        default:
                break;
        }
        display.clearDisplay();
        display.display();
}
