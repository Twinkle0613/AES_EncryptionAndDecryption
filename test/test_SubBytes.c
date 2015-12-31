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
  printf("No2.0 - subBytes\n");
  uint8_t exState[4][4] = {{0x83,0x6e,0x3b,0xe3},    \
                           {0x2c,0x5a,0xd6,0x2f},    \
                           {0x1a,0xa0,0xb3,0x84},    \
                           {0x1b,0x52,0x29,0x53} };  
  char* str = "ABCDEFGHIJKLMNOP";
  uint8_t state[4][4];
  convStrToState(str,state);
  subBytes(state);
  printfState(state);
  TEST_ASSERT_EQUAL_STATE(exState,state);
  
}