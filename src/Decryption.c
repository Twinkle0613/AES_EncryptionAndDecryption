#include "Decryption.h"
#include "Encryption.h"
#include "stdint.h"
#include "stdio.h"

//#define getBit(value,bit) (value >> bit & 0x01)



void invSubBytes(uint8_t state[][4]){
  int col,row;
  for(col = 0; col < 4 ; col++){
       for(row = 0; row < 4 ; row++){
        state[row][col] = invSBox[state[row][col]];
       }
    }
}


void invShiftRows(uint8_t state[][4]){
  
  
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

uint8_t timesEvenNumber(uint8_t value,int evenNum){
  int limit;
  int i;
  int temp = value;
  if( evenNum%2 == 1 ){
    printf("Error: Number of times can not be odd number\n");
  }else{
    
    if(evenNum < 5){
      limit = evenNum/2;
    }else{
      limit = evenNum/2 - 1;
    } 
   
   for( i = 0; i < limit ; i++){
      temp = xTime(temp);
   }
   return temp;
  }
  
}

uint8_t timesTen(uint8_t value){
  int i = 0;
  int temp = value;
  for(i = 0 ; i < 4 ; i++ ){
    temp = xTime(temp);
  }
  return temp;
}

uint8_t timesFour(uint8_t value){
  int i = 0;
  int temp = value;
  for(i = 0 ; i < 2 ; i++ ){
    temp = xTime(temp);
  }
  return temp;
}

uint8_t timesEight(uint8_t value){
  int i = 0;
  int temp = value;
  for(i = 0 ; i < 3 ; i++ ){
    temp = xTime(temp);
  }
  return temp;
}

uint8_t timesFourteen(uint8_t value){
  return ( timesTen(value) ^ timesFour(value) );
}

uint8_t timesEleven(uint8_t value){
  return (timesTen(value) ^ value);
}

uint8_t timesThirteen(uint8_t value){
  return (timesTen(value) ^ timesTwo(value) ^ value);
}

uint8_t timesNine(uint8_t value){
  return (timesEight(value) ^ value);
}





void invMixColumns(uint8_t state[][4]){
  int col;
  uint8_t value0,value1,value2,value3;
  for( col = 0 ; col < Nb ; col++){
     value0 = multiInGF(0x0e,state[0][col]) ^  multiInGF(0x0b,state[1][col]) ^ multiInGF(0x0d,state[2][col])  ^ multiInGF(0x09,state[3][col]);
     value1 = multiInGF(0x09,state[0][col]) ^  multiInGF(0x0e,state[1][col]) ^ multiInGF(0x0b,state[2][col])  ^ multiInGF(0x0d,state[3][col]);
     value2 = multiInGF(0x0d,state[0][col]) ^  multiInGF(0x09,state[1][col]) ^ multiInGF(0x0e,state[2][col])  ^ multiInGF(0x0b,state[3][col]);
     value3 = multiInGF(0x0b,state[0][col]) ^  multiInGF(0x0d,state[1][col]) ^ multiInGF(0x09,state[2][col])  ^ multiInGF(0x0e,state[3][col]);
    state[0][col] = value0;
    state[1][col] = value1;
    state[2][col] = value2;
    state[3][col] = value3;
  }
}



