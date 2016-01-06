#include "CException.h"
#include "ErrorObject.h"
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

  { customTestAssertEqualState(expOut,encrypOut,38); };

  invCipher(encrypOut,decrypOut,word,10);





  { customTestAssertEqualState(plainText,decrypOut,42); };

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

  { customTestAssertEqualState(expOut,encrypOut,66); };

  invCipher(encrypOut,decrypOut,word,12);





  { customTestAssertEqualState(plainText,decrypOut,70); };

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

  { customTestAssertEqualState(expOut,encrypOut,96); };

  invCipher(encrypOut,decrypOut,word,14);





  { customTestAssertEqualState(plainText,decrypOut,100); };

}



void test_decryption_16byte_given_plainText_in_encryption_and_expected_decryption_output_same_wtih_plainText(void){

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



  encryp_16byte(plainText,cipcherkey,encrypOut,1);

  decryp_16byte(encrypOut,cipcherkey,decrypOut,1);

  { customTestAssertEqualState(plainText,decrypOut,118); };

}



void test_decryption_16byte_given_plainText1_in_encryption_and_expected_decryption_output_same_wtih_plainText(void){

  printf("No5.0 - decryption_16byte \n");

  char *outString = malloc(sizeof(char)*17);

  char *encryOutSting = malloc(sizeof(char)*17);

  uint8_t plainText[4][4];

  convStrToState("Hello,HwaNeng!!!",plainText);

  uint8_t cipcherkey[] = { 0x00,0x01,0x02,0x03,

                           0x04,0x05,0x06,0x07,

                           0x08,0x09,0x0a,0x0b,

                           0x0c,0x0d,0x0e,0x0f };

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];

  encryp_16byte(plainText,cipcherkey,encrypOut,1);

  decryp_16byte(encrypOut,cipcherkey,decrypOut,1);







  convStateToStr(decrypOut,outString);

  convStateToStr(encrypOut,encryOutSting);



  { customTestAssertEqualState(plainText,decrypOut,141); };

}



void test_configureAES_testing_configuration_in_AES128_AES192_AES256(void){

  printf("No6.0 - configureAES\n");

  int wordofSize;

  int round;

  int keySize;

  configureAES(1,&keySize,&wordofSize,&round);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((round)), (((void *)0)), (_U_UINT)150, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((44)), (_U_SINT)((wordofSize)), (((void *)0)), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((keySize)), (((void *)0)), (_U_UINT)152, UNITY_DISPLAY_STYLE_INT);

  configureAES(2,&keySize,&wordofSize,&round);

  UnityAssertEqualNumber((_U_SINT)((12)), (_U_SINT)((round)), (((void *)0)), (_U_UINT)154, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((52)), (_U_SINT)((wordofSize)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((keySize)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT);

  configureAES(3,&keySize,&wordofSize,&round);

  UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((round)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((wordofSize)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((keySize)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

}





void test_decryp_16byte_given_128_bit_key(void){

  printf("No7.0 - decryp_16byte with 128-bit key\n");

  uint8_t plainText[4][4] = { {0x32,0x88,0x31,0xe0},

                       {0x43,0x5a,0x31,0x37},

                       {0xf6,0x30,0x98,0x07},

                       {0xa8,0x8d,0xa2,0x34} };

  uint8_t cipcherkey[] = {0x2b,0x7e,0x15,0x16,

                          0x28,0xae,0xd2,0xa6,

                          0xab,0xf7,0x15,0x88,

                          0x09,0xcf,0x4f,0x3c};

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];



  encryp_16byte(plainText,cipcherkey,encrypOut,1);

  decryp_16byte(encrypOut,cipcherkey,decrypOut,1);

  { customTestAssertEqualState(plainText,decrypOut,179); };

}

void test_decryp_16byte_given_192_bit_key(void){

  printf("No8.0 - decryp_16byte with 192-bit key\n");

  uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };

  uint8_t cipcherkey[] = {0x00,0x01,0x02,0x03,

                          0x04,0x05,0x06,0x07,

                          0x08,0x09,0x0a,0x0b,

                          0x0c,0x0d,0x0e,0x0f,

                          0x10,0x11,0x12,0x13,

                          0x14,0x15,0x16,0x17};



  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];



  encryp_16byte(plainText,cipcherkey,encrypOut,2);

  decryp_16byte(encrypOut,cipcherkey,decrypOut,2);

  { customTestAssertEqualState(plainText,decrypOut,199); };



}

void test_decryp_16byte_given_256_bit_key(void){

  printf("No9.0 - decryp_16byte with 256-bit key\n");

    uint8_t plainText[4][4] = { {0x00,0x44,0x88,0xcc},

                              {0x11,0x55,0x99,0xdd},

                              {0x22,0x66,0xaa,0xee},

                              {0x33,0x77,0xbb,0xff} };





  uint8_t cipcherkey[] = {0x00,0x01,0x02,0x03,

                        0x04,0x05,0x06,0x07,

                        0x08,0x09,0x0a,0x0b,

                        0x0c,0x0d,0x0e,0x0f,

                        0x10,0x11,0x12,0x13,

                        0x14,0x15,0x16,0x17,

                        0x18,0x19,0x1a,0x1b,

                        0x1c,0x1d,0x1e,0x1f};

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];



  encryp_16byte(plainText,cipcherkey,encrypOut,3);

  decryp_16byte(encrypOut,cipcherkey,decrypOut,3);

  { customTestAssertEqualState(plainText,decrypOut,223); };

}



