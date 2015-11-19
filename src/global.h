#include <Adafruit_SSD1306.h>
#include "Button.h"
#include "EepromReader.h"
#include "Screen.h"

#define SSD1306_128_64

#define BTN_PIN 2
#define EEPROM_ADDRESS 0x50
#define OLED_RESET 4

Adafruit_SSD1306 display(OLED_RESET);
Button button(BTN_PIN);
EepromReader eeprom(EEPROM_ADDRESS);
Screen screen;
