#ifndef Encryption_H
#define Encryption_H
#include <stdint.h>
#include "AddRoundKey.h"
#include "KeyExpansion.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "SubBytes.h"   
#include "string.h"


#define AES_128 1   //word[44]  round = 10
#define AES_192 2   //word[52]  round = 12
#define AES_256 3   //word[60]  round = 14

#define AES_128_KEYSIZE 16
#define AES_192_KEYSIZE 24
#define AES_256_KEYSIZE 32
char* encrypStr(char* str,char* key, int AESmode);
void encryp_16byte(uint8_t plainText[][4], uint8_t key[], uint8_t encrypOut[][4], int AESmode);
void cipher( uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound);

// void convWordToArr( uint8_t key[][4],uint32_t word[], int limit);
//void prinfWord( uint32_t word[],int limit);
char* optimizeKey(char*key,int AESmode);
char* keyProcess(char* key,int keySizeofAES);
void fillZeroToStr(int keySize,char* str,int keySizeofAES);
char* optimizeStr(char* str);
int reserveChipherLen(char* str);
void convStateToStrWithIndex( uint8_t state[][4],char* str,int index);
void convStrToStateWithIndex(char* str, uint8_t state[][4], int index);
void configureAES(int sizeofAES,int* keySize,int* wordSize, int* round);
void copyState(uint8_t in[][4],uint8_t state[][4]);






#endif // Encryption_H
