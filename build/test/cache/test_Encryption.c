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

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0xb6630ca6)), (_U_SINT)(_UU32)((word[43])), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0xac7766f3)), (_U_SINT)(_UU32)((word[36])), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0x110b3efd)), (_U_SINT)(_UU32)((word[25])), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_UINT32);

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

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0xad07d753)), (_U_SINT)(_UU32)((word[43])), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_UINT32);



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

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0x9ba35411)), (_U_SINT)(_UU32)((word[8])), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0x98312229)), (_U_SINT)(_UU32)((word[22])), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0xde136967)), (_U_SINT)(_UU32)((word[40])), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((0x706c631e)), (_U_SINT)(_UU32)((word[59])), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_UINT32);

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

  { customTestAssertEqualState(expOut,out,87); };

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

  { customTestAssertEqualState(expOut,out,108); };

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

  { customTestAssertEqualState(expOut,out,129); };

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

  { customTestAssertEqualState(expOut,out,146); };

}
