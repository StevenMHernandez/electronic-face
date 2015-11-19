# Eyes

uses [PlatformIO](http://platformio.org/)

## Libraries:
1. install Adafruit-SSD1306 `platformio lib install 135` which automatically also pulls in the Adafruit-GFX library
2. Edit Adafruit-SSH1306.h uncommenting the line `#define SSD1306_128_64`

## Board Setup
1. Connect the i2c (SDA and SCL) lines as well as GND/VCC to the Monochrome SSD1306 OLED screens.
2. In 'platform.ini' file, setup board details. [board setup details can be found at [PlatformIO boards page](http://platformio.org/#!/boards)]
3. upload to board: `cmd + shift + u`

## Cartridge Setup
