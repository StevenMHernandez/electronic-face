#include "Arduino.h"
#include "definitions.h"

class Screen {
public:
        Screen();
        void write(char* line);
        void write(char* line, int replace_line);
        void clearLines();
        char lines[4][11];
};
