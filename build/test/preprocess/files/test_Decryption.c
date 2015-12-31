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

  { customTestAssertEqualState(exState,state,70); };

}
