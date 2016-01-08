#include "AddRoundKey.h"
#include <stdint.h>
#include <stdio.h>


/*
 *AddRoundKey is transformation in the Cipher and Inverse Cipher in which a Round Key is added to the State using an XOR operation. 
 *The length of a Round Key equals the size of the State.
 * (i.e., for Nb = 4, the Round Key length equals 128 bits/16 bytes).
 *
 *
 *  W - word => 32-bit
 *  S - byte => 8-bit
 *
 *        S(0,0) S(0,1) S(0,2) S(0,3)                                S'(0,0) S'(0,1) S'(0,2) S'(0,3)
 *        S(1,0) S(1,1) S(1,2) S(1,3)   ^   W[0] W[1] W[2] W[3]   =  S'(1,0) S'(1,1) S'(1,2) S'(1,3)
 *        S(2,0) S(2,1) S(2,2) S(2,3)                                S'(2,0) S'(2,1) S'(2,2) S'(2,3)
 *        S(3,0) S(3,1) S(3,2) S(3,3)                                S'(3,0) S'(3,1) S'(3,2) S'(3,3)
 *
 *
 *  -----------------
 * | Function List: |
 * -----------------
 * void addRoundKey(uint8_t state[][Nb],uint32_t word[], int limit);
 * void convWordToArr( uint8_t key[][Nb],uint32_t word[], int limit);
 *
 *
 *  ------------------------
 * | Explaination Function |
 * ------------------------
 * The convWordToArr(...) function is used for converting a word(32-bit) to 4x4 2-D array.
 *
 *  ---------------------------------
 * | Explaination Input Of Function |
 * ---------------------------------
 * addRoundKey(uint8_t state[][Nb],uint32_t word[], int limit):
 *    state - store the 4x4 2-D array input data that was type by users.
 *    word - store the array key that was generate by KeyExpansion(...)
 *    limit - store the number of limit used in convWordToArr.
 *
 * convWordToArr( uint8_t key[][Nb],uint32_t word[], int limit):
 *    key -  store the 4x4 2-D array data is converted.
 *    word - store the data need to convert to 2-D array.
 *    limit - to select the number of location in word that need to doing convertion
 */

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