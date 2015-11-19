#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "global.h"
#include "bitmap.h"
#include "definitions.h"
#include "eyes.h"
#include "helpers.h"
#include "transitions.h"

void setup() {
        pinMode(13, OUTPUT);
        pinMode(2, INPUT);
        digitalWrite(13, HIGH);
        Serial.begin(9600);

        delay(1000);
        display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
        display.clearDisplay();
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setTextWrap(false);

        draw_eye(CIRCLE);
        delay(1000);
        digitalWrite(13, LOW);
}

void loop() {
        while (!eeprom.available()) {
                Serial.println("not available");
                display.clearDisplay();
                draw_circle_eye();
                display.setCursor(118, 48);
                display.print("x");
                display.display();
                eeprom.reset();
                delay(100);
        }
        char action = eeprom.next_byte();
        while(!isValid(eeprom.check_next_byte())) {
                eeprom.next_byte();
        }
        action = eeprom.next_byte();
        Serial.print("action: ");
        Serial.println((int)action);
        switch(action) {
        case DRAW_EYES:
                draw_eye(eeprom.next_byte());
                break;
        case TRANSITION:
                transition(eeprom.next_byte());
                break;
        case WRITE:
        {
                int replace_line = eeprom.next_byte();
                char string[10] = {0,0,0,0,0,0,0,0,0};
                int i = 0;
                while(isValid(eeprom.check_next_byte())) {
                        string[i] = eeprom.next_byte();
                        i++;
                }
                Serial.println(string);
                if(replace_line != (char)48) {
                        screen.write(string, replace_line);
                } else {
                        screen.write(string);
                }
                draw_screen();
        }
        break;
        case CLEAR_LINES:
                screen.clearLines();
                break;
        case BITMAP:
                draw_bitmap(eeprom.next_byte());
                break;
        case STORE_BITMAP_INDEX:
        {
                int bitmap_index = eeprom.next_byte();
                char bitmap_location[5] = {0,0,0,0,0};
                int i = 0;
                while(isValid(eeprom.check_next_byte())) {
                        bitmap_location[i] = eeprom.next_byte();
                        i++;
                }
        }
        break;
        case LOOP_BITMAPS:
        {
                int params[11];
                params[0] = eeprom.next_byte();
                int string[10];
                for (int i = 0; i > 10; i++) {
                        params[i+1] = eeprom.next_byte();
                        if (params[i+1] != (char)255) {
                                string[i] = params[i+1];
                        } else {
                                Wire.flush();
                        }
                }
                loop_bitmaps(string, params[0]);
        }
        break;
        case PAUSE:
        {
                char string[11];
                int i = 0;
                while(isValid(eeprom.check_next_byte())) {
                        string[i] = (int)eeprom.next_byte();
                        i++;
                }
                pause(atol(string));
        }
        break;
        default:
                break;
        }
        while(isValid(eeprom.check_next_byte())) {
                eeprom.next_byte();
        }
        delay(100);
}
