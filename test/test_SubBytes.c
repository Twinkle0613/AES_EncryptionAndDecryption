#include "unity.h"
#include "SubBytes.h"
#include "CustomAssertion.h"
void setUp(void)
{
}

void tearDown(void)
{
}

//*****************subBytes()******************//
/*

  'A'(41) 'E'(45) 'I'(49) 'M'(4d)   S-BOX   83 6e 3b e3
  'B'(42) 'F'(46) 'J'(4a) 'N'(4e)  ----->   2c 5a d6 2f
  'C'(43) 'G'(47) 'K'(4b) 'O'(4f)           1a a0 b3 84
  'D'(44) 'H'(48) 'L'(4c) 'P'(50)           1b 52 29 53

*/

void test_subBytes_given_ABCDEFGHIJKLMNOP(void){
  printf("No1.0 - subBytes\n");
  uint8_t exState[4][4] = {{0x83,0x6e,0x3b,0xe3},    \
                           {0x2c,0x5a,0xd6,0x2f},    \
                           {0x1a,0xa0,0xb3,0x84},    \
                           {0x1b,0x52,0x29,0x53} };  
  char* str = "ABCDEFGHIJKLMNOP";
  uint8_t state[4][4];
  convStrToState(str,state);
  subBytes(state);
 // printfState(state);
  TEST_ASSERT_EQUAL_STATE(exState,state);
  
}

//----------------invSubBytes----------------------

/*

  'A'(41) 'E'(45) 'I'(49) 'M'(4d)   invS-BOX   f8 68 a4 65
  'B'(42) 'F'(46) 'J'(4a) 'N'(4e)  -------->   f6 98 5c b6
  'C'(43) 'G'(47) 'K'(4b) 'O'(4f)              64 16 cc 92
  'D'(44) 'H'(48) 'L'(4c) 'P'(50)              86 d4 5d 6c

*/
void test_invSubBytes_given_ABCDEFGHIJK(void){
  printf("No2.0 - invSubBytes\n");
   uint8_t exState[4][4] = {{0xf8,0x68,0xa4,0x65},    \
                           {0xf6,0x98,0x5c,0xb6},    \
                           {0x64,0x16,0xcc,0x92},    \
                           {0x86,0xd4,0x5d,0x6c} };  
  char* str = "ABCDEFGHIJKLMNOP";
  uint8_t state[4][4];
  convStrToState(str,state);
//  printfState(state);
  printf("\n");
  invSubBytes(state);
//  printfState(state);
  TEST_ASSERT_EQUAL_STATE(exState,state);
}