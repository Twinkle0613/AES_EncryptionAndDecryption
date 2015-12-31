/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
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

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_multiWithXRO_given_0x57_and_0x83_expected_0x2b79(void);
extern void test_module0x11bWithXRO_(void);
extern void test_multiInGF_given_0x57_and_times_14_expected_(void);
extern void test_mixColumns_given_state2_and_expected_equal_exState(void);
extern void test_mixColumns_given_state3_and_expected_equal_exState(void);
extern void test_invMixColumns_given_state_and_expected_equal_exState(void);
extern void test_invMixColumns_given_state2_and_expected_equal_exState(void);


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
  UnityBegin("test_MixColumns.c");
  RUN_TEST(test_multiWithXRO_given_0x57_and_0x83_expected_0x2b79, 12);
  RUN_TEST(test_module0x11bWithXRO_, 26);
  RUN_TEST(test_multiInGF_given_0x57_and_times_14_expected_, 32);
  RUN_TEST(test_mixColumns_given_state2_and_expected_equal_exState, 42);
  RUN_TEST(test_mixColumns_given_state3_and_expected_equal_exState, 56);
  RUN_TEST(test_invMixColumns_given_state_and_expected_equal_exState, 72);
  RUN_TEST(test_invMixColumns_given_state2_and_expected_equal_exState, 87);

  return (UnityEnd());
}
