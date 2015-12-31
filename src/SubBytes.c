#include "SubBytes.h"
#include <stdio.h>
#include <stdint.h>



void convStrToState(char* str, uint8_t state[][4]){
  int row,col;                               
  for(col = 0; col < 4 ; col++){             
    for(row = 0; row < 4 ; row++){           
      state[row][col] = str[row + (4*col)];   
    }                                        
  }   
}

void convStateToStr( uint8_t state[][4] , char* str){
    int row,col;                               
  for(col = 0; col < 4 ; col++){             
    for(row = 0; row < 4 ; row++){           
      str[row + (4*col)] = state[row][col];   
    }                                        
  }
  str[(row + (4*col))+1] = '\0';
}

void printfState(uint8_t state[][4]){
  int row;
  for(row = 0 ; row < 4 ; row++){
    printf("%.*x %.*x %.*x %.*x\n",2,state[row][0],2,state[row][1],2,state[row][2],2,state[row][3]);
  }
}

void subBytes(uint8_t state[][4]){
  int col,row;
  for(col = 0; col < 4 ; col++){
       for(row = 0; row < 4 ; row++){
        state[row][col] = sBox[state[row][col]];
       }
    }
}

void invSubBytes(uint8_t state[][4]){
  int col,row;
  for(col = 0; col < 4 ; col++){
       for(row = 0; row < 4 ; row++){
        state[row][col] = invSBox[state[row][col]];
       }
    }
}