#ifndef Encryption_H
#define Encryption_H
#include <stdint.h>
#include <stdlib.h>

uint8_t** creat2DArray4x4(void);
void printState(uint8_t** state);
uint8_t** convInputToState(uint8_t in[]);
void subBytes(uint8_t** state);
void shift(int row , int stateSize , uint8_t** state);
//extern uint8_t sBox[256];
#endif // Encryption_H
