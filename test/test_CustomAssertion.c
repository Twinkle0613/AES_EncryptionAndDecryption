#include "unity.h"
#include "CustomAssertion.h"
#include <stdint.h>
#include <stdlib.h>

#include "Encryption.h"
void setUp(void){}

void tearDown(void){}
/*
void xtest_customTestAssertEqualState_actState_is_a_NULL(void){
  
  uint8_t** actState = NULL;
  uint8_t** expState = creat2DArray4x4();
  TEST_ASSERT_EQUAL_STATE(expState,actState);
  
  
}

void xtest_customTestAssertEqualState_expState_is_a_NULL(void){
  
  uint8_t** actState = creat2DArray4x4();
  uint8_t** expState = NULL ;
  //uint8_t expState[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}  };
  TEST_ASSERT_EQUAL_STATE(expState,actState);
  
  
}



void xtest_customTestAssertEqualState_given_str_array_that_should_return_true(void){
  uint8_t in[] = "0123456789abcdef";
  uint8_t in2[] = "0123456789abcdff";
  //uint8_t in[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
  uint8_t** actState = convInputToState(in);
  uint8_t** expState = convInputToState(in2) ;
  TEST_ASSERT_EQUAL_STATE(expState,actState);
  
  
}


void xtest_customTestAssertEqualState_given_hec_array_that_should_return_true(void){
  uint8_t in[] = {0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,0x53};
  uint8_t in2[] = {0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,0x53};
  uint8_t** actState = convInputToState(in);
  uint8_t** expState = convInputToState(in2) ;
  TEST_ASSERT_EQUAL_STATE(expState,actState); 
}


void xtest_customTestAssertEqualState_given_hec_and_str_array_that_should_return_true(void){
  uint8_t in[] = {0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4a,0x4b,0x4c,0x4d,0x4e,0x4f,0x50};
  uint8_t in2[] = "ABCDEFGHIJKLMNOP";
  uint8_t** actState = convInputToState(in);
  uint8_t** expState = convInputToState(in2) ;
  TEST_ASSERT_EQUAL_STATE(expState,actState);
  
  
}
*/