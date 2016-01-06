#include "CustomAssertion.h"
#include "MixColumns.h"
#include "unity.h"
void setUp(void)

{

}



void tearDown(void)

{

}



void test_multiWithXRO_given_0x57_and_0x83_expected_0x2b79(void){

    printf("No1.0 - multiWithXRO\n");

    UnityAssertEqualNumber((_U_SINT)((0x2b79)), (_U_SINT)((multiWithXRO(0x57,0x83))), (((void *)0)), (_U_UINT)14, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((multiWithXRO(0x57,0x0))), (((void *)0)), (_U_UINT)15, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((multiWithXRO(0x0,0x2))), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x2)), (_U_SINT)((multiWithXRO(0x1,0x2))), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x8)), (_U_SINT)((multiWithXRO(0x4,0x2))), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x570)), (_U_SINT)((multiWithXRO(0x57,0x10))), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x570)), (_U_SINT)((multiWithXRO(0x10,0x57))), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0x20)), (_U_SINT)((multiWithXRO(0x10,0x2))), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);





}



void test_module0x11bWithXRO_(void){

  printf("No2.0 - module0x11bWithXRO\n");



  UnityAssertEqualNumber((_U_SINT)((0xb)), (_U_SINT)((module0x11bWithXRO(0x110))), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

}



void test_multiInGF_given_0x57_and_times_14_expected_(void){

  printf("No3.0 - multiInGF\n");

  UnityAssertEqualNumber((_U_SINT)((0xae)), (_U_SINT)((multiInGF(0x57,0x02))), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xfe)), (_U_SINT)((multiInGF(0x57,0x13))), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x07)), (_U_SINT)((multiInGF(0x57,0x10))), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x47)), (_U_SINT)((multiInGF(0x57,0x04))), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x57)), (_U_SINT)((multiInGF(0x57,0x01))), (((void *)0)), (_U_UINT)38, UNITY_DISPLAY_STYLE_INT);

}





void test_mixColumns_given_state2_and_expected_equal_exState(void){

  printf("No4.0 - mixColumns\n");

  uint8_t state2[4][4] = { {0xac,0xef,0x13,0x45},

                          {0xc1,0xb5,0x23,0x73},

                          {0xd6,0x5a,0xcf,0x11},

                          {0xb8,0x7b,0xdf,0xb5} };

  uint8_t exState[4][4] = {{0x75,0x20,0x53,0xbb},

                           {0xec,0x0b,0xc0,0x25},

                           {0x09,0x63,0xcf,0xd0},

                           {0x93,0x33,0x7c,0xdc} };

    mixColumns(state2);

    { customTestAssertEqualState(exState,state2,53); };

}



void test_mixColumns_given_state3_and_expected_equal_exState(void){

  printf("No5.0 - mixColumns\n");

  uint8_t state3[4][4] = { {0x87,0xf2,0x4d,0x97},

                          {0x6e,0x4c,0x90,0xec},

                          {0x46,0xe7,0x4a,0xc3},

                          {0xa6,0x8c,0xd8,0x95} };

  uint8_t exState[4][4] = {{0x47,0x40,0xa3,0x4c},

                           {0x37,0xd4,0x70,0x9f},

                           {0x94,0xe4,0x3a,0x42},

                           {0xed,0xa5,0xa6,0xbc} };

    mixColumns(state3);

    { customTestAssertEqualState(exState,state3,67); };



}



void test_invMixColumns_given_state_and_expected_equal_exState(void){

  printf("No6.0 - invMixColumns\n");

    uint8_t state[4][4] = { {0xbd,0xf2,0x0b,0x8b},

                            {0x6e,0xb5,0x61,0x10},

                            {0x7c,0x77,0x21,0xb6},

                            {0x3d,0x9e,0x6e,0x89} };



  uint8_t exState[4][4] = { {0x47,0xf7,0x61,0xa1},

                            {0x73,0x2f,0xcb,0xe6},

                            {0xb9,0x35,0x01,0xcf},

                            {0x1f,0x43,0x8e,0x2c} };

  invMixColumns(state);

  { customTestAssertEqualState(exState,state,83); };

}



void test_invMixColumns_given_state2_and_expected_equal_exState(void){

  printf("No7.0 - invMixColumns\n");

    uint8_t state[4][4] = { {0xfd,0x05,0x35,0xf1},

                            {0xe3,0xe5,0x47,0xfe},

                            {0xba,0xd0,0x96,0x37},

                            {0xd2,0xd7,0x4e,0xf1} };



  uint8_t exState[4][4] = { {0x2d,0x39,0xe6,0x01},

                            {0x7e,0xd9,0x57,0x90},

                            {0x86,0x39,0x0a,0x4e},

                            {0xa3,0x3e,0x11,0x16} };

  invMixColumns(state);

  { customTestAssertEqualState(exState,state,98); };

}
