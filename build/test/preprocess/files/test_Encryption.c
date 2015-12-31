#include "SubBytes.h"
#include "ShiftRows.h"
#include "MixColumns.h"
#include "KeyExpansion.h"
#include "AddRoundKey.h"
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

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('A')), (_U_SINT)(_UU8 )((state[0][0])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('B')), (_U_SINT)(_UU8 )((state[1][0])), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('C')), (_U_SINT)(_UU8 )((state[2][0])), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('D')), (_U_SINT)(_UU8 )((state[3][0])), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('E')), (_U_SINT)(_UU8 )((state[0][1])), (((void *)0)), (_U_UINT)30, UNITY_DISPLAY_STYLE_UINT8);

  UnityAssertEqualNumber((_U_SINT)(_UU8 )(('P')), (_U_SINT)(_UU8 )((state[3][3])), (((void *)0)), (_U_UINT)31, UNITY_DISPLAY_STYLE_UINT8);

  printfState(state);

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

  { customTestAssertEqualState(exState,state,55); };



}

void test_shift_given_ABCDEFGHIJKLMNOP_expected_equal_exState(void){

  printf("No3.0 - shift\n");

  uint8_t expStr[] = "AFKPEJODINCHMBGL";

  uint8_t str[] = "ABCDEFGHIJKLMNOP";

  uint8_t exState[4][4];

  uint8_t state[4][4];

  convStrToState(str,state);

  convStrToState(expStr,exState);

  printfState(state);

  shift(0,4,state);

  shift(1,4,state);

  shift(2,4,state);

  shift(3,4,state);

  printf("\n");

  printfState(state);

 { customTestAssertEqualState(exState,state,84); };

}

void test_shiftRow_given_ABCDEFGHIJKLMNOP_expected_equal_exState(void){

  printf("No3.1 - shiftRow\n");

  uint8_t expStr[] = "AFKPEJODINCHMBGL";

  uint8_t str[] = "ABCDEFGHIJKLMNOP";

  uint8_t exState[4][4];

  uint8_t state[4][4];

  convStrToState(str,state);

  convStrToState(expStr,exState);

  printfState(state);

  shiftRow(state);

  printf("\n");

  printfState(state);

 { customTestAssertEqualState(exState,state,108); };

}



void test_shiftRow_given_state_and_expected_euqal_exState(void){

  printf("No3.2 - shiftRow\n");



    uint8_t state[4][4] = { {'1','2','3','4'},

                            {'5','6','7','8'},

                            {'9','A','B','C'},

                            {'D','E','F','G'} };

  uint8_t exState[4][4] = {{'1','2','3','4'},

                           {'6','7','8','5'},

                           {'B','C','9','A'},

                           {'G','D','E','F'} };

  printfState(state);

  shiftRow(state);

  printf("\n");

  printfState(state);

  { customTestAssertEqualState(exState,state,126); };



}

void test_mixColumns_given_state_and_expected_equal_exState(void){

  printf("No4.0 - mixColumns\n");

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

  { customTestAssertEqualState(exState,state,153); };

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

    { customTestAssertEqualState(exState,state2,167); };

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

    { customTestAssertEqualState(exState,state3,182); };



}



void test_convWordToArr_given_word_that_contain_4_array_data(void){

  printf("No5.0 - convWordToArr\n");

  uint32_t word[4] = {0x09c4f43c,0xFFaabbcc,0x12345678,0x33225566};



    uint8_t exState[4][4] = { {0x09,0xFF,0x12,0x33},

                              {0xc4,0xaa,0x34,0x22},

                              {0xf4,0xbb,0x56,0x55},

                              {0x3c,0xcc,0x78,0x66} };

  uint8_t key[4][4];



  convWordToArr(key,word,3);

  printfState(key);

  { customTestAssertEqualState(exState,key,198); };

}



