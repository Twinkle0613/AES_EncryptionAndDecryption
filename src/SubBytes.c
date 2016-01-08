#include "SubBytes.h"
#include <stdio.h>
#include <stdint.h>
#include "malloc.h"

/*
 *  subBytes(...) is transformation in the Cipher that processes the State using a nonlinear byte 
 *  substitution table (S-box) that operates on each of the State bytes independently.
 *
 *  invSubBytes(...) is transformation in the Inverse Cipher that is the inverse of SubBytes().
 *
 *  e.g 
 *
 * 'A'(41) 'E'(45) 'I'(49) 'M'(4d)   S-BOX   83 6e 3b e3
 * 'B'(42) 'F'(46) 'J'(4a) 'N'(4e)  ----->   2c 5a d6 2f
 * 'C'(43) 'G'(47) 'K'(4b) 'O'(4f)           1a a0 b3 84
 * 'D'(44) 'H'(48) 'L'(4c) 'P'(50)           1b 52 29 53
 *
 *
 * 'A'(41) 'E'(45) 'I'(49) 'M'(4d)   invS-BOX   f8 68 a4 65
 * 'B'(42) 'F'(46) 'J'(4a) 'N'(4e)  -------->   f6 98 5c b6
 * 'C'(43) 'G'(47) 'K'(4b) 'O'(4f)              64 16 cc 92
 * 'D'(44) 'H'(48) 'L'(4c) 'P'(50)              86 d4 5d 6c
 *
 *
 *  ------------------------
 * | Explaination Function |
 * ------------------------
 *
 * The convStateToStr(...) function is used for converting from the 2D array state to string.
 * The convStrToState(...) function is used for converting from the string to 2D array state.
 * The printfState(...) function is used for printing the data of 2D array state.
 * 
 *  -----------------
 * | Function List  |
 * -----------------
 *
 * void subBytes(uint8_t state[][4]); 
 * void invSubBytes(uint8_t state[][4]);
 * void convStateToStr( uint8_t state[][4] , char* str);
 * void convStrToState(char* str, uint8_t state[][4]);
 * void printfState(uint8_t state[][4]);
 *
 *  ---------------------------------
 * | Explaination Input Of Function |
 * ---------------------------------
 *
 *  subBytes(uint8_t state[][4]); 
 *  invSubBytes(uint8_t state[][4]);
 *      state - store input 2D array that is converted from str that is typed by used to 2D array.
 *
 *  convStateToStr( uint8_t state[][4] , char* str);
 *     state - store the 2D array that is needed for doing convertion
 *     str - store the string that is converted from 2D array to string
 * 
 *  convStrToState(char* str, uint8_t state[][4]);
 *      str - store the string that is needed for converting.
 *      state - store the 2D array that is converted form string to 2D array
 *
 *  printfState(uint8_t state[][4]);
 *      state - store the state that needed to print out.
 */

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
  str[16] = '\0';
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