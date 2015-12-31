#include "CustomAssertion.h"
#include "SubBytes.h"
#include "unity.h"
void setUp(void)

{

}



void tearDown(void)

{

}

void test_subBytes_given_ABCDEFGHIJKLMNOP(void){

  printf("No2.0 - subBytes\n");

  uint8_t exState[4][4] = {{0x83,0x6e,0x3b,0xe3},

                           {0x2c,0x5a,0xd6,0x2f},

                           {0x1a,0xa0,0xb3,0x84},

                           {0x1b,0x52,0x29,0x53} };

  char* str = "ABCDEFGHIJKLMNOP";

  uint8_t state[4][4];

  convStrToState(str,state);

  subBytes(state);

  printfState(state);

  { customTestAssertEqualState(exState,state,33); };



}
