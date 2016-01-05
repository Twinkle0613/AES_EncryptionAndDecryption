#include "SubBytes.h"
#include "ShiftRows.h"
#include "MixColumns.h"
#include "KeyExpansion.h"
#include "AddRoundKey.h"
#include "CustomAssertion.h"
#include "Decryption.h"
#include "Encryption.h"
#include "unity.h"








void setUp(void)

{

}



void tearDown(void)

{

}







void test_cipher_given_128_bit_cipher_key(void){

  printf("No1.0 - cipher 128-bit key Size \n");

  uint8_t in[4][4] = { {0x32,0x88,0x31,0xe0},

                       {0x43,0x5a,0x31,0x37},

                       {0xf6,0x30,0x98,0x07},

                       {0xa8,0x8d,0xa2,0x34} };

  uint8_t expOut[4][4] = { {0x39,0x02,0xdc,0x19},

                            {0x25,0xdc,0x11,0x6a},

                            {0x84,0x09,0x85,0x0b},

                            {0x1d,0xfb,0x97,0x32} };

  uint8_t cipcherkey[] = {0x2b,0x7e,0x15,0x16,

                          0x28,0xae,0xd2,0xa6,

                          0xab,0xf7,0x15,0x88,

                          0x09,0xcf,0x4f,0x3c};

  uint8_t out[4][4];

  uint32_t word[44];

  keyExpansion(cipcherkey,word,4,10);

  cipher(in,out,word,10);

  printfState(out);

  { customTestAssertEqualState(expOut,out,44); };

}



void test_cipher_given_192_bit_cipher_key(void){

  printf("No2.0 - cipher 192-bit key Size \n");

  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };



  uint8_t expOut[4][4] = { {0xdd,0x86,0x6e,0xec},

                            {0xa9,0x4c,0xaf,0x0d},

                            {0x7c,0xdf,0x70,0x71},

                            {0xa4,0xe0,0xa0,0x91} };

  uint8_t key[] = {0x00,0x01,0x02,0x03,

                   0x04,0x05,0x06,0x07,

                   0x08,0x09,0x0a,0x0b,

                   0x0c,0x0d,0x0e,0x0f,

                   0x10,0x11,0x12,0x13,

                   0x14,0x15,0x16,0x17};



  uint8_t out[4][4];

  uint32_t word[52];

  keyExpansion(key,word,6,12);

  cipher(plainText,out,word,12);

  printfState(out);

  { customTestAssertEqualState(expOut,out,70); };

}



void test_cipher_given_256_bit_cipher_key(void){

  printf("No3.0 - cipher 256-bit key Size \n");

  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };



  uint8_t expOut[4][4] = { {0x8e,0x51,0xea,0x4b},

                            {0xa2,0x67,0xfc,0x49},

                            {0xb7,0x45,0x49,0x60},

                            {0xca,0xbf,0x90,0x89} };

  uint8_t key[] = {0x00,0x01,0x02,0x03,

                   0x04,0x05,0x06,0x07,

                   0x08,0x09,0x0a,0x0b,

                   0x0c,0x0d,0x0e,0x0f,

                   0x10,0x11,0x12,0x13,

                   0x14,0x15,0x16,0x17,

                   0x18,0x19,0x1a,0x1b,

                   0x1c,0x1d,0x1e,0x1f};

  uint8_t out[4][4];

  uint32_t word[60];

  keyExpansion(key,word,8,14);

  cipher(plainText,out,word,14);

  printfState(out);

  { customTestAssertEqualState(expOut,out,97); };

}



void test_encryption16byte_(void){

  printf("No4.0 - encryption_16byte\n");

  uint8_t plainText[4][4] = { {0x32,0x88,0x31,0xe0},

                              {0x43,0x5a,0x31,0x37},

                              {0xf6,0x30,0x98,0x07},

                              {0xa8,0x8d,0xa2,0x34} };

  uint8_t expOut[4][4] = { {0x39,0x02,0xdc,0x19},

                            {0x25,0xdc,0x11,0x6a},

                            {0x84,0x09,0x85,0x0b},

                            {0x1d,0xfb,0x97,0x32} };

  uint8_t cipcherkey[] = { 0x2b,0x7e,0x15,0x16,

                           0x28,0xae,0xd2,0xa6,

                           0xab,0xf7,0x15,0x88,

                           0x09,0xcf,0x4f,0x3c};

  uint8_t out[4][4];

  encryption_16byte(plainText,cipcherkey,out);

  printfState(out);

  { customTestAssertEqualState(expOut,out,117); };

}



