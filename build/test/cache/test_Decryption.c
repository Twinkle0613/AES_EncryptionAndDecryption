#include "SubBytes.h"
#include "ShiftRows.h"
#include "MixColumns.h"
#include "KeyExpansion.h"
#include "AddRoundKey.h"
#include "CustomAssertion.h"
#include "Encryption.h"
#include "Decryption.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_invCipher_given_128_bit_chiper_key(void){

   printf("No1.0 - cipher 128-bit key Size \n");

  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };

  uint8_t expOut[4][4] = { {0x69,0x6a,0xd8,0x70},

                            {0xc4,0x7b,0xcd,0xb4},

                            {0xe0,0x04,0xb7,0xc5},

                            {0xd8,0x30,0x80,0x5a} };

  uint8_t cipcherkey[] = { 0x00,0x01,0x02,0x03,

                           0x04,0x05,0x06,0x07,

                           0x08,0x09,0x0a,0x0b,

                           0x0c,0x0d,0x0e,0x0f };

  uint32_t word[44];

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];

  keyExpansion(cipcherkey,word,4,10);

  cipher(plainText,encrypOut,word,10);

  { customTestAssertEqualState(expOut,encrypOut,35); };

  invCipher(encrypOut,decrypOut,word,10);

  printf("\n");

  printfState(decrypOut);

  { customTestAssertEqualState(plainText,decrypOut,39); };

}



void test_invCipher_given_192_bit_chiper_key(void){

   printf("No2.0 - cipher 192-bit key Size \n");

  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };

  uint8_t expOut[4][4] = { {0xdd,0x86,0x6e,0xec},

                           {0xa9,0x4c,0xaf,0x0d},

                           {0x7c,0xdf,0x70,0x71},

                           {0xa4,0xe0,0xa0,0x91} };

  uint8_t cipcherkey[] = {0x00,0x01,0x02,0x03,

                          0x04,0x05,0x06,0x07,

                          0x08,0x09,0x0a,0x0b,

                          0x0c,0x0d,0x0e,0x0f,

                          0x10,0x11,0x12,0x13,

                          0x14,0x15,0x16,0x17};

  uint32_t word[52];

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];

  keyExpansion(cipcherkey,word,6,12);

  cipher(plainText,encrypOut,word,12);

  { customTestAssertEqualState(expOut,encrypOut,63); };

  invCipher(encrypOut,decrypOut,word,12);

  printf("\n");

  printfState(decrypOut);

  { customTestAssertEqualState(plainText,decrypOut,67); };

}



void test_invCipher_given_256_bit_chiper_key(void){

   printf("No3.0 - cipher 256-bit key Size \n");

  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };

  uint8_t expOut[4][4] = { {0x8e,0x51,0xea,0x4b},

                           {0xa2,0x67,0xfc,0x49},

                           {0xb7,0x45,0x49,0x60},

                           {0xca,0xbf,0x90,0x89} };

uint8_t cipcherkey[] = {0x00,0x01,0x02,0x03,

                        0x04,0x05,0x06,0x07,

                        0x08,0x09,0x0a,0x0b,

                        0x0c,0x0d,0x0e,0x0f,

                        0x10,0x11,0x12,0x13,

                        0x14,0x15,0x16,0x17,

                        0x18,0x19,0x1a,0x1b,

                        0x1c,0x1d,0x1e,0x1f};

  uint32_t word[60];

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];

  keyExpansion(cipcherkey,word,8,14);

  cipher(plainText,encrypOut,word,14);

  { customTestAssertEqualState(expOut,encrypOut,93); };

  invCipher(encrypOut,decrypOut,word,14);

  printf("\n");

  printfState(decrypOut);

  { customTestAssertEqualState(plainText,decrypOut,97); };

}



void test_decryption_16byte_(void){

  printf("No4.0 - decryption_16byte \n");

    uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };

  uint8_t cipcherkey[] = { 0x00,0x01,0x02,0x03,

                           0x04,0x05,0x06,0x07,

                           0x08,0x09,0x0a,0x0b,

                           0x0c,0x0d,0x0e,0x0f };

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];



  encryption_16byte(plainText,cipcherkey,encrypOut);

  decryption_16byte(encrypOut,cipcherkey,decrypOut);

  { customTestAssertEqualState(plainText,decrypOut,115); };

}



void test_decryption_16byte_given_str_(void){

  printf("No5.0 - decryption_16byte \n");

  char *outString = malloc(sizeof(char)*17);

  uint8_t plainText[4][4];

  convStrToState("Hello,HwaNeng!!!",plainText);

  uint8_t cipcherkey[] = { 0x00,0x01,0x02,0x03,

                           0x04,0x05,0x06,0x07,

                           0x08,0x09,0x0a,0x0b,

                           0x0c,0x0d,0x0e,0x0f };

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];



  encryption_16byte(plainText,cipcherkey,encrypOut);

  printfState(encrypOut);

  printf("\n");

  decryption_16byte(encrypOut,cipcherkey,decrypOut);

  printfState(decrypOut);

  convStateToStr(decrypOut,outString);

  printf("%s",outString);



  { customTestAssertEqualState(plainText,decrypOut,138); };

}
