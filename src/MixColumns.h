#ifndef MixColumns_H
#define MixColumns_H
#include <stdint.h>

void mixColumns(uint8_t state[][4]);
int multiWithXRO(uint8_t value1, uint8_t value2);
uint8_t module0x11bWithXRO(int value);
uint8_t multiInGF(uint8_t value, uint8_t valueOfMulti );
#endif // MixColumns_H
