#include "unity.h"
#include "Decryption.h"
#include "Encryption.h"
#include "CustomAssertion.h"
#include "AddRoundKey.h"
#include "KeyExpansion.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "SubBytes.h"   
#include "malloc.h"
#include "ErrorObject.h"
#include "CException.h"


void setUp(void){}

void tearDown(void){}

void test_invCipher_given_128_bit_chiper_key(void){
   printf("No1.0 - cipher 128-bit key Size \n");
  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},\
                              {0x11,0x55,0x99,0xdd},\
                              {0x22,0x66,0xaa,0xee},\
                              {0x33,0x77,0xbb,0xff} }; 
  uint8_t expOut[4][4] =  { {0x69,0x6a,0xd8,0x70},\
                            {0xc4,0x7b,0xcd,0xb4},\
                            {0xe0,0x04,0xb7,0xc5},\
                            {0xd8,0x30,0x80,0x5a} };
  uint8_t cipcherkey[] = { 0x00,0x01,0x02,0x03,\
                           0x04,0x05,0x06,0x07,\
                           0x08,0x09,0x0a,0x0b,\
                           0x0c,0x0d,0x0e,0x0f };
  uint32_t word[44]; 
  uint8_t encrypOut[4][4];
  uint8_t decrypOut[4][4];
  keyExpansion(cipcherkey,word,4,10);
  cipher(plainText,encrypOut,word,10);  
  TEST_ASSERT_EQUAL_STATE(expOut,encrypOut); 
  invCipher(encrypOut,decrypOut,word,10);
  // printf("\n");
  // printfState(decrypOut);
  TEST_ASSERT_EQUAL_STATE(plainText,decrypOut); 
}

void test_invCipher_given_192_bit_chiper_key(void){
  printf("No2.0 - cipher 192-bit key Size \n");
  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},\
                              {0x11,0x55,0x99,0xdd},\
                              {0x22,0x66,0xaa,0xee},\
                              {0x33,0x77,0xbb,0xff} }; 
  uint8_t expOut[4][4] = { {0xdd,0x86,0x6e,0xec},\
                           {0xa9,0x4c,0xaf,0x0d},\
                           {0x7c,0xdf,0x70,0x71},\
                           {0xa4,0xe0,0xa0,0x91} };
  uint8_t cipcherkey[] = {0x00,0x01,0x02,0x03,\
                          0x04,0x05,0x06,0x07,\
                          0x08,0x09,0x0a,0x0b,\
                          0x0c,0x0d,0x0e,0x0f,\
                          0x10,0x11,0x12,0x13,\
                          0x14,0x15,0x16,0x17};
  uint32_t word[52]; 
  uint8_t encrypOut[4][4];
  uint8_t decrypOut[4][4];
  keyExpansion(cipcherkey,word,6,12);
  cipher(plainText,encrypOut,word,12);
  TEST_ASSERT_EQUAL_STATE(expOut,encrypOut);
  invCipher(encrypOut,decrypOut,word,12);
  // printf("\n");
  // printfState(decrypOut);
  TEST_ASSERT_EQUAL_STATE(plainText,decrypOut); 
}

void test_invCipher_given_256_bit_chiper_key(void){
   printf("No3.0 - cipher 256-bit key Size \n");
  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},\
                              {0x11,0x55,0x99,0xdd},\
                              {0x22,0x66,0xaa,0xee},\
                              {0x33,0x77,0xbb,0xff} }; 
  uint8_t expOut[4][4] = { {0x8e,0x51,0xea,0x4b},\
                           {0xa2,0x67,0xfc,0x49},\
                           {0xb7,0x45,0x49,0x60},\
                           {0xca,0xbf,0x90,0x89} };
