/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_convKeyToWord_given_key_123456789ABCDEFG(void);
extern void test_rotWord_given_0x31323334_and_expected_0x34313233(void);
extern void test_rotWord_given_0x2a6c7605_and_expected_0x6c76052a(void);
extern void test_rotWord_given_0x7359f67f_and_expected_0x59f67f73(void);
extern void test_subWord_given_0xcf4f3c09_expected_0x8a84eb01(void);
extern void test_subWord_given_0x6c76052a_expected_0x50386be5(void);
extern void test_keyExpansion_given_128_bit_cipher_key(void);
extern void test_keyExpansion_given_192_bit_cipher_key(void);
extern void test_keyExpansion_given_256_bit_cipher_key(void);


//=======Test Reset Option=====
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  UnityBegin("test_KeyExpansion.c");
  RUN_TEST(test_convKeyToWord_given_key_123456789ABCDEFG, 24);
  RUN_TEST(test_rotWord_given_0x31323334_and_expected_0x34313233, 58);
  RUN_TEST(test_rotWord_given_0x2a6c7605_and_expected_0x6c76052a, 67);
  RUN_TEST(test_rotWord_given_0x7359f67f_and_expected_0x59f67f73, 75);
  RUN_TEST(test_subWord_given_0xcf4f3c09_expected_0x8a84eb01, 97);
  RUN_TEST(test_subWord_given_0x6c76052a_expected_0x50386be5, 105);
  RUN_TEST(test_keyExpansion_given_128_bit_cipher_key, 124);
  RUN_TEST(test_keyExpansion_given_192_bit_cipher_key, 141);
  RUN_TEST(test_keyExpansion_given_256_bit_cipher_key, 156);

  return (UnityEnd());
}
