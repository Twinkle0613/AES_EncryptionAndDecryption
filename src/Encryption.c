#include "Encryption.h"
#include <stdint.h>
#include <stdio.h>

#include "AddRoundKey.h"
#include "KeyExpansion.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "SubBytes.h"


void copyState(uint8_t in[][4],uint8_t state[][4]){
    int row,col;
  for(row = 0 ; row < 4 ; row++){
    for(col = 0; col < 4 ; col++){
    state[row][col] = in[row][col];
    }
  }
}

void cipher( uint8_t in[][4], uint8_t out[][4], uint32_t word[],int NumOfRound){
  int i;
  uint8_t state[4][4];
  copyState(in,state);
  addRoundKey(state,word,3);
   for( i = 1 ; i <= NumOfRound - 1 ; i++){
     subBytes(state);
     shiftRow(state);
     mixColumns(state);
     addRoundKey(state,word, (i+1)*Nb-1 );
    }
    subBytes(state);
    shiftRow(state);
    addRoundKey(state,word,(NumOfRound+1)*Nb-1 );
    copyState(state,out);
}

void encryption_16byte(uint8_t plainText[][4],uint8_t key[],uint8_t result[][4]){
   uint32_t word[44];
   keyExpansion(key,word,4,10);
   cipher(plainText,result,word,10);
}



