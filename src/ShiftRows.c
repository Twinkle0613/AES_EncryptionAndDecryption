#include "ShiftRows.h"
#include <stdint.h>
#include "SubBytes.h"

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