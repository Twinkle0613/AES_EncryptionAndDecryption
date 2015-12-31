#include "KeyExpansion.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

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

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((word[0])), (((void *)0)), (_U_UINT)40, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect1)), (_U_SINT)(_UU32)((word[1])), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect2)), (_U_SINT)(_UU32)((word[2])), (((void *)0)), (_U_UINT)42, UNITY_DISPLAY_STYLE_UINT32);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect3)), (_U_SINT)(_UU32)((word[3])), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_UINT32);



}

void test_rotWord_given_0x31323334_and_expected_0x34313233(void){

  printf("No8.0 - rotWord\n");

  uint32_t expect0 = '2' << 24 | '3' << 16 | '4' << 8 | '1' << 0;

  uint32_t temp = '1' << 24 | '2' << 16 | '3' << 8 | '4' << 0;

  temp = rotWord(temp);

  printf("%x %x",expect0,temp);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((temp)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_UINT32);

}



void test_rotWord_given_0x2a6c7605_and_expected_0x6c76052a(void){

  printf("No8.1 - rotWord\n");

  uint32_t expect0 = 0x6c << 24 | 0x76 << 16 | 0x05 << 8 | 0x2a << 0;

  uint32_t temp = 0x2a << 24 | 0x6c << 16 | 0x76 << 8 | 0x05 << 0;

  temp = rotWord(temp);

  printf("%x %x",expect0,temp);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((temp)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_UINT32);

}

void test_rotWord_given_0x7359f67f_and_expected_0x59f67f73(void){

  printf("No8.2 - rotWord\n");

  uint32_t expect0 = 0x59 << 24 | 0xf6 << 16 | 0x7f << 8 | 0x73 << 0;

  uint32_t temp = 0x73 << 24 | 0x59 << 16 | 0xf6 << 8 | 0x7f << 0;

  temp = rotWord(temp);

  printf("%x %x",expect0,temp);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((temp)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_UINT32);

}

void test_subWord_given_0xcf4f3c09_expected_0x8a84eb01(void){

  printf("No9.0 - subWord\n");

  uint32_t expect0 = 0x8a << 24 | 0x84 << 16 | 0xeb << 8 | 0x01 << 0;

  uint32_t temp = 0xcf << 24 | 0x4f << 16 | 0x3c << 8 | 0x09 << 0;

  temp = subWord(temp);

  printf("%x %x",expect0,temp);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((temp)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_UINT32);

}

void test_subWord_given_0x6c76052a_expected_0x50386be5(void){

  printf("No9.1 - subWord\n");

  uint32_t expect0 = 0x50 << 24 | 0x38 << 16 | 0x6b << 8 | 0xe5 << 0;

  uint32_t temp = 0x6c << 24 | 0x76 << 16 | 0x05 << 8 | 0x2a << 0;

  temp = subWord(temp);

  printf("%x %x",expect0,temp);

  UnityAssertEqualNumber((_U_SINT)(_UU32)((expect0)), (_U_SINT)(_UU32)((temp)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_UINT32);

}
