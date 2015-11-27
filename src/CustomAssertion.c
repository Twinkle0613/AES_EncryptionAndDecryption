#include "CustomAssertion.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include "unity.h"
void customTestAssertEqualState(uint8_t expState[][4] , uint8_t actState[][4], int lineNo){
  
  if( expState == NULL ){
    CUSTOM_TEST_FAIL(lineNo,"expState should not be a NULL."); 
  }
  if( actState == NULL ){
    CUSTOM_TEST_FAIL(lineNo,"actState should not be a NULL."); 
  }
  
  int row,col;
  for(col = 0; col < 4 ; col++){
   for(row = 0; row < 4 ; row++){
   customTestAssertEqualValue(actState[row][col],expState[row][col],lineNo,"Expected %x(Hex) was %x(Hex) in [%d][%d].",expState[row][col],actState[row][col],row,col);
   }
  }
}


void customTestAssertEqualValue(uint8_t expectValue,uint8_t actualValue,int lineNo,char* msg,...){
  char *msgBuffer = malloc(1024);
  va_list args;
  va_start(args,msg);
  vsprintf(msgBuffer, msg,args);
  UNITY_TEST_ASSERT_EQUAL_INT8(actualValue,expectValue,lineNo,msgBuffer);
  va_end(args);
}