void test_decryp_16byte_given_string_hwa_neng_and_key_9988776622334455_in_AES_128(void){

  printf("No10.0 - decryp_16byte\n");

  uint8_t plainText[4][4];

  convStrToState("Hello,HwaNeng!!!",plainText);

  uint8_t cipcherkey[] = "9988772211334455";

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];



  encryp_16byte(plainText,cipcherkey,encrypOut,1);

  decryp_16byte(encrypOut,cipcherkey,decrypOut,1);

  { customTestAssertEqualState(plainText,decrypOut,236); };



}

void test_decryp_16byte_given_string_hwa_neng_and_key_9988776622334455_in_AES_192(void){

  printf("No11.0 - decryp_16byte\n");

  uint8_t plainText[4][4];

  convStrToState("Hello,HwaNeng!!!",plainText);

  uint8_t cipcherkey[] = "9988772211334455";

  uint8_t encrypOut[4][4];

  uint8_t decrypOut[4][4];



  encryp_16byte(plainText,cipcherkey,encrypOut,2);

  decryp_16byte(encrypOut,cipcherkey,decrypOut,2);

  { customTestAssertEqualState(plainText,decrypOut,258); };



}

void test_decrypStr_given_a_less_than_16byte_of_str_and_the_encrypKey_and_decrypKey_is_same_expected_invCipherKey_is_correct_AES128(void){

  printf("No12.0 - decrypStr\n");

    uint8_t* cipherKey = encrypStr("Hello","9988772211334455",1);

    uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",1);

  UnityAssertEqualString((const char*)("Hello00000000000"), (const char*)(invCipherKey), (((void *)0)), (_U_UINT)275);

}

void test_decrypStr_given_a_16byte_str_and_the_encrypKey_and_decrypKey_is_same_expected_invCipherKey_is_correct_AES128(void){

  printf("No13.0 - decrypStr\n");

  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!!","9988772211334455",1);

  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",1);

  UnityAssertEqualString((const char*)("Hello,HwaNeng!!!"), (const char*)(invCipherKey), (((void *)0)), (_U_UINT)290);

}

void test_decrypStr_given_a_more_than_16byte_of_str_and_the_encrypKey_and_decrypKey_is_same_expected_invCipherKey_is_correct_AES128(void){

  printf("No14.0 - decrypStr\n");

  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",1);

  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",1);

  UnityAssertEqualString((const char*)("Hello,HwaNeng!!! I m LengZai0000"), (const char*)(invCipherKey), (((void *)0)), (_U_UINT)305);

}