uint8_t cipcherkey[] = {0x00,0x01,0x02,0x03,\
                        0x04,0x05,0x06,0x07,\
                        0x08,0x09,0x0a,0x0b,\
                        0x0c,0x0d,0x0e,0x0f,\
                        0x10,0x11,0x12,0x13,\
                        0x14,0x15,0x16,0x17,\
                        0x18,0x19,0x1a,0x1b,\
                        0x1c,0x1d,0x1e,0x1f};
  uint32_t word[60];
  uint8_t encrypOut[4][4];
  uint8_t decrypOut[4][4];
  keyExpansion(cipcherkey,word,8,14);
  cipher(plainText,encrypOut,word,14);
  TEST_ASSERT_EQUAL_STATE(expOut,encrypOut);
  invCipher(encrypOut,decrypOut,word,14);
  // printf("\n");
  // printfState(decrypOut);
  TEST_ASSERT_EQUAL_STATE(plainText,decrypOut); 
}

void test_decryption_16byte_given_plainText_in_encryption_and_expected_decryption_output_same_wtih_plainText(void){
  printf("No4.0 - decryption_16byte \n");
    uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},\
                              {0x11,0x55,0x99,0xdd},\
                              {0x22,0x66,0xaa,0xee},\
                              {0x33,0x77,0xbb,0xff} }; 
  uint8_t cipcherkey[] = { 0x00,0x01,0x02,0x03,\
                           0x04,0x05,0x06,0x07,\
                           0x08,0x09,0x0a,0x0b,\
                           0x0c,0x0d,0x0e,0x0f };
  uint8_t encrypOut[4][4];
  uint8_t decrypOut[4][4];
                           
  encryp_16byte(plainText,cipcherkey,encrypOut,AES_128);
  decryp_16byte(encrypOut,cipcherkey,decrypOut,AES_128);
  TEST_ASSERT_EQUAL_STATE(plainText,decrypOut); 
}

void test_decryption_16byte_given_plainText1_in_encryption_and_expected_decryption_output_same_wtih_plainText(void){
  printf("No5.0 - decryption_16byte \n");
  char *outString = malloc(sizeof(char)*17);
  char *encryOutSting = malloc(sizeof(char)*17);
  uint8_t plainText[4][4];
  convStrToState("Hello,HwaNeng!!!",plainText);
  uint8_t cipcherkey[] = { 0x00,0x01,0x02,0x03,\
                           0x04,0x05,0x06,0x07,\
                           0x08,0x09,0x0a,0x0b,\
                           0x0c,0x0d,0x0e,0x0f };
  uint8_t encrypOut[4][4];
  uint8_t decrypOut[4][4];
  encryp_16byte(plainText,cipcherkey,encrypOut,AES_128);
  decryp_16byte(encrypOut,cipcherkey,decrypOut,AES_128);
  // printfState(encrypOut);
  // printf("\n");
  // printfState(decrypOut);
  convStateToStr(decrypOut,outString);
  convStateToStr(encrypOut,encryOutSting);
  // printf("%s\n",outString);
  TEST_ASSERT_EQUAL_STATE(plainText,decrypOut); 
}

void test_configureAES_testing_configuration_in_AES128_AES192_AES256(void){
  printf("No6.0 - configureAES\n");
  int wordofSize;
  int round;
  int keySize;
  configureAES(AES_128,&keySize,&wordofSize,&round);
  TEST_ASSERT_EQUAL(10,round);
  TEST_ASSERT_EQUAL(44,wordofSize);
  TEST_ASSERT_EQUAL(4,keySize);
  configureAES(AES_192,&keySize,&wordofSize,&round);
  TEST_ASSERT_EQUAL(12,round);
  TEST_ASSERT_EQUAL(52,wordofSize);
  TEST_ASSERT_EQUAL(6,keySize);
  configureAES(AES_256,&keySize,&wordofSize,&round);
  TEST_ASSERT_EQUAL(14,round);
  TEST_ASSERT_EQUAL(60,wordofSize);
  TEST_ASSERT_EQUAL(8,keySize);
}


