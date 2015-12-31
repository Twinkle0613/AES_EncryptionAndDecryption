#include "unity.h"
#include "Decryption.h"
#include "Encryption.h"
#include "CustomAssertion.h"
#include "AddRoundKey.h"
#include "KeyExpansion.h"
#include "MixColumns.h"
#include "ShiftRows.h"
#include "SubBytes.h"   


void setUp(void){}

void tearDown(void){}

//----------------invSubBytes----------------------

/*

  'A'(41) 'E'(45) 'I'(49) 'M'(4d)   invS-BOX   f8 68 a4 65
  'B'(42) 'F'(46) 'J'(4a) 'N'(4e)  -------->   f6 98 5c b6
  'C'(43) 'G'(47) 'K'(4b) 'O'(4f)              64 16 cc 92
  'D'(44) 'H'(48) 'L'(4c) 'P'(50)              86 d4 5d 6c

*/
void test_invSubBytes_given_ABCDEFGHIJK(void){
  printf("No1.0 - invSubBytes\n");
   uint8_t exState[4][4] = {{0xf8,0x68,0xa4,0x65},    \
                           {0xf6,0x98,0x5c,0xb6},    \
                           {0x64,0x16,0xcc,0x92},    \
                           {0x86,0xd4,0x5d,0x6c} };  
  char* str = "ABCDEFGHIJKLMNOP";
  uint8_t state[4][4];
  convStrToState(str,state);
//  printfState(state);
  printf("\n");
  invSubBytes(state);
//  printfState(state);
  TEST_ASSERT_EQUAL_STATE(exState,state);
}


//------------------------invShiftRows---------------------

/*
 row 
 0   'A' 'E' 'I' 'M'   --->invShift(0,4,state)--->   'A' 'E' 'I' 'M'
 1   'B' 'F' 'J' 'N'   --->invShift(1,4,state)--->   'N' 'B' 'F' 'J'
 2   'C' 'G' 'K' 'O'   --->invShift(2,4,state)--->   'K' 'O' 'C' 'G'
 3   'D' 'H' 'L' 'P'   --->invShift(3,4,state)--->   'H' 'L' 'P' 'D'
*/

void test_invShift_given_ABCDEFGHIJKLMNOP_expected_equal_exState(void){
  printf("No2.0 - invShift\n");

  uint8_t exState[4][4] = { {'A','E','I','M'},\
                            {'N','B','F','J'},\
                            {'K','O','C','G'},\
                            {'H','L','P','D'}  };
  uint8_t state[4][4] = { {'A','E','I','M'},\
                          {'B','F','J','N'},\
                          {'C','G','K','O'},\
                          {'D','H','L','P'}  };
 // invShift(0,4,state);
   printfState(state);
   printf("\n");
  invShift(0,4,state);
  invShift(1,4,state);
  invShift(2,4,state);
  invShift(3,4,state);
  printfState(state);
  TEST_ASSERT_EQUAL_STATE(exState,state);
}  

/*
 row 
 0   'A' 'E' 'I' 'M'                       'A' 'E' 'I' 'M'
 1   'B' 'F' 'J' 'N'  ----invShiftRow--->  'N' 'B' 'F' 'J'
 2   'C' 'G' 'K' 'O'                       'K' 'O' 'C' 'G'
 3   'D' 'H' 'L' 'P'                       'H' 'L' 'P' 'D'
*/

void test_invShiftRow_given_ABCDEFGHIJKLMNOP_expected_result_is_ANKHEBOLIFCPMJGD(void){
  printf("No3.0 - invShiftRow\n");
  uint8_t state[4][4] = { {'A','E','I','M'},\
                          {'B','F','J','N'},\
                          {'C','G','K','O'},\
                          {'D','H','L','P'}  };
                          
  uint8_t exState[4][4] = { {'A','E','I','M'},\
                            {'N','B','F','J'},\
                            {'K','O','C','G'},\
                            {'H','L','P','D'}  };

  invShiftRow(state);              
  TEST_ASSERT_EQUAL_STATE(exState,state);
}

void test_invShiftRow_given_123456789ABCEFG_expected_result_is_ANKHEBOLIFCPMJGD(void){
  printf("No3.1 - invShiftRow\n");
  uint8_t state[4][4] = { {'1','5','9','D'},\
                          {'2','6','A','E'},\
                          {'3','7','B','F'},\
                          {'L','P','D','H'}  };
                          
  uint8_t exState[4][4] = { {'1','5','9','D'},\
                            {'E','2','6','A'},\
                            {'B','F','3','7'},\
                            {'P','D','H','L'}  };

  invShiftRow(state);              
  TEST_ASSERT_EQUAL_STATE(exState,state);
}

//------------------invMixColumns-----------------//

