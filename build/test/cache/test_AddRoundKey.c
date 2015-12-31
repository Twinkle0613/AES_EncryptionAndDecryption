#include "SubBytes.h"
#include "CustomAssertion.h"
#include "AddRoundKey.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}

void test_addRoundKey_given_state_and_cipherKey_expected_equal_exState(void){

  printf("No1.0 - addRoundKey\n");

  uint8_t exState[4][4] = { {0x19,0xa0,0x9a,0xe9},

                            {0x3d,0xf4,0xc6,0xf8},

                            {0xe3,0xe2,0x8d,0x48},

                            {0xbe,0x2b,0x2a,0x08} };



  uint8_t state[4][4] = { {0x32,0x88,0x31,0xe0},

                           {0x43,0x5a,0x31,0x37},

                           {0xf6,0x30,0x98,0x07},

                           {0xa8,0x8d,0xa2,0x34} };

  uint32_t cipherKey[4] = {0x2b7e1516,0x28aed2a6,0xabf71588,0x09cf4f3c};

  addRoundKey(state,cipherKey,3);

  printfState(state);

   { customTestAssertEqualState(exState,state,41); };



}



void test_addRoundKey_given_state1_and_cipherKey1_expected_equal_exState(void){

  printf("No2.0 - addRoundKey\n");

  uint8_t exState[4][4] = { {0x48,0x67,0x4d,0xd6},

                            {0x6c,0x1d,0xe3,0x5f},

                            {0x4e,0x9d,0xb1,0x58},

                            {0xee,0x0d,0x38,0xe7} };



  uint8_t state[4][4] = { {0x75,0x20,0x53,0xbb},

                           {0xec,0x0b,0xc0,0x25},

                           {0x09,0x63,0xcf,0xd0},

                           {0x93,0x33,0x7c,0xdc} };

  uint32_t cipherKey[4] = {0x3d80477d,0x4716fe3e,0x1e237e44,0x6d7a883b};

  addRoundKey(state,cipherKey,3);

  printfState(state);

   { customTestAssertEqualState(exState,state,59); };



}



void test_addRoundKey_given_state2_and_cipherKey_expected_equal_exState(void){

  printf("No3.0 - addRoundKey\n");

  uint8_t exState[4][4] = { {0x11,0x11,0x11,0x11},

                            {0x11,0x11,0x11,0x11},

                            {0x11,0x11,0x11,0x11},

                            {0x11,0x11,0x11,0x11} };



  uint8_t state[4][4] = { {0x00,0x00,0x00,0x00},

                          {0x00,0x00,0x00,0x00},

                          {0x00,0x00,0x00,0x00},

                          {0x00,0x00,0x00,0x00} };

  uint32_t cipherKey[4] = {0x11111111,0x11111111,0x11111111,0x11111111};

  addRoundKey(state,cipherKey,3);

  printfState(state);

   { customTestAssertEqualState(exState,state,77); };



}
