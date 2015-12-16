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

void mixColumns( uint8_t state[][Nb]){
  int col;
  uint8_t value0,value1,value2,value3;
  for( col = 0 ; col < Nb ; col++){
     value0 =  timesTwo(state[0][col]) ^  timesThree(state[1][col]) ^ state[2][col]  ^ state[3][col];
     value1 = state[0][col] ^  timesTwo(state[1][col]) ^ timesThree(state[2][col]) ^ state[3][col];
     value2 = state[0][col] ^ state[1][col] ^ timesTwo(state[2][col]) ^ timesThree(state[3][col]);
     value3 = timesThree(state[0][col]) ^ state[1][col] ^ state[2][col] ^ timesTwo(state[3][col]);
    state[0][col] = value0;
    state[1][col] = value1;
    state[2][col] = value2;
    state[3][col] = value3;
  }
}

//**************addRoundKey****************//


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

//************keyExpansion**********//

void convKeyToArr(char* key, uint8_t cipherKey[][4], int keySize){
  int row,col;                               
  for(col = 0; col < keySize ; col++){             
    for(row = 0; row < 4 ; row++){           
      cipherKey[row][col] = key[row + (4*col)];   
    }                                        
  }  
  
}
uint32_t convKeyToWord(uint8_t key0,uint8_t key1,uint8_t key2,uint8_t key3){
   // if(key0 == NULL || key1 == NULL || key2 == NULL || key3 == NULL ){
   // }
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
    //printf("word[%d] = %.*x\n",i,8,word[i]);
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
   // printf("word[%d] = %.*x\n",i,2,word[i]);
    i++;
  }
}


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
 // printf("state\n");
 // printfState(state);
  addRoundKey(state,word,3);
   for( i = 1 ; i <= NumOfRound - 1 ; i++){
     subBytes(state);
   // printf("subBytes\n");
   // printfState(state);
     shiftRow(state);
   // printf("shiftRow\n");
   // printfState(state);
     mixColumns(state);
   //  printf("mixColumns\n");
   // printfState(state);
     addRoundKey(state,word, (i+1)*Nb-1 );
    }
    subBytes(state);
    shiftRow(state);
    addRoundKey(state,word,(NumOfRound+1)*Nb-1 );
    copyState(state,out);
}