void test_convWordToArr_given_word_that_contain_8_array_data(void){

  printf("No5.1 - convWordToArr\n");

  uint32_t word[8] = {0x09c4f43c,0xFFaabbcc,0x12345678,0x33225566,

                      0x77889900,0x22334455,0xeeffaabb,0x88997766};



    uint8_t exState[4][4] = { {0x77,0x22,0xee,0x88},

                              {0x88,0x33,0xff,0x99},

                              {0x99,0x44,0xaa,0x77},

                              {0x00,0x55,0xbb,0x66} };

  uint8_t key[4][4];



  convWordToArr(key,word,7);

  printfState(key);

  { customTestAssertEqualState(exState,key,214); };

}

void test_convWordToArr_given_word_that_contain_16_array_data(void){

  printf("No5.2 - convWordToArr\n");

  uint32_t word[12] = {0x09c4f43c,0xFFaabbcc,0x12345678,0x33225566,

                      0x77889900,0x22334455,0xeeffaabb,0x88997766,

                      0x88223311,0x99002211,0x66556655,0x11223344};



    uint8_t exState[4][4] = { {0x88,0x99,0x66,0x11},

                              {0x22,0x00,0x55,0x22},

                              {0x33,0x22,0x66,0x33},

                              {0x11,0x11,0x55,0x44} };

  uint8_t key[4][4];



  convWordToArr(key,word,11);

  printfState(key);

  { customTestAssertEqualState(exState,key,230); };

}

void test_addRoundKey_given_state_and_cipherKey_expected_equal_exState(void){

  printf("No6.0 - addRoundKey\n");

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

   { customTestAssertEqualState(exState,state,263); };



}



void test_addRoundKey_given_state1_and_cipherKey1_expected_equal_exState(void){

  printf("No6.1 - addRoundKey\n");

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

   { customTestAssertEqualState(exState,state,281); };



}



void test_addRoundKey_given_state2_and_cipherKey_expected_equal_exState(void){

  printf("No6.2 - addRoundKey\n");

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

   { customTestAssertEqualState(exState,state,299); };



}

void test_convKeyToWord_(void){

  printf("No7.0 - convKeyToWord\n");

  char *key = "123456789ABCDEFG" ;

  int i = 0;

  uint32_t word[4];

  uint32_t expect0 = '1' << 24 | '2' << 16 | '3' << 8 | '4' << 0;

  uint32_t expect1 = '5' << 24 | '6' << 16 | '7' << 8 | '8' << 0;

  uint32_t expect2 = '9' << 24 | 'A' << 16 | 'B' << 8 | 'C' << 0;

  uint32_t expect3 = 'D' << 24 | 'E' << 16 | 'F' << 8 | 'G' << 0;



  while( i < 4){

  word[i] = convKeyToWord(key[4*i],key[4*i+1],key[4*i+2],key[4*i+3]);

  printf("%x ",word[i]);

  i++;

  }

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((word[0])), (((void *)0)), (_U_UINT)330, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect1)), (_U_SINT)(_UU32)((word[1])), (((void *)0)), (_U_UINT)331, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect2)), (_U_SINT)(_UU32)((word[2])), (((void *)0)), (_U_UINT)332, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect3)), (_U_SINT)(_UU32)((word[3])), (((void *)0)), (_U_UINT)333, UNITY_DISPLAY_STYLE_UINT32);



}

void test_rotWord_given_0x31323334_and_expected_0x34313233(void){

  printf("No8.0 - rotWord\n");

  uint32_t expect0 = '2' << 24 | '3' << 16 | '4' << 8 | '1' << 0;

  uint32_t temp = '1' << 24 | '2' << 16 | '3' << 8 | '4' << 0;

  temp = rotWord(temp);

  printf("%x %x",expect0,temp);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((temp)), (((void *)0)), (_U_UINT)355, UNITY_DISPLAY_STYLE_UINT32);

}