void test_decryp_16byte_given_128_bit_key(void){
  printf("No7.0 - decryp_16byte with 128-bit key\n");
  uint8_t plainText[4][4] = { {0x32,0x88,0x31,0xe0},\
                       {0x43,0x5a,0x31,0x37},\
                       {0xf6,0x30,0x98,0x07},\
                       {0xa8,0x8d,0xa2,0x34} }; 
  uint8_t cipcherkey[] = {0x2b,0x7e,0x15,0x16,\
                          0x28,0xae,0xd2,0xa6,\
                          0xab,0xf7,0x15,0x88,\
                          0x09,0xcf,0x4f,0x3c};
  uint8_t encrypOut[4][4];
  uint8_t decrypOut[4][4];
  
  encryp_16byte(plainText,cipcherkey,encrypOut,AES_128);
  decryp_16byte(encrypOut,cipcherkey,decrypOut,AES_128);
  TEST_ASSERT_EQUAL_STATE(plainText,decrypOut); 
}
void test_decryp_16byte_given_192_bit_key(void){
  printf("No8.0 - decryp_16byte with 192-bit key\n");
  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},\
                              {0x11,0x55,0x99,0xdd},\
                              {0x22,0x66,0xaa,0xee},\
                              {0x33,0x77,0xbb,0xff} }; 
  uint8_t cipcherkey[] = {0x00,0x01,0x02,0x03,\
                          0x04,0x05,0x06,0x07,\
                          0x08,0x09,0x0a,0x0b,\
                          0x0c,0x0d,0x0e,0x0f,\
                          0x10,0x11,0x12,0x13,\
                          0x14,0x15,0x16,0x17};
                          
  uint8_t encrypOut[4][4];
  uint8_t decrypOut[4][4];
  
  encryp_16byte(plainText,cipcherkey,encrypOut,AES_192);
  decryp_16byte(encrypOut,cipcherkey,decrypOut,AES_192);
  TEST_ASSERT_EQUAL_STATE(plainText,decrypOut); 
  
}
void test_decryp_16byte_given_256_bit_key(void){
  printf("No9.0 - decryp_16byte with 256-bit key\n");
    uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},\
                              {0x11,0x55,0x99,0xdd},\
                              {0x22,0x66,0xaa,0xee},\
                              {0x33,0x77,0xbb,0xff} }; 


  uint8_t cipcherkey[] = {0x00,0x01,0x02,0x03,\
                        0x04,0x05,0x06,0x07,\
                        0x08,0x09,0x0a,0x0b,\
                        0x0c,0x0d,0x0e,0x0f,\
                        0x10,0x11,0x12,0x13,\
                        0x14,0x15,0x16,0x17,\
                        0x18,0x19,0x1a,0x1b,\
                        0x1c,0x1d,0x1e,0x1f};
  uint8_t encrypOut[4][4];
  uint8_t decrypOut[4][4];
  
  encryp_16byte(plainText,cipcherkey,encrypOut,AES_256);
  decryp_16byte(encrypOut,cipcherkey,decrypOut,AES_256);
  TEST_ASSERT_EQUAL_STATE(plainText,decrypOut); 
}

void test_decryp_16byte_given_string_hwa_neng_and_key_9988776622334455_in_AES_128(void){
  printf("No10.0 - decryp_16byte\n");
  uint8_t plainText[4][4];
  convStrToState("Hello,HwaNeng!!!",plainText);
  uint8_t cipcherkey[] = "9988772211334455";
  uint8_t encrypOut[4][4];
  uint8_t decrypOut[4][4];
  
  encryp_16byte(plainText,cipcherkey,encrypOut,AES_128);
  decryp_16byte(encrypOut,cipcherkey,decrypOut,AES_128);
  TEST_ASSERT_EQUAL_STATE(plainText,decrypOut); 
  
}

/*
              AESmode = AES_128                                          AESmode = AES_128
           encrypKey = "9988772211334455";                             decrypKey = "9988772211334455"; 
                 ||                                                                    ||
                 V                                                                     V
    "Hello,HwaNeng!!!"------->encryp_16byte(...)--->cipherKey--->decryp_16byte(...)-------->"Hello,HwaNeng!!!"

*/
void test_decryp_16byte_given_string_hwa_neng_and_key_9988776622334455_in_AES_192(void){
  printf("No11.0 - decryp_16byte\n");
  uint8_t plainText[4][4];
  convStrToState("Hello,HwaNeng!!!",plainText);
  uint8_t cipcherkey[] = "9988772211334455";
  uint8_t encrypOut[4][4];
  uint8_t decrypOut[4][4];
  
  encryp_16byte(plainText,cipcherkey,encrypOut,AES_192);
  decryp_16byte(encrypOut,cipcherkey,decrypOut,AES_192);
  TEST_ASSERT_EQUAL_STATE(plainText,decrypOut); 
  
}

