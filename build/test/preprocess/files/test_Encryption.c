#include "CustomAssertion.h"
#include "Encryption.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}



void test_convStrToState_(void){

  printf("No.1 - convStrToState\n");

  char* str = "ABCDEFGHIJKLMNOP";

  uint8_t state[4][4];

  convStrToState(str,state);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('A')), (_U_SINT)(_UU8 )((state[0][0])), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('B')), (_U_SINT)(_UU8 )((state[1][0])), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('C')), (_U_SINT)(_UU8 )((state[2][0])), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('D')), (_U_SINT)(_UU8 )((state[3][0])), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('E')), (_U_SINT)(_UU8 )((state[0][1])), (((void *)0)), (_U_UINT)22, UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('P')), (_U_SINT)(_UU8 )((state[3][3])), (((void *)0)), (_U_UINT)23, UNITY_DISPLAY_STYLE_UINT8);

  printfState(state);

}



void test_subBytes_given_ABCDEFGHIJKLMNOP(void){

  printf("No.2 - subBytes\n");

  uint8_t exState[4][4] = {{0x83,0x6e,0x3b,0xe3},

                           {0x2c,0x5a,0xd6,0x2f},

                           {0x1a,0xa0,0xb3,0x84},

                           {0x1b,0x52,0x29,0x53} };

  char* str = "ABCDEFGHIJKLMNOP";

  uint8_t state[4][4];

  convStrToState(str,state);

  subBytes(state);

  printfState(state);

  { customTestAssertEqualState(exState,state,38); };



}



void test_mixColumns_in(void){

  printf("No3 - mixColumns\n");

  uint8_t state[4][4] = { {0xd4,0xe0,0xb8,0x1e},

                          {0xbf,0xb4,0x41,0x27},

                          {0x5d,0x52,0x11,0x98},

                          {0x30,0xae,0xf1,0xe5} };



  uint8_t exState[4][4] = {{0x04,0xe0,0x48,0x28},

                           {0x66,0xcb,0xf8,0x06},

                           {0x81,0x19,0xd3,0x26},

                           {0xe5,0x9a,0x7a,0x4c} };

  printfState(state);

  printf("\n");

  mixColumns(state);

  printfState(state);

  { customTestAssertEqualState(exState,state,57); };



}





void test_add(void){



  uint32_t word[4] = {0x09c4f43c,0xFFaabbcc,0x12345678,0x33225566};



  uint8_t key[4][4];

  int row,col,shift;

  for( col = 0; col < 4 ; col++ ){

    shift = 0;

    for( row = 3 ; row >= 0 ; row--){

      key[row][col] = (word[col] >> shift) & 0x000000FF;

      shift = shift + 8;

    }

  }

  printfState(key);

}
