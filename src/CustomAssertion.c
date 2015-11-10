#include "CustomAssertion.h"
#include <stdint.h>
#include <stdlib.h>

#include "unity.h"
void customTestAssertEqualState(uint8_t** expState , uint8_t** actState, int lineNo){
  
  if( expState == NULL ){
    CUSTOM_TEST_FAIL(lineNo,"expState should not be a NULL."); 
  }
  if( actState == NULL ){
    CUSTOM_TEST_FAIL(lineNo,"actState should not be a NULL."); 
  }
  
  int row,col;
  for(col = 0; col < 4 ; col++){
   for(row = 0; row < 4 ; row++){
    UNITY_TEST_ASSERT_EQUAL_INT8(actState[row][col],expState[row][col],lineNo,"The expected state is not same with the actual state.");
    }
  }
}