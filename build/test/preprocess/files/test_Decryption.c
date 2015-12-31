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

void test_invSubBytes_given_ABCDEFGHIJK(void){

  printf("No1.0 - invSubBytes\n");

   uint8_t exState[4][4] = {{0xf8,0x68,0xa4,0x65},

                           {0xf6,0x98,0x5c,0xb6},

                           {0x64,0x16,0xcc,0x92},

                           {0x86,0xd4,0x5d,0x6c} };

  char* str = "ABCDEFGHIJKLMNOP";

  uint8_t state[4][4];

  convStrToState(str,state);



  printf("\n");

  invSubBytes(state);



  { customTestAssertEqualState(exState,state,39); };

}

void test_invShift_given_ABCDEFGHIJKLMNOP_expected_equal_exState(void){

  printf("No2.0 - invShift\n");



  uint8_t exState[4][4] = { {'A','E','I','M'},

                            {'N','B','F','J'},

                            {'K','O','C','G'},

                            {'H','L','P','D'} };

  uint8_t state[4][4] = { {'A','E','I','M'},

                          {'B','F','J','N'},

                          {'C','G','K','O'},

                          {'D','H','L','P'} };



   printfState(state);

   printf("\n");

  invShift(0,4,state);

  invShift(1,4,state);

  invShift(2,4,state);

  invShift(3,4,state);

  printfState(state);

  { customTestAssertEqualState(exState,state,72); };

}

void test_invShiftRow_given_ABCDEFGHIJKLMNOP_expected_result_is_ANKHEBOLIFCPMJGD(void){

  printf("No3.0 - invShiftRow\n");

  uint8_t state[4][4] = { {'A','E','I','M'},

                          {'B','F','J','N'},

                          {'C','G','K','O'},

                          {'D','H','L','P'} };



  uint8_t exState[4][4] = { {'A','E','I','M'},

                            {'N','B','F','J'},

                            {'K','O','C','G'},

                            {'H','L','P','D'} };



  invShiftRow(state);

  { customTestAssertEqualState(exState,state,96); };

}



void test_invShiftRow_given_123456789ABCEFG_expected_result_is_ANKHEBOLIFCPMJGD(void){

  printf("No3.1 - invShiftRow\n");

  uint8_t state[4][4] = { {'1','5','9','D'},

                          {'2','6','A','E'},

                          {'3','7','B','F'},

                          {'L','P','D','H'} };



  uint8_t exState[4][4] = { {'1','5','9','D'},

                            {'E','2','6','A'},

                            {'B','F','3','7'},

                            {'P','D','H','L'} };



  invShiftRow(state);

  { customTestAssertEqualState(exState,state,112); };

}

void test_invMixColumns_given_state_and_expected_equal_exState(void){

  printf("No4.0 - invMixColumns\n");

    uint8_t state[4][4] = { {0xbd,0xf2,0x0b,0x8b},

                            {0x6e,0xb5,0x61,0x10},

                            {0x7c,0x77,0x21,0xb6},

                            {0x3d,0x9e,0x6e,0x89} };



  uint8_t exState[4][4] = { {0x47,0xf7,0x61,0xa1},

                            {0x73,0x2f,0xcb,0xe6},

                            {0xb9,0x35,0x01,0xcf},

                            {0x1f,0x43,0x8e,0x2c} };

  invMixColumns(state);

  { customTestAssertEqualState(exState,state,136); };

}



void test_invMixColumns_given_state2_and_expected_equal_exState(void){

  printf("No4.1 - invMixColumns\n");

    uint8_t state[4][4] = { {0xfd,0x05,0x35,0xf1},

                            {0xe3,0xe5,0x47,0xfe},

                            {0xba,0xd0,0x96,0x37},

                            {0xd2,0xd7,0x4e,0xf1} };



  uint8_t exState[4][4] = { {0x2d,0x39,0xe6,0x01},

                            {0x7e,0xd9,0x57,0x90},

                            {0x86,0x39,0x0a,0x4e},

                            {0xa3,0x3e,0x11,0x16} };

  invMixColumns(state);

  { customTestAssertEqualState(exState,state,151); };

}

void test_multiWithXRO_given_0x57_and_0x83_expected_0x2b79(void){

    printf("No5.3 - multiWithXRO\n");

    UnityAssertEqualNumber((_U_SINT)((0x2b79)), (_U_SINT)((multiWithXRO(0x57,0x83))), (((void *)0)), (_U_UINT)176, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((multiWithXRO(0x57,0x0))), (((void *)0)), (_U_UINT)177, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((multiWithXRO(0x0,0x2))), (((void *)0)), (_U_UINT)178, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x2)), (_U_SINT)((multiWithXRO(0x1,0x2))), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x8)), (_U_SINT)((multiWithXRO(0x4,0x2))), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x570)), (_U_SINT)((multiWithXRO(0x57,0x10))), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x570)), (_U_SINT)((multiWithXRO(0x10,0x57))), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x20)), (_U_SINT)((multiWithXRO(0x10,0x2))), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

    printf("0xF1*0x03 = 0x%x , multiWithXRO(0xf1,0x03) = 0x%x\n",(0xf1*0x03),multiWithXRO(0xf1,0x03));







}



void test_module0x11bWithXRO_(void){

  printf("No5.4 - module0x11bWithXRO\n");



  UnityAssertEqualNumber((_U_SINT)((0xb)), (_U_SINT)((module0x11bWithXRO(0x110))), (((void *)0)), (_U_UINT)193, UNITY_DISPLAY_STYLE_INT);

}



void test_multiInGF_given_0x57_and_times_14_expected_(void){

  printf("No5.5 - multiInGF\n");

  UnityAssertEqualNumber((_U_SINT)((0xae)), (_U_SINT)((multiInGF(0x57,0x02))), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xfe)), (_U_SINT)((multiInGF(0x57,0x13))), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x07)), (_U_SINT)((multiInGF(0x57,0x10))), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x47)), (_U_SINT)((multiInGF(0x57,0x04))), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x57)), (_U_SINT)((multiInGF(0x57,0x01))), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

}
