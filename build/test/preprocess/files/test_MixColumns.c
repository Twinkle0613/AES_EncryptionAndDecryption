#include "CustomAssertion.h"
#include "MixColumns.h"
#include "unity.h"
void setUp(void)

{

}



void tearDown(void)

{

}



void test_mixColumns_given_state2_and_expected_equal_exState(void){

  printf("No4.1\n");

  uint8_t state2[4][4] = { {0xac,0xef,0x13,0x45},

                          {0xc1,0xb5,0x23,0x73},

                          {0xd6,0x5a,0xcf,0x11},

                          {0xb8,0x7b,0xdf,0xb5} };

  uint8_t exState[4][4] = {{0x75,0x20,0x53,0xbb},

                           {0xec,0x0b,0xc0,0x25},

                           {0x09,0x63,0xcf,0xd0},

                           {0x93,0x33,0x7c,0xdc} };



    mixColumns(state2);

    { customTestAssertEqualState(exState,state2,24); };

}



void test_mixColumns_given_state3_and_expected_equal_exState(void){

  printf("No4.2\n");

  uint8_t state3[4][4] = { {0x87,0xf2,0x4d,0x97},

                          {0x6e,0x4c,0x90,0xec},

                          {0x46,0xe7,0x4a,0xc3},

                          {0xa6,0x8c,0xd8,0x95} };

  uint8_t exState[4][4] = {{0x47,0x40,0xa3,0x4c},

                           {0x37,0xd4,0x70,0x9f},

                           {0x94,0xe4,0x3a,0x42},

                           {0xed,0xa5,0xa6,0xbc} };



    mixColumns(state3);

    { customTestAssertEqualState(exState,state3,39); };



}
