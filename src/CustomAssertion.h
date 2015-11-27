#ifndef CustomAssertion_H
#define CustomAssertion_H


#include "unity.h"

void customTestAssertEqualValue(uint8_t expValue,uint8_t actValue,int lineNo,char* msg,...);

void customTestAssertEqualState(uint8_t expState[][4] , uint8_t actState[][4], int lineNo);
#define TEST_ASSERT_EQUAL_STATE(expState,actState){               \
   customTestAssertEqualState(expState,actState,__LINE__);        \
}


#define CUSTOM_TEST_FAIL(lineNo,msg,...)                        \
        {                                                       \
         char buffer[256];                                      \
         sprintf(buffer,msg, ## __VA_ARGS__);                   \
         UNITY_TEST_FAIL(lineNo,buffer);                        \
        }


#endif // CustomAssertion_H
