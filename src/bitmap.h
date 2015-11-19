#include "frames.h"

unsigned char* _select_bitmap_by_frame_number(int frame_number) {
        switch (frame_number) {
        case 1:
                return bitmap_1;
        case 2:
                return bitmap_2;
        case 3:
                return bitmap_3;
        case 4:
                return bitmap_4;
        default:
                return bitmap_1; //maybe an (image not available) image
                break;
        }
}

void draw_bitmap(int frame) {
        display.clearDisplay();
        unsigned char* bitmap = _select_bitmap_by_frame_number(frame);
        int16_t i, j, h, byte, to_the_power;
        for(j=0; j<64; j++) { //every column
                for(i=0; i<8; i++ ) { //every row
                        byte = bitmap[j*8 + i];
                        if (byte != 0) {
                                for (h=0; h < 8; h++) { //every bit
                                        to_the_power = pow(2, 8-(h+1));
                                        if (h < 6) {
                                                to_the_power++;
                                        }
                                        if (byte >= to_the_power) {
                                                display.drawPixel(32+(i*8+h), 0+j, WHITE);
                                                byte = byte - to_the_power;
                                        }
                                }
                        }
                }
        }
        display.display();
}

void loop_bitmaps(int frames[4], int frame_length) {
        bool new_press = false;
        while(!new_press) { //set some wait_pad()
                for (int i = 0; i < 4; i++) {
                        draw_bitmap(frames[i]);
                        new_press = new_press || button.isNewPress();
                        // delay(frame_length);
                }
        }
}
