#include "MixColumns.h"
#include <stdint.h>

#define getBit(value,posBit)  ( ( value >> posBit) & 1 )

uint8_t multiInGF(uint8_t value, uint8_t valueOfMulti ){
  uint8_t reminder;
  int value2 = multiWithXRO(value,valueOfMulti);
  int i;
  reminder = module0x11bWithXRO(value2);
  return reminder;   
}

uint8_t module0x11bWithXRO(int value){
   int i;
   int reminder = value;
     for( i = 15; i >= 8; i--){
        if( getBit(reminder,i)  ){
          reminder ^= (0x11b << (i-8) ); 
        }
     }
   return (uint8_t)reminder;
}

int multiWithXRO(uint8_t value1, uint8_t value2){
  int i;
  int store = 0;
  for( i = 0 ; i < 8 ; i++){
    if(  getBit(value2,i) ){
      store ^= (value1 << i);
    }
  }
  return store;
}

void mixColumns( uint8_t state[][4]){
  int col;
  uint8_t value0,value1,value2,value3;
  for( col = 0 ; col < 4 ; col++){
     value0 =  multiInGF(0x02,state[0][col]) ^  multiInGF(0x03,state[1][col]) ^ state[2][col]  ^ state[3][col];
     value1 = state[0][col] ^  multiInGF(0x02,state[1][col]) ^ multiInGF(0x03,state[2][col]) ^ state[3][col];
     value2 = state[0][col] ^ state[1][col] ^ multiInGF(0x02,state[2][col]) ^ multiInGF(0x03,state[3][col]);
     value3 = multiInGF(0x03,state[0][col]) ^ state[1][col] ^ state[2][col] ^ multiInGF(0x02,state[3][col]);
    state[0][col] = value0;
    state[1][col] = value1;
    state[2][col] = value2;
    state[3][col] = value3;
  }
}