void test_encryp_16byte_given_128_bit_cipher_key(void){

  printf("No5.0 - encryp_16byte with 128-bit key\n");

  uint8_t plainText[4][4] = { {0x32,0x88,0x31,0xe0},

                       {0x43,0x5a,0x31,0x37},

                       {0xf6,0x30,0x98,0x07},

                       {0xa8,0x8d,0xa2,0x34} };

  uint8_t expOut[4][4] = { {0x39,0x02,0xdc,0x19},

                            {0x25,0xdc,0x11,0x6a},

                            {0x84,0x09,0x85,0x0b},

                            {0x1d,0xfb,0x97,0x32} };

  uint8_t cipcherkey[] = {0x2b,0x7e,0x15,0x16,

                          0x28,0xae,0xd2,0xa6,

                          0xab,0xf7,0x15,0x88,

                          0x09,0xcf,0x4f,0x3c};

  uint8_t encrypOut[4][4];



  encryp_16byte(plainText,cipcherkey,encrypOut,1);

  { customTestAssertEqualState(expOut,encrypOut,137); };

}



void test_encryp_16byte_given_192_bit_cipher_key(void){

  printf("No6.0 - encryp_16byte with 192-bit key\n");

  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };



  uint8_t expOut[4][4] = { {0xdd,0x86,0x6e,0xec},

                            {0xa9,0x4c,0xaf,0x0d},

                            {0x7c,0xdf,0x70,0x71},

                            {0xa4,0xe0,0xa0,0x91} };

  uint8_t key[] = {0x00,0x01,0x02,0x03,

                   0x04,0x05,0x06,0x07,

                   0x08,0x09,0x0a,0x0b,

                   0x0c,0x0d,0x0e,0x0f,

                   0x10,0x11,0x12,0x13,

                   0x14,0x15,0x16,0x17};

  uint8_t encrypOut[4][4];

  encryp_16byte(plainText,key,encrypOut,2);

  { customTestAssertEqualState(expOut,encrypOut,159); };

}



void test_encryp_16byte_given_256_bit_cipher_key(void){

  printf("No7.0 - encryp_16byte with 256-bit key\n");

  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };



  uint8_t expOut[4][4] = { {0x8e,0x51,0xea,0x4b},

                            {0xa2,0x67,0xfc,0x49},

                            {0xb7,0x45,0x49,0x60},

                            {0xca,0xbf,0x90,0x89} };

  uint8_t key[] = {0x00,0x01,0x02,0x03,

                   0x04,0x05,0x06,0x07,

                   0x08,0x09,0x0a,0x0b,

                   0x0c,0x0d,0x0e,0x0f,

                   0x10,0x11,0x12,0x13,

                   0x14,0x15,0x16,0x17,

                   0x18,0x19,0x1a,0x1b,

                   0x1c,0x1d,0x1e,0x1f};

  uint8_t encrypOut[4][4];

  encryp_16byte(plainText,key,encrypOut,3);

  { customTestAssertEqualState(expOut,encrypOut,183); };

}

void test_strncpy_(void){

  printf("No10.0 - strncpy\n");

  char *str = "Hello,HwaNeng!!!";

  char *str2 = "Hello";

  char* processStr = malloc(sizeof(char)*5);

  int keySize = 5;

  strncpy(processStr,"Hello,HwaNeng!!!",5);

  printf("%s\n",processStr);

  UnityAssertEqualString((const char*)("Hello"), (const char*)(processStr), (((void *)0)), (_U_UINT)201);

}



void test_fillZeroToStr_given(void){

  printf("No11.0 - fillZeroToStr\n");

  char *str = "Hello";

  char* processStr = malloc(sizeof(char)*17);

  strncpy(processStr,str,strlen(str));

  fillZeroToStr(strlen(str),processStr,16);

  printf("%s\n",processStr);

  UnityAssertEqualString((const char*)("Hello00000000000"), (const char*)(processStr), (((void *)0)), (_U_UINT)211);

}



void test_keyProcess_given_a_string_1234567_expected_string_1234567000000000_In_AES128(void){

  printf("No12.0 - keyProcess in AES_128\n");

  char* applyKey;

  char* key = "1234567";

  applyKey = keyProcess(key,16);

  printf("%s\n",applyKey);

  UnityAssertEqualString((const char*)("1234567000000000"), (const char*)(applyKey), (((void *)0)), (_U_UINT)220);

}