/*
              AESmode = AES_128                            AESmode = AES_128
           encrypKey = "9988772211334455";                decrypKey = "9988772211334455"; 
                 ||                                                   ||
                 V                                                    V
      "Hello"-------> encrypStr(...)--->cipherKey--->decrypStr(...)-------->"Hello00000000000"

*/

void test_decrypStr_given_a_less_than_16byte_of_str_and_the_encrypKey_and_decrypKey_is_same_expected_invCipherKey_is_correct_AES128(void){
  printf("No12.0 - decrypStr\n");
    uint8_t* cipherKey = encrypStr("Hello","9988772211334455",AES_128);
    uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",AES_128);
  TEST_ASSERT_EQUAL_STRING("Hello00000000000",invCipherKey);
}

/*
               AESmode = AES_128                              AESmode = AES_128
             encrypKey = "9988772211334455";                decrypKey = "9988772211334455"; 
                           ||                                                 ||
                           V                                                  V
    "Hello,HwaNeng!!!"------->encrypStr(...)--->cipherKey--->decrypStr(...)--------> "Hello,HwaNeng!!!"

*/
void test_decrypStr_given_a_16byte_str_and_the_encrypKey_and_decrypKey_is_same_expected_invCipherKey_is_correct_AES128(void){
  printf("No13.0 - decrypStr\n");
  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!!","9988772211334455",AES_128);
  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",AES_128);
  TEST_ASSERT_EQUAL_STRING("Hello,HwaNeng!!!",invCipherKey);
}

/*
                        AESmode = AES_128                                AESmode = AES_128
                      encrypKey = "9988772211334455";                 decrypKey = "9988772211334455"; 
                                     ||                                                   ||
                                     V                                                    V
    "Hello,HwaNeng!!! I m LengZai"------->encrypStr(...)--->cipherKey--->decrypStr(...)--------> "Hello,HwaNeng!!! I m LengZai0000"

*/
void test_decrypStr_given_a_more_than_16byte_of_str_and_the_encrypKey_and_decrypKey_is_same_expected_invCipherKey_is_correct_AES128(void){
  printf("No14.0 - decrypStr\n");
  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",AES_128);
  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",AES_128);
  TEST_ASSERT_EQUAL_STRING("Hello,HwaNeng!!! I m LengZai0000",invCipherKey);
}
/*        
                            AESmode = AES_128                            AESmode = AES_128
                          encrypKey = "554433221122342";              decrypKey = "9988772211334455";     
                                      ||                                                    ||
                                      V                                                     V
    "Hello,HwaNeng!!! I m LengZai"------->encrypStr(...)--->cipherKey--->decrypStr(...)--------> "XXXXXXXXXXXXXXX"

*/
void test_decrypStr_given_a_string_and_encrypkey_and_decrypkey_is_not_same_expected_invCipherKey_is_wrong_AES128(void){
  printf("No15.0 - decrypStr\n");
  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","554433221122342",AES_128);
  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",AES_128);
 TEST_ASSERT_NOT_EQUAL_STRING("Hello,HwaNeng!!! I m LengZai0000",invCipherKey);
}

