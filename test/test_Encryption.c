#include "unity.h"
#include "Encryption.c"
#include <stdint.h>
#include <stdlib.h>
#include "CustomAssertion.h"
void setUp(void){}

void tearDown(void){}

/*
*                                                                           state
*                                                          ----------------------------------------                    
*                                                         | 'A'(41) | 'E'(45) | 'I'(49) | 'M'(4d) |      
*                                                          ----------------------------------------               
*                                  convInputToState(in)   | 'B'(42) | 'F'(46) | 'J'(4a) | 'N'(4e) |   
*       in[] = "ABCDEFGHIJKLMNOP";      ---------->       -----------------------------------------  
*                                                         | 'C'(43) | 'G'(47) | 'K'(4b) | 'O'(4f) |  
*                                                         ----------------------------------------- 
*                                                         | 'D'(44) | 'H'(48) | 'L'(4c) | 'P'(50) | 
*                                                         -----------------------------------------                    
*
*
*/
void test_convInputToState_given_ABCDEFGHIJKLMNOP(void){
  //printf("test_convInputToState_given_ABCDEFGHIJKLMNOP");
  TEST_IGNORE_MESSAGE("test_convInputToState_given_ABCDEFGHIJKLMNOP");
  uint8_t in[] = "ABCDEFGHIJKLMNOP";
  uint8_t **state;
  int col,row;
  state = convInputToState(in);
  printState(state);
 
  for(col = 0; col < 4 ; col++){
   for(row = 0; row < 4 ; row++){
     TEST_ASSERT_EQUAL(in[row + (4*col)],state[row][col]);
    }
  }
}

/*
*                      state
*     ----------------------------------------                     --------------------
*    | 'A'(41) | 'E'(45) | 'I'(49) | 'M'(4d) |                    | 83 | 6e | 3b | e3 |
*     ----------------------------------------                    --------------------
*    | 'B'(42) | 'F'(46) | 'J'(4a) | 'N'(4e) |         S-BOX      | 2c | 5a | d6 | 2f |
*    -----------------------------------------        ---->       --------------------
*    | 'C'(43) | 'G'(47) | 'K'(4b) | 'O'(4f) |                    | 1a | a0 | b3 | 84 |
*    -----------------------------------------                    --------------------
*    | 'D'(44) | 'H'(48) | 'L'(4c) | 'P'(50) |                    | 1b | 52 | 29 | 53 |
*    -----------------------------------------                    ---------------------
*
*
*/


void test_subBytes(void){
  printf("test_subBytes\n");
  //TEST_IGNORE_MESSAGE("test_subBytes");
  uint8_t in2[] = {0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,0x53};
  uint8_t in[] = "ABCDEFGHIJKLMNOP";
  uint8_t** expState = convInputToState(in2) ;
  uint8_t **state = convInputToState(in);
  //printState(state);
  printBoxState(state);
  subBytes(state);
  printf("            -----S-BOX-----       \n");
  //printState(state);  
  printBoxState(state);
  TEST_ASSERT_EQUAL_STATE(expState,state);
}

/*
*                      state
*     ----------------------------------------                     --------------------
*    | 'A'(41) | 'E'(45) | 'I'(49) | 'M'(4d) |                    | 41 | 45 | 49 | 4d |
*     ----------------------------------------                    --------------------
*    | 'B'(42) | 'F'(46) | 'J'(4a) | 'N'(4e) |        shiftRow    | 46 | 4a | 4e | 42 |
*    -----------------------------------------        ---->       --------------------
*    | 'C'(43) | 'G'(47) | 'K'(4b) | 'O'(4f) |                    | 4b | 4f | 43 | 47 |
*    -----------------------------------------                    --------------------
*    | 'D'(44) | 'H'(48) | 'L'(4c) | 'P'(50) |                    | 50 | 44 | 48 | 4c |
*    -----------------------------------------                    ---------------------
*
*
*/

void test_shift_given_ABCDEFGHIJKLMNOP_expected_pass(void){
   printf("            -----shift-----       \n");
  uint8_t in2[] = "AFKPEJODINCHMBGL";
  uint8_t in[] = "ABCDEFGHIJKLMNOP";
  uint8_t** expState = convInputToState(in2) ;
  uint8_t **state = convInputToState(in);
  printBoxState(state);
  shift(0,4,state);
  shift(1,4,state);
  shift(2,4,state);
  shift(3,4,state);
  printBoxState(state);
 TEST_ASSERT_EQUAL_STATE(expState,state);
}

void test_shiftRow_given_ABCDEFGHIJKLMNOP_expected_pass(void){
  printf("            -----shiftRow-----       \n");
  uint8_t in2[] = "AFKPEJODINCHMBGL";
  uint8_t in[] = "ABCDEFGHIJKLMNOP";
  uint8_t** expState = convInputToState(in2) ;
  uint8_t **state = convInputToState(in);
  printBoxState(state);
  shiftRow(state);
  printBoxState(state);
 TEST_ASSERT_EQUAL_STATE(expState,state);
}


void test_mixColumns(void){
  printf("            -----mixColumns-----       \n");
  uint8_t in[] = {0xd4,0xbf,0x5b,0x30,0xe0,0xb4,0x52,0xae,0xb8,0x41,0x11,0xf1,0x1e,0x27,0x98,0xe5};
  uint8_t **state = convInputToState(in);
  printBoxState(state);
  mixColumns(state);
  printBoxState(state);
  
}