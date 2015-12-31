#include "AddRoundKey.h"
#include <stdint.h>
#include <stdio.h>

void addRoundKey(uint8_t state[][Nb],uint32_t word[], int limit){
  uint8_t key[4][Nk];
  convWordToArr(key,word,limit);
  int row,col;
  for(col = 0 ; col < 4 ; col++){
    for(row = 0; row < Nb ; row++){
     state[row][col] = state[row][col] ^ key[row][col]; 
    }
  }
}

void prinfWord( uint32_t word[],int limit){
  int i;
  for(i = limit - 3; i <= limit ; i++){
    printf("word[%d] = 0x%.*x\n",i,8,word[i]);
  }
}

void convWordToArr( uint8_t key[][Nb],uint32_t word[], int limit){
  int row,col,shift,i;
  i = 0;
  for( col =  limit - 3 ; col <= limit ; col++ ){
    shift = 0;
    for( row = 3 ; row >= 0 ; row--){
      key[row][i] = (word[col] >> shift) & 0x000000FF;
      shift = shift + 8;       
    }
    i++;
  }
}