void test_keyProcess_given_a_string_0123456789ABCDEF_expected_string_0123456789ABCDEF_In_AES128(void){

  printf("No13.0 - keyProcess in AES_128\n");

  char* applyKey;

  char* key = "0123456789ABCDEF";

  applyKey = keyProcess(key,16);

  printf("%s\n",applyKey);

  UnityAssertEqualString((const char*)("0123456789ABCDEF"), (const char*)(applyKey), (((void *)0)), (_U_UINT)229);

}



void test_keyProcess_given_a_string_0123456789ABCDEF12345_expected_string_0123456789ABCDEF_In_AES128(void){

  printf("No14.0 - keyProcess in AES_128\n");

  char* applyKey;

  char* key = "0123456789ABCDEF12345";

  applyKey = keyProcess(key,16);

  printf("%s\n",applyKey);

  UnityAssertEqualString((const char*)("0123456789ABCDEF"), (const char*)(applyKey), (((void *)0)), (_U_UINT)238);

}



void test_keyProcess_given_a_string_1234567_expected_string_123456700000000000000000_In_AES192(void){

  printf("No15.0 - keyProcess in AES_192\n");

  char* applyKey;

  char* key = "1234567";

  applyKey = keyProcess(key,24);

  printf("%s\n",applyKey);

  UnityAssertEqualString((const char*)("123456700000000000000000"), (const char*)(applyKey), (((void *)0)), (_U_UINT)247);

}



void test_keyProcess_given_a_string_0123456789ABCDEFGHIJKLNM_expected_string_0123456789ABCDEFGHIJKLNM_In_AES192(void){

  printf("No16.0 - keyProcess in AES_192\n");

  char* applyKey;

  char* key = "0123456789ABCDEFGHIJKLNM";

  applyKey = keyProcess(key,24);

  printf("%s\n",applyKey);

  UnityAssertEqualString((const char*)("0123456789ABCDEFGHIJKLNM"), (const char*)(applyKey), (((void *)0)), (_U_UINT)256);

}



void test_keyProcess_given_a_string_0123456789ABCDEFGHIJKLNM1221221212_expected_string_0123456789ABCDEFGHIJKLNM_In_AES192(void){

  printf("No17.0 - keyProcess in AES_192\n");

  char* applyKey;

  char* key = "0123456789ABCDEFGHIJKLNM1221221212";

  applyKey = keyProcess(key,24);

  printf("%s\n",applyKey);

  UnityAssertEqualString((const char*)("0123456789ABCDEFGHIJKLNM"), (const char*)(applyKey), (((void *)0)), (_U_UINT)265);

}



void test_keyProcess_given_a_string_01234567_expected_string_012345670000000000000000000000000_In_AES256(void){

  printf("No18.0 - keyProcess in AES_256\n");

  char* applyKey;

  char* key = "01234567";

  applyKey = keyProcess(key,32);

  printf("%s\n",applyKey);

  UnityAssertEqualString((const char*)("01234567000000000000000000000000"), (const char*)(applyKey), (((void *)0)), (_U_UINT)274);

}



void test_keyProcess_given_a_string_0123456789ABCDEFGHIJKLNMOPQRSTUV_expected_string_0123456789ABCDEFGHIJKLNMOPQRSTUV_In_AES256(void){

  printf("No19.0 - keyProcess in AES_256\n");

  char* applyKey;

  char* key = "0123456789ABCDEFGHIJKLNMOPQRSTUV";

  applyKey = keyProcess(key,32);

  printf("%s\n",applyKey);

  UnityAssertEqualString((const char*)("0123456789ABCDEFGHIJKLNMOPQRSTUV"), (const char*)(applyKey), (((void *)0)), (_U_UINT)283);

}



void test_keyProcess_given_a_string_0123456789ABCDEFGHIJKLNMOPQRSTUV112233_expected_string_0123456789ABCDEFGHIJKLNMOPQRSTUV_In_AES256(void){

  printf("No20.0 - keyProcess in AES_256\n");

  char* applyKey;

  char* key = "0123456789ABCDEFGHIJKLNMOPQRSTUV112233";

  applyKey = keyProcess(key,32);

  printf("%s\n",applyKey);

  UnityAssertEqualString((const char*)("0123456789ABCDEFGHIJKLNMOPQRSTUV"), (const char*)(applyKey), (((void *)0)), (_U_UINT)292);

}



