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
  printfState(state);
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