void test_rotWord_given_0x2a6c7605_and_expected_0x6c76052a(void){

  printf("No8.1 - rotWord\n");

  uint32_t expect0 = 0x6c << 24 | 0x76 << 16 | 0x05 << 8 | 0x2a << 0;

  uint32_t temp = 0x2a << 24 | 0x6c << 16 | 0x76 << 8 | 0x05 << 0;

  temp = rotWord(temp);

  printf("%x %x",expect0,temp);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((temp)), (((void *)0)), (_U_UINT)364, UNITY_DISPLAY_STYLE_UINT32);

}

void test_rotWord_given_0x7359f67f_and_expected_0x59f67f73(void){

  printf("No8.2 - rotWord\n");

  uint32_t expect0 = 0x59 << 24 | 0xf6 << 16 | 0x7f << 8 | 0x73 << 0;

  uint32_t temp = 0x73 << 24 | 0x59 << 16 | 0xf6 << 8 | 0x7f << 0;

  temp = rotWord(temp);

  printf("%x %x",expect0,temp);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((temp)), (((void *)0)), (_U_UINT)372, UNITY_DISPLAY_STYLE_UINT32);

}

void test_subWord_given_0xcf4f3c09_expected_0x8a84eb01(void){

  printf("No9.0 - subWord\n");

  uint32_t expect0 = 0x8a << 24 | 0x84 << 16 | 0xeb << 8 | 0x01 << 0;

  uint32_t temp = 0xcf << 24 | 0x4f << 16 | 0x3c << 8 | 0x09 << 0;

  temp = subWord(temp);

  printf("%x %x",expect0,temp);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((temp)), (((void *)0)), (_U_UINT)394, UNITY_DISPLAY_STYLE_UINT32);

}

void test_subWord_given_0x6c76052a_expected_0x50386be5(void){

  printf("No9.1 - subWord\n");

  uint32_t expect0 = 0x50 << 24 | 0x38 << 16 | 0x6b << 8 | 0xe5 << 0;

  uint32_t temp = 0x6c << 24 | 0x76 << 16 | 0x05 << 8 | 0x2a << 0;

  temp = subWord(temp);

  printf("%x %x",expect0,temp);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((temp)), (((void *)0)), (_U_UINT)402, UNITY_DISPLAY_STYLE_UINT32);

}





void test_keyExpansion_given_128_bit_cipher_key(void){

 printf("No10.0 - keyExpansion 128-bit cipher key\n");

  int i = 0;

  char* key = malloc(sizeof(char)*17);

  uint8_t cipcherkey[] = { 0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};

  for(i = 0; i < 16 ; i++){

    key[i] = cipcherkey[i];

  }



  uint32_t word[44];

  keyExpansion(key,word,4,10);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0xb6630ca6)), (_U_SINT)(_UU32)((word[43])), (((void *)0)), (_U_UINT)417, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0xac7766f3)), (_U_SINT)(_UU32)((word[36])), (((void *)0)), (_U_UINT)418, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0x110b3efd)), (_U_SINT)(_UU32)((word[25])), (((void *)0)), (_U_UINT)419, UNITY_DISPLAY_STYLE_UINT32);

}





void test_keyExpansion_given_192_bit_cipher_key(void){

 printf("No10.1 - keyExpansion 192-bit cipher key\n");

  int i = 0;

  char* key = malloc(sizeof(char)*25);

  uint8_t cipcherkey[] = { 0x8e,0x73,0xb0,0xf7,0xda,0x0e,0x64,0x52,0xc8,0x10,0xf3,0x2b,

                           0x80,0x90,0x79,0xe5,0x62,0xf8,0xea,0xd2,0x52,0x2c,0x6b,0x7b};

  for(i = 0; i < 24 ; i++){

    key[i] = cipcherkey[i];

  }

  uint32_t word[52];

  keyExpansion(key,word,6,12);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0xad07d753)), (_U_SINT)(_UU32)((word[43])), (((void *)0)), (_U_UINT)434, UNITY_DISPLAY_STYLE_UINT32);



}



