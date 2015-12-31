#ifndef Encryption_H
#define Encryption_H
#include <stdint.h>
#include "AddRoundKey.h"
#include "KeyExpansion.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "SubBytes.h"   

void convWordToArr( uint8_t key[][4],uint32_t word[], int limit);
void prinfWord( uint32_t word[],int limit);
void copyState(uint8_t in[][4],uint8_t state[][4]);
void encryption_16byte(uint8_t plainText[][4],uint8_t key[],uint8_t result[][4]);
void cipher( uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound);

#endif // Encryption_H