/*
                            AESmode = AES_128                          AESmode = AES_192 <----Note:different
                          encrypKey = "9988772211334455";            decrypKey = "9988772211334455";     
                                        ||                                               ||
                                        V                                                V
    Hello,HwaNeng!!! I m LengZai"------->encrypStr(...)--->cipherKey--->decrypStr(...)--------> "XXXXXXXXXXXXXXX"

*/
void test_decrypStr_given_a_string_and_encrypkey_and_decrypkey_is_same_but_AESmode_is_diffrent_expected_invCipherKey_is_wrong(void){
  printf("No16.0 - decrypStr\n");
  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",AES_192);
  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",AES_128);
 TEST_ASSERT_NOT_EQUAL_STRING("Hello,HwaNeng!!! I m LengZai0000",invCipherKey);
}
/*
                           AESmode = AES_192                            AESmode = AES_192
                        encrypKey = "9988772211334455";                 decrypKey = "9988772211334455"; 
                                      ||                                                  ||
                                      V                                                   V
    "Hello,HwaNeng!!! I m LengZai"------->encrypStr(...)--->cipherKey--->decrypStr(...)-------->"Hello,HwaNeng!!! I m LengZai0000"

*/
void test_decrypStr_given_a_more_than_16byte_of_str_and_the_encrypKey_and_decrypKey_is_same_in_AES192_expected_invCipherKey_is_correct(void){
  printf("No17.0 - decrypStr\n");
  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",AES_192);
  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",AES_192);
  TEST_ASSERT_EQUAL_STRING("Hello,HwaNeng!!! I m LengZai0000",invCipherKey);
}

/*
                          AESmode = AES_256                              AESmode = AES_256
                        encrypKey = "9988772211334455";                 decrypKey = "9988772211334455"; 
                                      ||                                                   ||
                                      V                                                    V
    "Hello,HwaNeng!!! I m LengZai"------->encrypStr(...)--->cipherKey--->decrypStr(...)--------> "Hello,HwaNeng!!! I m LengZai0000"

*/
void test_decrypStr_given_a_more_than_16byte_of_str_and_the_encrypKey_and_decrypKey_is_same_in_AES256_expected_invCipherKey_is_correct(void){
  printf("No18.0 - decrypStr\n");
  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",AES_256);
  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",AES_256);
  TEST_ASSERT_EQUAL_STRING("Hello,HwaNeng!!! I m LengZai0000",invCipherKey);
}



void test_decrypStr_given_a_unknown_mode_expected_thorw_err_AES_MODE_CANNOT_BE_NULL_(void){
  printf("No19.0 - decrypStr\n");
  CEXCEPTION_T err;
  Try{
  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",AES_256);
  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",0);
  }Catch(err){
   printf("%s",err->errorMsg); 
   TEST_ASSERT_EQUAL(ERR_AES_MODE_CANNOT_BE_NULL,err->errorCode);
   TEST_ASSERT_EQUAL_STRING("Erorr: Please key in correct AES mode!",err->errorMsg);
   freeError(err);
  }
  
}

void test_decrypStr_given_NULL_in_decrykey_expected_thorw_err_KEY_CANNOT_BE_NULL_(void){
  printf("No20.0 - decrypStr\n");
  CEXCEPTION_T err;
  Try{
  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",AES_256);
  uint8_t* invCipherKey = decrypStr(cipherKey,NULL,AES_256);
  }Catch(err){
   printf("%s",err->errorMsg); 
   TEST_ASSERT_EQUAL(ERR_KEY_CANNOT_BE_NULL,err->errorCode);
   TEST_ASSERT_EQUAL_STRING("Error: Decrypt Key cannot be NULL!",err->errorMsg);
   freeError(err);
  }
}

void test_decrypStr_given_NULL_in_Str_expected_thorw_err_STR_CANNOT_BE_NULL(void){
  printf("No21.0 - decrypStr\n");
  CEXCEPTION_T err;
  Try{
  uint8_t* cipherKey = encrypStr("1234","9988772211334455",AES_256);
  uint8_t* invCipherKey = decrypStr(NULL,"9988772211334455",AES_256);
  }Catch(err){
   printf("%s",err->errorMsg); 
   TEST_ASSERT_EQUAL(ERR_STR_CANNOT_BE_NULL,err->errorCode);
   TEST_ASSERT_EQUAL_STRING("Error: Input plainText cannot be NULL!",err->errorMsg);
   freeError(err);
  }
}

