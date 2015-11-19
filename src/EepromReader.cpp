#include "EepromReader.h"

EepromReader::EepromReader(int deviceaddress) {
        this->deviceaddress = deviceaddress;
}

bool EepromReader::available() {
        return (this->read_byte(0) != 255)
               || (this->read_byte(1) != 255)
               || (this->read_byte(2) != 255)
               || (this->read_byte(3) != 255);
}

// i2c_eeprom_read_byte:
// http://playground.arduino.cc/Code/I2CEEPROM
int EepromReader::read_byte(int eeaddress) {
        int rdata = 0xFF;
        Wire.beginTransmission(this->deviceaddress);
        Wire.send((int)(eeaddress >> 8)); // MSB
        Wire.send((int)(eeaddress & 0xFF)); // LSB
        Wire.endTransmission();
        Wire.requestFrom(this->deviceaddress,1);
        if (Wire.available()) rdata = Wire.receive();
        return rdata;
}

int EepromReader::next_byte() {
        current_eeaddress++;
        this->current_byte = this->read_byte(current_eeaddress);
        return this->current_byte;
}

int EepromReader::check_next_byte() {
        return this->read_byte(current_eeaddress + 1);
}

void EepromReader::reset() {
  this->current_eeaddress = 0;
}