void test_optimizeKey_given_1234567_expected_1234567000000000_in_128_bit(void){

  printf("No20.0 - optimizeKey in AES_128\n");

  char* key = "1234567";

  char* newkey = optimizeKey(key,1);

  printf("%s\n",newkey);

  UnityAssertEqualString((const char*)("1234567000000000"), (const char*)(newkey), (((void *)0)), (_U_UINT)300);

}



void test_optimizeKey_given_1234567_expected_123456700000000000000000_in_192_bit(void){

  printf("No21.0 - optimizeKey in AES_192\n");

  char* key = "1234567";

  char* newkey = optimizeKey(key,2);

  printf("%s\n",newkey);

  UnityAssertEqualString((const char*)("123456700000000000000000"), (const char*)(newkey), (((void *)0)), (_U_UINT)308);

}



void test_optimizeKey_given_1234567_expected_12345670000000000000000000000000_in_256_bit(void){

  printf("No22.0 - optimizeKey in AES_256\n");

  char* key = "1234567";

  char* newkey = optimizeKey(key,3);

  printf("%s\n",newkey);

  UnityAssertEqualString((const char*)("12345670000000000000000000000000"), (const char*)(newkey), (((void *)0)), (_U_UINT)316);

}







void test_getCipherKeyLen_(void){

  printf("No23.0 - getCipherKeyLen\n");

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((getCipherKeyLen("0123456789ABCDEFG"))), (((void *)0)), (_U_UINT)323, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((getCipherKeyLen("0123456789AFG"))), (((void *)0)), (_U_UINT)324, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((getCipherKeyLen("012345FG"))), (((void *)0)), (_U_UINT)325, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((getCipherKeyLen("345FG"))), (((void *)0)), (_U_UINT)326, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((getCipherKeyLen(""))), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((48)), (_U_SINT)((getCipherKeyLen("0123456789ABCDEFG0123456789ABCDEFG"))), (((void *)0)), (_U_UINT)328, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((64)), (_U_SINT)((getCipherKeyLen("0123456789ABCDEFG0123456789ABCDEFG0123456789ABCDEFG"))), (((void *)0)), (_U_UINT)329, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((getCipherKeyLen("0123456789ABCDEFG0123456789ABCDEFG0123456789ABCDEFG0123456789ABCDEFG"))), (((void *)0)), (_U_UINT)330, UNITY_DISPLAY_STYLE_INT);

}







void test_optimizerStr_given_0123456789ABCDEF_expected_0123456789ABCDEF(void){

  printf("No24.0 - optimizerStr\n");

  char* str1 = "0123456789ABCDEF";

  char* newStr = optimizeStr(str1);



  UnityAssertEqualString((const char*)("0123456789ABCDEF"), (const char*)(newStr), (((void *)0)), (_U_UINT)340);

  UnityAssertEqualNumber((_U_SINT)((16)), (_U_SINT)((strlen(newStr))), (((void *)0)), (_U_UINT)341, UNITY_DISPLAY_STYLE_INT);

}



void test_optimizerStr_given_0123456789ABCDEFA_expected_0123456789ABCDEFA000000000000000(void){

  printf("No25.0 - optimizerStr\n");

  char* str = "0123456789ABCDEFA";

  char* newStr = optimizeStr(str);



  UnityAssertEqualString((const char*)("0123456789ABCDEFA000000000000000"), (const char*)(newStr), (((void *)0)), (_U_UINT)349);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((strlen(newStr))), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT);





}



void test_optimizerStr_given_0123456789ABCDEF0123456789ABCDEF_expected_0123456789ABCDEF0123456789ABCDEF(void){

  printf("No25.0 - optimizerStr\n");

  char* str = "0123456789ABCDEF0123456789ABCDEF";

  char* newStr = optimizeStr(str);



  UnityAssertEqualString((const char*)("0123456789ABCDEF0123456789ABCDEF"), (const char*)(newStr), (((void *)0)), (_U_UINT)360);

  UnityAssertEqualNumber((_U_SINT)((32)), (_U_SINT)((strlen(newStr))), (((void *)0)), (_U_UINT)361, UNITY_DISPLAY_STYLE_INT);

}