void test_keyExpansion_given_256_bit_cipher_key(void){

 printf("No10.2 - keyExpansion 256-bit cipher key\n");

  int i = 0;

  char* key = malloc(sizeof(char)*33);

  uint8_t cipcherkey[] = { 0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,

                           0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,

                           0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4};

  for(i = 0; i < 32 ; i++){

    key[i] = cipcherkey[i];

  }

  uint32_t word[60];

  keyExpansion(key,word,8,14);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0x9ba35411)), (_U_SINT)(_UU32)((word[8])), (((void *)0)), (_U_UINT)450, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0x98312229)), (_U_SINT)(_UU32)((word[22])), (((void *)0)), (_U_UINT)451, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0xde136967)), (_U_SINT)(_UU32)((word[40])), (((void *)0)), (_U_UINT)452, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0x706c631e)), (_U_SINT)(_UU32)((word[59])), (((void *)0)), (_U_UINT)453, UNITY_DISPLAY_STYLE_UINT32);

}



void test_cipher_given_128_bit_cipher_key(void){

  printf("No11.0 - cipher 128-bit key Size \n");

  uint8_t in[4][4] = { {0x32,0x88,0x31,0xe0},

                           {0x43,0x5a,0x31,0x37},

                           {0xf6,0x30,0x98,0x07},

                           {0xa8,0x8d,0xa2,0x34} };

  uint8_t expOut[4][4] = { {0x39,0x02,0xdc,0x19},

                            {0x25,0xdc,0x11,0x6a},

                            {0x84,0x09,0x85,0x0b},

                            {0x1d,0xfb,0x97,0x32} };

  uint8_t out[4][4];

  uint32_t word[44];

  uint8_t cipcherkey[] = { 0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};

  keyExpansion(cipcherkey,word,4,10);

  cipher(in,out,word,10);

  printfState(out);

  { customTestAssertEqualState(expOut,out,472); };

}



void test_cipher_given_192_bit_cipher_key(void){

  printf("No11.1 - cipher 192-bit key Size \n");

  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };



  uint8_t expOut[4][4] = { {0xdd,0x86,0x6e,0xec},

                            {0xa9,0x4c,0xaf,0x0d},

                            {0x7c,0xdf,0x70,0x71},

                            {0xa4,0xe0,0xa0,0x91} };

  uint8_t out[4][4];

  uint32_t word[52];

  uint8_t key[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,

                    0x0f,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17};

  keyExpansion(key,word,6,12);

  cipher(plainText,out,word,12);

  printfState(out);

  { customTestAssertEqualState(expOut,out,493); };

}



void test_cipher_given_256_bit_cipher_key(void){

  printf("No11.2 - cipher 256-bit key Size \n");

  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };



  uint8_t expOut[4][4] = { {0x8e,0x51,0xea,0x4b},

                            {0xa2,0x67,0xfc,0x49},

                            {0xb7,0x45,0x49,0x60},

                            {0xca,0xbf,0x90,0x89} };

  uint8_t out[4][4];

  uint32_t word[60];

  uint8_t key[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,

                    0x0e,0x0f,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x1a,0x1b,0x1c,0x1d,0x1e,0x1f};

  keyExpansion(key,word,8,14);

  cipher(plainText,out,word,14);

 printfState(out);

  { customTestAssertEqualState(expOut,out,514); };

}



void test_encryption16byte_(void){

  printf("No12.0 - encryption_16byte\n");

  uint8_t plainText[4][4] = { {0x32,0x88,0x31,0xe0},

                              {0x43,0x5a,0x31,0x37},

                              {0xf6,0x30,0x98,0x07},

                              {0xa8,0x8d,0xa2,0x34} };

  uint8_t expOut[4][4] = { {0x39,0x02,0xdc,0x19},

                            {0x25,0xdc,0x11,0x6a},

                            {0x84,0x09,0x85,0x0b},

                            {0x1d,0xfb,0x97,0x32} };

  uint8_t cipcherkey[] = { 0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};

  uint8_t out[4][4];

  encryption_16byte(plainText,cipcherkey,out);

  printfState(out);

  { customTestAssertEqualState(expOut,out,531); };

}