void test_decrypStr_given_a_string_and_encrypkey_and_decrypkey_is_not_same_expected_invCipherKey_is_wrong_AES128(void){

  printf("No15.0 - decrypStr\n");

  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","554433221122342",1);

  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",1);

 { customTestAssertNotEqualStrting("Hello,HwaNeng!!! I m LengZai0000",invCipherKey,319); };

}

void test_decrypStr_given_a_string_and_encrypkey_and_decrypkey_is_same_but_AESmode_is_diffrent_expected_invCipherKey_is_wrong(void){

  printf("No16.0 - decrypStr\n");

  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",2);

  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",1);

 { customTestAssertNotEqualStrting("Hello,HwaNeng!!! I m LengZai0000",invCipherKey,334); };

}

void test_decrypStr_given_a_more_than_16byte_of_str_and_the_encrypKey_and_decrypKey_is_same_in_AES192_expected_invCipherKey_is_correct(void){

  printf("No17.0 - decrypStr\n");

  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",2);

  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",2);

  UnityAssertEqualString((const char*)("Hello,HwaNeng!!! I m LengZai0000"), (const char*)(invCipherKey), (((void *)0)), (_U_UINT)348);

}

void test_decrypStr_given_a_more_than_16byte_of_str_and_the_encrypKey_and_decrypKey_is_same_in_AES256_expected_invCipherKey_is_correct(void){

  printf("No18.0 - decrypStr\n");

  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",3);

  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",3);

  UnityAssertEqualString((const char*)("Hello,HwaNeng!!! I m LengZai0000"), (const char*)(invCipherKey), (((void *)0)), (_U_UINT)363);

}







void test_decrypStr_given_a_unknown_mode_expected_thorw_err_AES_MODE_CANNOT_BE_NULL_(void){

  printf("No19.0 - decrypStr\n");

  ErrorObject* err;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",3);

  uint8_t* invCipherKey = decrypStr(cipherKey,"9988772211334455",0);

  }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

   printf("%s",err->errorMsg);

   UnityAssertEqualNumber((_U_SINT)((ERR_AES_MODE_CANNOT_BE_NULL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)376, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualString((const char*)("Erorr: Please key in correct AES mode!"), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)377);

   freeError(err);

  }



}



void test_decrypStr_given_NULL_in_decrykey_expected_thorw_err_KEY_CANNOT_BE_NULL_(void){

  printf("No20.0 - decrypStr\n");

  ErrorObject* err;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  uint8_t* cipherKey = encrypStr("Hello,HwaNeng!!! I m LengZai","9988772211334455",3);

  uint8_t* invCipherKey = decrypStr(cipherKey,((void *)0),3);

  }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

   printf("%s",err->errorMsg);

   UnityAssertEqualNumber((_U_SINT)((ERR_KEY_CANNOT_BE_NULL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)391, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualString((const char*)("Error: Decrypt Key cannot be NULL!"), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)392);

   freeError(err);

  }

}



void test_decrypStr_given_NULL_in_Str_expected_thorw_err_STR_CANNOT_BE_NULL(void){

  printf("No21.0 - decrypStr\n");

  ErrorObject* err;

  { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = ((void *)0); if (_setjmp(NewFrame) == 0) { if (1){

  uint8_t* cipherKey = encrypStr("1234","9988772211334455",3);

  uint8_t* invCipherKey = decrypStr(((void *)0),"9988772211334455",3);

  }else { } CExceptionFrames[MY_ID].Exception = ((void *)0); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != ((void *)0)){

   printf("%s",err->errorMsg);

   UnityAssertEqualNumber((_U_SINT)((ERR_STR_CANNOT_BE_NULL)), (_U_SINT)((err->errorCode)), (((void *)0)), (_U_UINT)405, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualString((const char*)("Error: Input plainText cannot be NULL!"), (const char*)(err->errorMsg), (((void *)0)), (_U_UINT)406);

   freeError(err);

  }

}
