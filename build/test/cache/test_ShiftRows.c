#include "SubBytes.h"
#include "CustomAssertion.h"
#include "ShiftRows.h"
#include "unity.h"


void setUp(void)

{

}



void tearDown(void)

{

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

 { customTestAssertEqualState(exState,state,39); };

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

 { customTestAssertEqualState(exState,state,63); };

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

  { customTestAssertEqualState(exState,state,81); };



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

  { customTestAssertEqualState(exState,state,98); };

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

  { customTestAssertEqualState(exState,state,114); };

}
