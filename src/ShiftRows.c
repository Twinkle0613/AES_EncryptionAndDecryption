#include "ShiftRows.h"
#include <stdint.h>
#include "SubBytes.h"
/*
 *  ShiftRows(...) is transformation in the Cipher that takes all of the columns of the State and mixes 
 *  their data (independently of one another) to produce new columns.
 *
 *  invShiftRow(...) is transformation in the Inverse Cipher that is the inverse of ShiftRows(...).
 *
 *  e.g 
 * 
 *   'A' 'E' 'I' 'M'                     'A' 'E' 'I' 'M'
 *   'B' 'F' 'J' 'N'   ---shiftRow--->   'F' 'J' 'N' 'B'
 *   'C' 'G' 'K' 'O'                     'K' 'O' 'C' 'G'
 *   'D' 'H' 'L' 'P'                     'P' 'D' 'H' 'L'
 *
 *
 *
 *   'A' 'E' 'I' 'M'                        'A' 'E' 'I' 'M'
 *   'B' 'F' 'J' 'N'   ---invShiftRow--->   'N' 'B' 'F' 'J'
 *   'C' 'G' 'K' 'O'                        'K' 'O' 'C' 'G'
 *   'D' 'H' 'L' 'P'                        'D' 'H' 'L' 'P'
 *
 *  ------------------------
 * | Explaination Function |
 * ------------------------
 *
 * The shift(...) function is basic of ShiftRows(...) function 
 * The invShift(...) function is basic of invShiftRows(...) function 
 *
 *  -----------------
 * | Function List  |
 * -----------------
 *
 * void shift(int row , int stateSize , uint8_t state[][4]);
 * void shiftRow(uint8_t state[][4]);
 * void invShift(int row , int stateSize , uint8_t state[][4]);
 * void invShiftRow(uint8_t state[][4]);
 *
 *  ---------------------------------
 * | Explaination Input Of Function |
 * ---------------------------------
 *
 * shift(int row , int stateSize , uint8_t state[][4])
 * invShift(int row , int stateSize , uint8_t state[][4])
 *      row - the number of row for the 2D array of state.
 *      stateSize - the width of 2D array of state.
 *      state - store the string in 2D array form.
 *
 * shiftRow(uint8_t state[][4]);
 * invShiftRow(uint8_t state[][4]);
 *      state - store the string in 2D array form. 
 */
void shift(int row , int stateSize , uint8_t state[][4]){
  int rightSize = stateSize - row;
  int leftSize = row;
  int i,j;
  int k = 0;
  uint8_t rightTemp[rightSize];
  uint8_t leftTemp[leftSize];
  for( i = 0 ; i < leftSize ; i++){
    leftTemp[i] = state[row][i];
  }
  for( j = leftSize ; j < stateSize ; j++){  
    rightTemp[k++] = state[row][j];
  }
  for ( i = 0; i < rightSize ; i++){
    state[row][i] = rightTemp[i];
  }
  k = 0;
  for ( j = stateSize - leftSize ; j < stateSize ; j++){
     state[row][j] = leftTemp[k++];
  }
}

void shiftRow(uint8_t state[][4]){
  int i;
  for( i = 0 ; i < 4 ; i++) 
  shift(i,4,state);
}

void invShift(int row , int stateSize , uint8_t state[][4]){
  int leftSize = stateSize - row;
  int rightSize = row;
  int i,j;
  int k = 0;
  uint8_t rightTemp[rightSize];
  uint8_t leftTemp[leftSize];
  
  for( i = 0 ; i < leftSize ; i++){
    leftTemp[i] = state[row][i];
  }
  for( j = leftSize ; j < stateSize ; j++){  
    rightTemp[k++] = state[row][j];
  }
  for ( i = 0; i < rightSize ; i++){
    state[row][i] = rightTemp[i];
  }
  k = 0;
  for ( j = rightSize ; j < stateSize ; j++){
     state[row][j] = leftTemp[k++];
  }
}

void invShiftRow(uint8_t state[][4]){
  int i;
  for( i = 0 ; i < Nb ; i++) 
  invShift(i,Nb,state);
}