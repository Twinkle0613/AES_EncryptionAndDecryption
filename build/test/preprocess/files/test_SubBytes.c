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

  printf("No1.0 - subBytes\n");

  uint8_t exState[4][4] = {{0x83,0x6e,0x3b,0xe3},

                           {0x2c,0x5a,0xd6,0x2f},

                           {0x1a,0xa0,0xb3,0x84},

                           {0x1b,0x52,0x29,0x53} };

  char* str = "ABCDEFGHIJKLMNOP";

  uint8_t state[4][4];

  convStrToState(str,state);

  subBytes(state);



  { customTestAssertEqualState(exState,state,33); };



}

void test_invSubBytes_given_ABCDEFGHIJK(void){

  printf("No2.0 - invSubBytes\n");

   uint8_t exState[4][4] = {{0xf8,0x68,0xa4,0x65},

                           {0xf6,0x98,0x5c,0xb6},

                           {0x64,0x16,0xcc,0x92},

                           {0x86,0xd4,0x5d,0x6c} };

  char* str = "ABCDEFGHIJKLMNOP";

  uint8_t state[4][4];

  convStrToState(str,state);



  printf("\n");

  invSubBytes(state);



  { customTestAssertEqualState(exState,state,60); };

}
