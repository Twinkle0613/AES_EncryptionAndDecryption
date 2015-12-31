#ifndef AddRoundKey_H
#define AddRoundKey_H
#include <stdint.h>
#include "SubBytes.h"
void addRoundKey(uint8_t state[][Nb],uint32_t word[], int limit);
void prinfWord( uint32_t word[],int limit);
void convWordToArr( uint8_t key[][Nb],uint32_t word[], int limit);
#endif // AddRoundKey_H
