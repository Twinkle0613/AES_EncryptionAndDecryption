#include "Encryption.h"
#include <stdint.h>
#include <stdio.h>

void convStrToState(char* str, uint8_t state[][4]){
  int row,col;                               
  for(col = 0; col < 4 ; col++){             
    for(row = 0; row < 4 ; row++){           
      state[row][col] = str[row + (4*col)];   
    }                                        
  }   
}

void printfState(uint8_t state[][4]){
  int row;
  for(row = 0 ; row < 4 ; row++){
    printf("%.*x %.*x %.*x %.*x\n",2,state[row][0],2,state[row][1],2,state[row][2],2,state[row][3]);
  }
}
//*****************subBytes()******************//
void subBytes(uint8_t state[][4]){
  int col,row;
  for(col = 0; col < 4 ; col++){
       for(row = 0; row < 4 ; row++){
        state[row][col] = sBox[state[row][col]];
       }
    }
}

//*****************shiftRow()******************//

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
  for( j = leftSize ; j < stateSize ; j++){    rightTemp[k++] = state[row][j];
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
  for( i = 0 ; i < Nb ; i++) 
  shift(i,Nb,state);
}

//*****************mixColumns()******************//


int getBit( int value, int posBit ){  
  return (( value >> posBit) & 1 );
}     

uint8_t xTime(uint8_t value){
  int num = (int)value << 1;
  if(  getBit(num,8) ){
    num = num ^ 0x11b;
  }
  return (uint8_t)num;
}

uint8_t timesTwo(uint8_t value){
  return xTime(value);
}

uint8_t timesThree(uint8_t value){
  return  ( value ^ xTime(value) );
}

void _mixColumns( uint8_t state[][Nb]){
  int col;
  uint8_t value0,value1,value2,value3;
 // printfState(state);
 // printf("\n");
  for( col = 0 ; col < Nb ; col++){
  printf("\n");
     printf("0) %x %x %x %x \n",timesTwo(state[0][col]),timesThree(state[1][col]),state[2][col],state[3][col]);    
     value0 =  timesTwo(state[0][col]) ^  timesThree(state[1][col]) ^ state[2][col]  ^ state[3][col];
      printf("1) %x %x %x %x \n", state[0][col] ,  timesTwo(state[1][col]) , timesThree(state[2][col]) , state[3][col]);
     value1 = state[0][col] ^  timesTwo(state[1][col]) ^ timesThree(state[2][col]) ^ state[3][col];
     printf("2) %x %x %x %x \n",state[0][col] , state[1][col] , timesTwo(state[2][col]) , timesThree(state[3][col]));
    value2 = state[0][col] ^ state[1][col] ^ timesTwo(state[2][col]) ^ timesThree(state[3][col]);
      printf("2) %x %x %x %x \n",timesThree(state[0][col]) , state[1][col] , state[2][col] , timesTwo(state[3][col]));
     value3 = timesThree(state[0][col]) ^ state[1][col] ^ state[2][col] ^ timesTwo(state[3][col]);
  //printfState(state);
    state[0][col] = value0;
    state[1][col] = value1;
    state[2][col] = value2;
    state[3][col] = value3;
  }
}