void test_optimizerStr_given_0123456789ABCDEF0123456789ABCDEFA_expected_0123456789ABCDEF0123456789ABCDEFA000000000000000(void){

  printf("No26.0 - optimizerStr\n");

  char* str = "0123456789ABCDEF0123456789ABCDEFA";

  char* newStr = optimizeStr(str);



  UnityAssertEqualString((const char*)("0123456789ABCDEF0123456789ABCDEFA000000000000000"), (const char*)(newStr), (((void *)0)), (_U_UINT)369);

  UnityAssertEqualNumber((_U_SINT)((48)), (_U_SINT)((strlen(newStr))), (((void *)0)), (_U_UINT)370, UNITY_DISPLAY_STYLE_INT);

}



void test_convStrToStateWithIndex_(void){

  printf("No27.0 - convStrToStateWithIndex\n");

  uint8_t expOut0[4][4] = { {'0','4','8','C'},

                            {'1','5','9','D'},

                            {'2','6','A','E'},

                            {'3','7','B','F'} };

  uint8_t expOut1[4][4] = { {'A','0','0','0'},

                            {'0','0','0','0'},

                            {'0','0','0','0'},

                            {'0','0','0','0'} };

  uint8_t expOut2[4][4] = { {'0','4','8','1'},

                            {'1','5','9','1'},

                            {'2','6','1','1'},

                            {'3','7','1','1'} };

  uint8_t state[4][4];



  char* str = "0123456789ABCDEFA0000000000000000123456789111111";



  convStrToStateWithIndex(str,state,0);

  { customTestAssertEqualState(expOut0,state,392); };



  convStrToStateWithIndex(str,state,1);

  { customTestAssertEqualState(expOut1,state,395); };



  convStrToStateWithIndex(str,state,2);

  { customTestAssertEqualState(expOut2,state,398); };



}



void test_convStateToStrWithIndex(void){

  printf("No28.0 - convStateToStrWithIndex\n");



  char* encrypOut = malloc(sizeof(char*)*48);



    uint8_t state0[4][4] = { {'0','4','8','C'},

                            {'1','5','9','D'},

                            {'2','6','A','E'},

                            {'3','7','B','F'} };

  uint8_t state1[4][4] = { {'A','0','0','0'},

                            {'0','0','0','0'},

                            {'0','0','0','0'},

                            {'0','0','0','0'} };

  uint8_t state2[4][4] = { {'0','4','8','1'},

                            {'1','5','9','1'},

                            {'2','6','1','1'},

                            {'3','7','1','1'} };

   convStateToStrWithIndex(state0,encrypOut,0);

   printf("encrypOut = %s\n",encrypOut);

   convStateToStrWithIndex(state1,encrypOut,1);

   printf("encrypOut = %s\n",encrypOut);

   convStateToStrWithIndex(state2,encrypOut,2);

   printf("encrypOut = %s\n",encrypOut);

  UnityAssertEqualString((const char*)("0123456789ABCDEFA0000000000000000123456789111111"), (const char*)(encrypOut), (((void *)0)), (_U_UINT)425);

  UnityAssertEqualNumber((_U_SINT)((48)), (_U_SINT)((strlen(encrypOut))), (((void *)0)), (_U_UINT)426, UNITY_DISPLAY_STYLE_INT);



}



void test_encrypStr_given(void){

  printf("No29.0 - encrypStr\n");



  uint8_t* expectOut = malloc(sizeof(char)*17);

  uint8_t plainText[4][4];

  convStrToState("Hello,HwaNeng!!!",plainText);

  uint8_t key[] = "9988772211334455";

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];

  uint8_t state[4][4];



  encryp_16byte(plainText,key,encrypOut,1);

  convStateToStr(encrypOut,expectOut);

  uint8_t* chiperKey = encrypStr("Hello,HwaNeng!!!","9988772211334455",1);



  int i;

  for( i = 0 ; i<16;i++){

    printf("encrypOut[%d] = %x, chiperKey[%d] = %x\n",i,expectOut[i],i,chiperKey[i]);

    UnityAssertEqualNumber((_U_SINT)((expectOut[i])), (_U_SINT)((chiperKey[i])), (((void *)0)), (_U_UINT)448, UNITY_DISPLAY_STYLE_INT);

  }



  convStrToState(chiperKey,state);

  decryp_16byte(state,key,decrypOut,1);

  { customTestAssertEqualState(plainText,decrypOut,453); };

}
