#include "Decryption.h"
#include "Encryption.h"
#include "stdint.h"
#include "stdio.h"
#include "AddRoundKey.h"
#include "KeyExpansion.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "SubBytes.h"   

void invCipher(uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound){
  int i;
  uint8_t state[4][4];
  copyState(in,state);
  addRoundKey(state,word,(NumOfRound+1)*Nb-1);
  for( i =  NumOfRound - 1 ; i >= 1 ; i--){
    invShiftRow(state);
    invSubBytes(state);
    addRoundKey(state,word, (i+1)*Nb-1 );
    invMixColumns(state);
  }
    invShiftRow(state);
    invSubBytes(state);
    addRoundKey(state,word,3);
    copyState(state,out);
}

void decryption_16byte(uint8_t cipherKey[][4],uint8_t key[],uint8_t result[][4]){
   uint32_t word[44];
   keyExpansion(key,word,4,10);
   invCipher(cipherKey,result,word,10);
}


void decryp_16byte(uint8_t plainText[][4], uint8_t key[], uint8_t encrypOut[][4], int sizeofAES){
  int wordSize;
  int round;
  int keySize;
  configureAES(sizeofAES,&keySize,&wordSize,&round);
  uint32_t word[wordSize];
  keyExpansion(key,word,keySize,round);
  invCipher(plainText,encrypOut,word,round);
}



