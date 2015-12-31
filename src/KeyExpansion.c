#include "KeyExpansion.h"
#include <stdint.h>
#include <stdio.h>
#include "SubBytes.h"
void convKeyToArr(char* key, uint8_t cipherKey[][4], int keySize){
  int row,col;                               
  for(col = 0; col < keySize ; col++){             
    for(row = 0; row < 4 ; row++){           
      cipherKey[row][col] = key[row + (4*col)];   
    }                                        
  }  
  
}
uint32_t convKeyToWord(uint8_t key0,uint8_t key1,uint8_t key2,uint8_t key3){
  return (uint32_t)( ( key0 << 24 )| (key1 << 16 )| (key2 << 8 ) | key3);
}

uint32_t rotWord(uint32_t temp){
  return ( temp >> 24 | temp << 8);
}



uint32_t subWord(uint32_t temp){
  int i;
  uint8_t store[4];
  for(i = 0; i < 4 ; i++){
  store[i] = sBox[ (uint8_t)(temp >> (i*8) &  0xFF  ) ];
  }
  return (uint32_t)( ( store[3] << 24 )| ( store[2] << 16 )| (store[1] << 8 ) | store[0]);
}

void keyExpansion(uint8_t key[] ,uint32_t word[] ,int keySize, int numOfRound){
  int i = 0;
  uint32_t temp;
  while( i < keySize){
    word[i] =  convKeyToWord(key[4*i],key[(4*i)+1],key[(4*i)+2],key[(4*i)+3]);
    i++;
  }
  i = keySize;
  while( i < ( Nb*(numOfRound+1) ) ) {
    temp = word[i - 1];
    if( (i % keySize) == 0){
      temp = subWord(rotWord(temp)) ^ (rcon[(i/keySize)] << 24);
    }else if( keySize > 6 && (i % keySize == 4 ) ){
      temp = subWord(temp);
    }
    word[i] = word[i - keySize] ^ temp;
    i++;
  }
}