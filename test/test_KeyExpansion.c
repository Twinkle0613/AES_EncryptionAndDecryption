#include "unity.h"
#include "KeyExpansion.h"
#include "malloc.h"
void setUp(void)
{
}

void tearDown(void)
{
}

/*   
                                          
                                            ---------
                                     word1 | 0x1234 |
                                           ---------
                                     word2 | 0x5678 |
   *key = "123456789ABCDEFG"   --->        ---------
                                     word3 | 0x9ABC |
                                           ---------
                                     word4 | 0xDEFG |
                                            ---------
*/
void test_convKeyToWord_given_key_123456789ABCDEFG(void){
  printf("No1.0 - convKeyToWord\n");
  char *key = "123456789ABCDEFG" ;
  int i = 0;
  uint32_t word[4];
  uint32_t expect0 = '1' << 24 | '2' << 16 | '3' << 8 | '4' << 0;
  uint32_t expect1 = '5' << 24 | '6' << 16 | '7' << 8 | '8' << 0;
  uint32_t expect2 = '9' << 24 | 'A' << 16 | 'B' << 8 | 'C' << 0;
  uint32_t expect3 = 'D' << 24 | 'E' << 16 | 'F' << 8 | 'G' << 0;
  //printf("%x ",expect);
  while( i < 4){
  word[i] = convKeyToWord(key[4*i],key[4*i+1],key[4*i+2],key[4*i+3]);
  printf("%x ",word[i]);
  i++;
  }
  TEST_ASSERT_EQUAL_UINT32(expect0,word[0]);
  TEST_ASSERT_EQUAL_UINT32(expect1,word[1]);
  TEST_ASSERT_EQUAL_UINT32(expect2,word[2]);
  TEST_ASSERT_EQUAL_UINT32(expect3,word[3]);
  
}

/*
       -----                -----
  --->| 31 |               | 34 |
  |   -----                -----
  |   | 32 |     rotWord   | 31 |
  |   -----     ------>    -----
  |   | 33 |               | 32 |
  |   -----                -----
  ----| 34 |               | 33 |
      -----                -----
  
*/
void test_rotWord_given_0x31323334_and_expected_0x34313233(void){
  printf("No2.0 - rotWord\n");
  uint32_t expect0 = '2' << 24 | '3' << 16 | '4' << 8 | '1' << 0;
  uint32_t temp = '1' << 24 | '2' << 16 | '3' << 8 | '4' << 0;
  temp = rotWord(temp);
  printf("%x %x",expect0,temp);
  TEST_ASSERT_EQUAL_UINT32(expect0,temp); 
}

void test_rotWord_given_0x2a6c7605_and_expected_0x6c76052a(void){
  printf("No3.0 - rotWord\n");
  uint32_t expect0 = 0x6c << 24 | 0x76 << 16 | 0x05 << 8 | 0x2a << 0;
  uint32_t temp = 0x2a << 24 | 0x6c << 16 | 0x76 << 8 | 0x05 << 0;
  temp = rotWord(temp);
  printf("%x %x",expect0,temp);
  TEST_ASSERT_EQUAL_UINT32(expect0,temp); 
}
void test_rotWord_given_0x7359f67f_and_expected_0x59f67f73(void){
  printf("No4.0 - rotWord\n");
  uint32_t expect0 = 0x59 << 24 | 0xf6 << 16 | 0x7f << 8 | 0x73 << 0;
  uint32_t temp = 0x73 << 24 | 0x59 << 16 | 0xf6 << 8 | 0x7f << 0;
  temp = rotWord(temp);
  printf("%x %x",expect0,temp);
  TEST_ASSERT_EQUAL_UINT32(expect0,temp); 
}

/*
       -----                -----
      | cf |               | 8a |
      -----      (S-BOX)   -----
      | 4f |     subWord   | 84 |
      -----     ------>    -----
      | 3c |               | eb |
      -----                -----
      | 09 |               | 01 |
      -----                -----
  
*/

void test_subWord_given_0xcf4f3c09_expected_0x8a84eb01(void){
  printf("No5.0 - subWord\n");
  uint32_t expect0 = 0x8a << 24 | 0x84 << 16 | 0xeb << 8 | 0x01 << 0;
  uint32_t temp = 0xcf << 24 | 0x4f << 16 | 0x3c << 8 | 0x09 << 0;  
  temp = subWord(temp);
  printf("%x %x",expect0,temp);
  TEST_ASSERT_EQUAL_UINT32(expect0,temp); 
}
void test_subWord_given_0x6c76052a_expected_0x50386be5(void){
  printf("No6.0 - subWord\n");
  uint32_t expect0 = 0x50 << 24 | 0x38 << 16 | 0x6b << 8 | 0xe5 << 0;
  uint32_t temp = 0x6c << 24 | 0x76 << 16 | 0x05 << 8 | 0x2a << 0;  
  temp = subWord(temp);
  printf("%x %x",expect0,temp);
  TEST_ASSERT_EQUAL_UINT32(expect0,temp); 
}

void test_keyExpansion_given_128_bit_cipher_key(void){
 printf("No7.0 - keyExpansion 128-bit cipher key\n");
  int i = 0;
  char* key = malloc(sizeof(char)*17);
  uint8_t cipcherkey[] = { 0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};
  for(i = 0; i < 16 ; i++){
    key[i] = cipcherkey[i];
  }
  //printf("key = %.*x\n",8,key[i]);
  uint32_t word[44];
  keyExpansion(key,word,4,10);
  TEST_ASSERT_EQUAL_UINT32(0xb6630ca6,word[43]); 
  TEST_ASSERT_EQUAL_UINT32(0xac7766f3,word[36]); 
  TEST_ASSERT_EQUAL_UINT32(0x110b3efd,word[25]); 
}


void test_keyExpansion_given_192_bit_cipher_key(void){
 printf("No8.0 - keyExpansion 192-bit cipher key\n");
  int i = 0;
  char* key = malloc(sizeof(char)*25);
  uint8_t cipcherkey[] = { 0x8e,0x73,0xb0,0xf7,0xda,0x0e,0x64,0x52,0xc8,0x10,0xf3,0x2b,\
                           0x80,0x90,0x79,0xe5,0x62,0xf8,0xea,0xd2,0x52,0x2c,0x6b,0x7b};
  for(i = 0; i < 24 ; i++){
    key[i] = cipcherkey[i];
  }
  uint32_t word[52];
  keyExpansion(key,word,6,12);
  TEST_ASSERT_EQUAL_UINT32(0xad07d753,word[43]); 
  
}

void test_keyExpansion_given_256_bit_cipher_key(void){
 printf("No9.0 - keyExpansion 256-bit cipher key\n");
  int i = 0;
  char* key = malloc(sizeof(char)*33);
  uint8_t cipcherkey[] = { 0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,\
                           0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,\
                           0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4};
  for(i = 0; i < 32 ; i++){
    key[i] = cipcherkey[i];
  }
  uint32_t word[60];
  keyExpansion(key,word,8,14);
  TEST_ASSERT_EQUAL_UINT32(0x9ba35411,word[8]); 
  TEST_ASSERT_EQUAL_UINT32(0x98312229,word[22]); 
  TEST_ASSERT_EQUAL_UINT32(0xde136967,word[40]); 
  TEST_ASSERT_EQUAL_UINT32(0x706c631e,word[59]); 
}