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
extern void test_shift_given_ABCDEFGHIJKLMNOP_expected_equal_exState(void);
extern void test_shiftRow_given_ABCDEFGHIJKLMNOP_expected_equal_exState(void);
extern void test_shiftRow_given_state_and_expected_euqal_exState(void);
extern void test_invShiftRow_given_ABCDEFGHIJKLMNOP_expected_result_is_ANKHEBOLIFCPMJGD(void);
extern void test_invShiftRow_given_123456789ABCEFG_expected_result_is_ANKHEBOLIFCPMJGD(void);


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
  UnityBegin("test_ShiftRows.c");
  RUN_TEST(test_shift_given_ABCDEFGHIJKLMNOP_expected_equal_exState, 24);
  RUN_TEST(test_shiftRow_given_ABCDEFGHIJKLMNOP_expected_equal_exState, 51);
  RUN_TEST(test_shiftRow_given_state_and_expected_euqal_exState, 66);
  RUN_TEST(test_invShiftRow_given_ABCDEFGHIJKLMNOP_expected_result_is_ANKHEBOLIFCPMJGD, 85);
  RUN_TEST(test_invShiftRow_given_123456789ABCEFG_expected_result_is_ANKHEBOLIFCPMJGD, 101);

  return (UnityEnd());
}
