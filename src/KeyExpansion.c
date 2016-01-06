#include "KeyExpansion.h"
#include <stdint.h>
#include <stdio.h>
#include "SubBytes.h"



/**
 * KeyExpansion is routine used to generate a series of Round Keys from the Cipher Key.
 *
 * 
 * Decryption Concept Diagram:
 *
 *           0                        1                          10
 * 0x2b 0x28 0xab 0x09      0xa0 0x88 0x23 0x2a        0x57 0xd0 0xc9 0xe1
 * 0x7e 0xae 0xf7 0xcf  ->  0xfa 0x54 0xa3 0x6c  ..... 0x5c 0x14 0xee 0x3f
 * 0x15 0xd2 0x15 0x4f      0xfe 0x2c 0x39 0x76        0x00 0xf9 0x25 0x0c
 * 0x16 0xa6 0x88 0x3c      0x17 0xb1 0x39 0x05        0x6e 0xa8 0x89 0xc8
 *
 *  -----------------
 * | Function List: |
 * -----------------
 *
 * >>> Main Function <<<
 * void keyExpansion(uint8_t key[] ,uint32_t word[] ,int keySize, int numOfRound);
 * void convKeyToArr(char* key, uint8_t cipherKey[][4], int keySize);
 * uint32_t convKeyToWord(uint8_t key0,uint8_t key1,uint8_t key2,uint8_t key3);
 * uint32_t rotWord(uint32_t temp);
 * uint32_t subWord(uint32_t temp);
 *
 *  ------------------------
 * | Explaination Function |
 * ------------------------
 * >>> Main Function <<<
 * The keyExpansion(...) function is used to generate a series of Round Keys from the Cipher Key
 * The convKeyToArr(...) function is used for coverting from a string of key to 4X4 2-D array.
 * The convKeyToWord(...) function is used for coverting from 4X4 2-D array to a string of key.
 * The rotWord(...) function is used in the Key Expansion routine that takes a four-byte word and performs a cyclic permutation.
 * The subWord(...) function is used in the Key Expansion routine that takes a four-byte input word 
 * and applies an S-box to each of the four bytes to produce an output word.
 * 
 *  ---------------------------------
 * | Explaination Input Of Function |
 * ---------------------------------
 *
 *
 *  void keyExpansion(uint8_t key[] ,uint32_t word[] ,int keySize, int numOfRound);
 *    key - store the encrypt key was typed by users.
 *    keySize - store the encrypt key size.
 *    word - store the array is set by KeyExpansion Function.
 *    NumOfRound - store the number of round that depend on the AES mode.
 * 
 *  uint32_t rotWord(uint32_t temp);
 *    temp - store the 32-bit data that is set by program.
 *
 *  uint32_t subWord(uint32_t temp);
 *    temp - store the 32-bit data that is set by program.
 *
 *
 */

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