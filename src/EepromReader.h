#include <Wire.h>
#include "definitions.h"

class EepromReader {
public:
        EepromReader(int eeaddress);
        bool available();
        int next_byte();
        int check_next_byte();
        int current_byte;
        void loadBitmap(unsigned int eeaddress, unsigned char *frame);
        void reset();
private:
        int deviceaddress;
        int read_byte(int eeaddress);
        unsigned int current_eeaddress = 0;
};
