#include "CustomAssertion.h"
#include "unity.h"




void setUp(void){}



void tearDown(void){}

void test_convInputToState_given_ABCDEFGHIJKLMNOP(void){



  UnityIgnore( ("test_convInputToState_given_ABCDEFGHIJKLMNOP"), (_U_UINT)26);;

  uint8_t in[] = "ABCDEFGHIJKLMNOP";

  uint8_t **state;

  int col,row;

  state = convInputToState(in);

  printState(state);

  for(col = 0; col < 4 ; col++){

   for(row = 0; row < 4 ; row++){

     UnityAssertEqualNumber((_U_SINT)((in[row + (4*col)])), (_U_SINT)((state[row][col])), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

    }

  }

}

void test_subBytes(void){

  printf("test_subBytes\n");



  uint8_t in2[] = {0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,0x53};

  uint8_t in[] = "ABCDEFGHIJKLMNOP";

  uint8_t** expState = convInputToState(in2) ;

  uint8_t **state = convInputToState(in);

  printState(state);

  subBytes(state);

  printf("-----S-BOX-----\n");

  printState(state);

  { customTestAssertEqualState(expState,state,66); };



}
