#include "Screen.h"

Screen::Screen() {
        this->clearLines();
}

void Screen::write(char* line) {
        strcpy(lines[0], lines[1]);
        strcpy(lines[1], lines[2]);
        strcpy(lines[2], lines[3]);
        strcpy(lines[3], line);
}

void Screen::write(char* line, int replace_line) {
        strcpy(lines[replace_line - 1 - 48], line);
}

void Screen::clearLines() {
        for (int i = 0; i < 4; i++) {
                strcpy(lines[i], "");
        }
}
