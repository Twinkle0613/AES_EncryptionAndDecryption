#ifndef Decryption_H
#define Decryption_H
#include "stdint.h"
#include "Encryption.h"
#include "AddRoundKey.h"
#include "KeyExpansion.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "SubBytes.h"   

void invCipher(uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound);
void decryp_16byte(uint8_t plainText[][4], uint8_t key[], uint8_t encrypOut[][4], int sizeofAES);
uint8_t* decrypStr(uint8_t* str,char* key,int AESmode);

#endif // Decryption_H