/*
    S'(0,C)      02 03 01 01       S(0,C)
    S'(1,C)  =   01 02 03 01  dot  S(1,C)  
    S'(2,C)      01 01 02 03       S(2,C)
    S'(3,C)      03 01 01 02       S(3,C)
*/

void test_invMixColumns_given_state_and_expected_equal_exState(void){
  printf("No4.0 - invMixColumns\n");
    uint8_t state[4][4] = { {0xbd,0xf2,0x0b,0x8b},\
                            {0x6e,0xb5,0x61,0x10},\
                            {0x7c,0x77,0x21,0xb6},\
                            {0x3d,0x9e,0x6e,0x89}  };
                          
  uint8_t exState[4][4] = { {0x47,0xf7,0x61,0xa1},\
                            {0x73,0x2f,0xcb,0xe6},\
                            {0xb9,0x35,0x01,0xcf},\
                            {0x1f,0x43,0x8e,0x2c}  };
  invMixColumns(state);
  TEST_ASSERT_EQUAL_STATE(exState,state);
}

void test_invMixColumns_given_state2_and_expected_equal_exState(void){
  printf("No4.1 - invMixColumns\n");
    uint8_t state[4][4] = { {0xfd,0x05,0x35,0xf1},\
                            {0xe3,0xe5,0x47,0xfe},\
                            {0xba,0xd0,0x96,0x37},\
                            {0xd2,0xd7,0x4e,0xf1}  };
                          
  uint8_t exState[4][4] = { {0x2d,0x39,0xe6,0x01},\
                            {0x7e,0xd9,0x57,0x90},\
                            {0x86,0x39,0x0a,0x4e},\
                            {0xa3,0x3e,0x11,0x16}  };
  invMixColumns(state);
  TEST_ASSERT_EQUAL_STATE(exState,state);
}


// void test_timesTen_given_0x57_expected_0x07(void){
  // printf("No5.0 - timesTen\n");
  // TEST_ASSERT_EQUAL(0x07,timesTen(0x57));
// }

// void test_timeFour_given_0x57_ecpected_0x8e(void){
  // printf("No5.1 - timesFour\n");
  // TEST_ASSERT_EQUAL(0x47,timesFour(0x57));
// }

// void test_timesEvenNumber_given_0x57_and_times_2_4_8_and_10(void){
   // printf("No5.2 - timesEvenNumber\n");
   // TEST_ASSERT_EQUAL(0xae,timesEvenNumber(0x57,2));
   // TEST_ASSERT_EQUAL(0x47,timesEvenNumber(0x57,4));
   // TEST_ASSERT_EQUAL(0x8e,timesEvenNumber(0x57,8));
   // TEST_ASSERT_EQUAL(0x07,timesEvenNumber(0x57,10));
// }


void test_multiWithXRO_given_0x57_and_0x83_expected_0x2b79(void){
    printf("No5.3 - multiWithXRO\n");
    TEST_ASSERT_EQUAL(0x2b79,multiWithXRO(0x57,0x83));
    TEST_ASSERT_EQUAL(0x0,multiWithXRO(0x57,0x0));
    TEST_ASSERT_EQUAL(0x0,multiWithXRO(0x0,0x2));
    TEST_ASSERT_EQUAL(0x2,multiWithXRO(0x1,0x2));
    TEST_ASSERT_EQUAL(0x8,multiWithXRO(0x4,0x2));
    TEST_ASSERT_EQUAL(0x570,multiWithXRO(0x57,0x10));
    TEST_ASSERT_EQUAL(0x570,multiWithXRO(0x10,0x57));
    TEST_ASSERT_EQUAL(0x20,multiWithXRO(0x10,0x2));
    printf("0xF1*0x03 = 0x%x , multiWithXRO(0xf1,0x03) = 0x%x\n",(0xf1*0x03),multiWithXRO(0xf1,0x03));
//    printf("multiInGF(0xf1,0x03) = 0x%x, timesThree(0xf1) = 0x%x",multiInGF(0xf1,0x03),timesThree(0xf1));
    
    
}

void test_module0x11bWithXRO_(void){
  printf("No5.4 - module0x11bWithXRO\n");
  //printf("module0x11bWithXRO(0x110) = 0x%x",module0x11bWithXRO(0x110));
  TEST_ASSERT_EQUAL(0xb,module0x11bWithXRO(0x110));
}

void test_multiInGF_given_0x57_and_times_14_expected_(void){
  printf("No5.5 - multiInGF\n");
  TEST_ASSERT_EQUAL(0xae,multiInGF(0x57,0x02));
  TEST_ASSERT_EQUAL(0xfe,multiInGF(0x57,0x13));
  TEST_ASSERT_EQUAL(0x07,multiInGF(0x57,0x10));
  TEST_ASSERT_EQUAL(0x47,multiInGF(0x57,0x04));
  TEST_ASSERT_EQUAL(0x57,multiInGF(0x57,0x01));  
}








