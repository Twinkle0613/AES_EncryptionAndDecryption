#include "unity.h"
#include "Encryption.h"
#include <stdint.h>
#include "CustomAssertion.h"
void setUp(void)
{
}

void tearDown(void)
{
}

void test_convStrToState_(void){
  printf("No.1 - convStrToState\n");
  char* str = "ABCDEFGHIJKLMNOP";
  uint8_t state[4][4];
  convStrToState(str,state);
  TEST_ASSERT_EQUAL_UINT8('A',state[0][0]);
  TEST_ASSERT_EQUAL_UINT8('B',state[1][0]);
  TEST_ASSERT_EQUAL_UINT8('C',state[2][0]);
  TEST_ASSERT_EQUAL_UINT8('D',state[3][0]);
  TEST_ASSERT_EQUAL_UINT8('E',state[0][1]);
  TEST_ASSERT_EQUAL_UINT8('P',state[3][3]);
  printfState(state);
}

void test_subBytes_(void){
  printf("No.2 - subBytes\n");
  uint8_t exState[4][4] = {{0x83,0x6e,0x3b,0xe3},    \
                           {0x2c,0x5a,0xd6,0x2f},    \
                           {0x1a,0xa0,0xb3,0x84},    \
                           {0x1b,0x52,0x29,0x53} };  
  char* str = "ABCDEFGHIJKLMNOP";
  uint8_t state[4][4];
  convStrToState(str,state);
  subBytes(state);
  printfState(state);
  TEST_ASSERT_EQUAL_STATE(exState,state);
  
}

void test_mixColumns_in(void){
  printf("No3 - mixColumns\n");
  uint8_t state[4][4] = { {0xd4,0xe0,0xb8,0x1e},    \
                          {0xbf,0xb4,0x41,0x27},    \
                          {0x5d,0x52,0x11,0x98},    \
                          {0x30,0xae,0xf1,0xe5}  }; 
                           
  uint8_t exState[4][4] = {{0x04,0xe0,0x48,0x28},    \
                           {0x66,0xcb,0xf8,0x06},    \
                           {0x81,0x19,0xd3,0x26},    \
                           {0xe5,0x9a,0x7a,0x4c} }; 
  printfState(state);
  mixColumns(state);
  printfState(state);
  TEST_ASSERT_EQUAL_STATE(exState,state);
  
}


void test_xtime(void){
  int value1,value2,value3,value4;
  printf("\n");
  printf("0) %x %x %x %x \n",timesTwo(0xd4) , timesThree(0xbf) , 0x5d , 0x30);
  value1 = timesTwo(0xd4) ^ timesThree(0xbf) ^ 0x5d ^ 0x30;
  printf("1) %x %x %x %x \n",0xd4 , timesTwo(0xbf) , timesThree(0x5d)  , 0x30);
  value2 =  0xd4 ^ timesTwo(0xbf) ^ timesThree(0x5d)  ^ 0x30;
  printf("2) %x %x %x %x \n",0xd4 , 0xbf , timesTwo(0x5d) , timesThree(0x30));
  value3 = 0xd4 ^ 0xbf ^ timesTwo(0x5d) ^ timesThree(0x30);
  printf("3) %x %x %x %x \n", timesThree(0xd4) , 0xbf , 0x5d , timesTwo(0x30)); 
 value4 = timesThree(0xd4) ^ 0xbf ^ 0x5d ^ timesTwo(0x30);
  
  // printf(" state[0][0] = %x\n",value1);
  // printf(" state[1][0] = %x\n",value2);
  // printf(" state[2][0] = %x\n",value3);
  // printf(" state[3][0] = %x\n",value4);
  printf("\n");
  printf("0) %x %x %x %x \n",timesTwo(0xe0) , timesThree(0xb4) , 0x52 , 0xae);
  value1 = timesTwo(0xe0) ^ timesThree(0xb4) ^ 0x52 ^ 0xae;
  printf("1) %x %x %x %x \n",0xe0 , timesTwo(0xb4) , timesThree(0x52)  , 0xae);
  value2 =  0xe0 ^ timesTwo(0xb4) ^ timesThree(0x52)  ^ 0xae;
  printf("2) %x %x %x %x \n",0xe0 , 0xb4 , timesTwo(0x52) , timesThree(0xae));
  value3 = 0xe0 ^ 0xb4 ^ timesTwo(0x52) ^ timesThree(0xae);
  printf("3) %x %x %x %x \n", timesThree(0xe0) , 0xb4 , 0x52 , timesTwo(0xae));
  value4 = timesThree(0xe0) ^ 0xb4 ^ 0x52 ^ timesTwo(0xae);
  
  // printf(" state[0][1] = %x\n",value1);
  // printf(" state[1][1] = %x\n",value2);
  // printf(" state[2][1] = %x\n",value3);
  // printf(" state[3][1] = %x\n",value4);
  printf("\n");
  printf("0) %x %x %x %x \n",timesTwo(0xb8) , timesThree(0x41) , 0x11 , 0xf1);
  value1 = timesTwo(0xb8) ^ timesThree(0x41) ^ 0x11 ^ 0xf1;
  printf("1) %x %x %x %x \n",0xb8 , timesTwo(0x41) , timesThree(0x11)  , 0xf1);
  value2 =  0xb8 ^ timesTwo(0x41) ^ timesThree(0x11)  ^ 0xf1;
  printf("2) %x %x %x %x \n",0xb8 , 0x41 , timesTwo(0x11) , timesThree(0xf1));
  value3 = 0xb8 ^ 0x41 ^ timesTwo(0x11) ^ timesThree(0xf1);
  printf("3) %x %x %x %x \n", timesThree(0xb8) , 0x41 , 0x11 , timesTwo(0xf1));
  value4 = timesThree(0xb8) ^ 0x41 ^ 0x11 ^ timesTwo(0xf1);
  
  // printf(" state[0][2] = %x\n",value1);
  // printf(" state[1][2] = %x\n",value2);
  // printf(" state[2][2] = %x\n",value3);
  // printf(" state[3][2] = %x\n",value4);
  printf("\n");
  printf("0) %x %x %x %x \n",timesTwo(0x1e) , timesThree(0x27) , 0x98 , 0xe5);
  value1 = timesTwo(0x1e) ^ timesThree(0x27) ^ 0x98 ^ 0xe5;
  printf("1) %x %x %x %x \n",0x1e , timesTwo(0x27) , timesThree(0x98)  , 0xe5);
  value2 =  0x1e ^ timesTwo(0x27) ^ timesThree(0x98)  ^ 0xe5;
  printf("2) %x %x %x %x \n",0x1e , 0x27 , timesTwo(0x98) , timesThree(0xe5));
  value3 = 0x1e ^ 0x27 ^ timesTwo(0x98) ^ timesThree(0xe5);
  printf("3) %x %x %x %x \n", timesThree(0x1e) , 0x27 , 0x98 , timesTwo(0xe5));
  value4 = timesThree(0x1e) ^ 0x27 ^ 0x98 ^ timesTwo(0xe5);
  
  // printf(" state[0][3] = %x\n",value1);
  // printf(" state[1][3] = %x\n",value2);
  // printf(" state[2][3] = %x\n",value3);
  // printf(" state[3][3] = %x\n",value4);
}
