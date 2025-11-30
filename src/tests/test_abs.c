#include "test_framework.h"
#include "../waffle/math.h"

/* Test cases for waffle_abs() function */
int test_abs_positive(void)
{
    TEST_ASSERT_EQ(5, waffle_abs(5), "waffle_abs(5) should be 5");
    TEST_ASSERT_EQ(100, waffle_abs(100), "waffle_abs(100) should be 100");
    TEST_ASSERT_EQ(1, waffle_abs(1), "waffle_abs(1) should be 1");
    return TEST_PASSED;
}

int test_abs_negative(void)
{
    TEST_ASSERT_EQ(5, waffle_abs(-5), "waffle_abs(-5) should be 5");
    TEST_ASSERT_EQ(100, waffle_abs(-100), "waffle_abs(-100) should be 100");
    TEST_ASSERT_EQ(1, waffle_abs(-1), "waffle_abs(-1) should be 1");
    return TEST_PASSED;
}

int test_abs_zero(void)
{
    TEST_ASSERT_EQ(0, waffle_abs(0), "waffle_abs(0) should be 0");
    return TEST_PASSED;
}

/* Test cases for waffle_labs() function */
int test_labs_positive(void)
{
    TEST_ASSERT_EQ(5L, waffle_labs(5L), "waffle_labs(5) should be 5");
    TEST_ASSERT_EQ(1000000L, waffle_labs(1000000L), "waffle_labs(1000000) should be 1000000");
    return TEST_PASSED;
}

int test_labs_negative(void)
{
    TEST_ASSERT_EQ(5L, waffle_labs(-5L), "waffle_labs(-5) should be 5");
    TEST_ASSERT_EQ(1000000L, waffle_labs(-1000000L), "waffle_labs(-1000000) should be 1000000");
    return TEST_PASSED;
}

int test_labs_zero(void)
{
    TEST_ASSERT_EQ(0L, waffle_labs(0L), "waffle_labs(0) should be 0");
    return TEST_PASSED;
}

/* Test cases for waffle_llabs() function */
int test_llabs_positive(void)
{
    TEST_ASSERT_EQ(5LL, waffle_llabs(5LL), "waffle_llabs(5) should be 5");
    TEST_ASSERT_EQ(9223372036854775807LL, waffle_llabs(9223372036854775807LL), 
                   "waffle_llabs(LLONG_MAX) should be LLONG_MAX");
    return TEST_PASSED;
}

int test_llabs_negative(void)
{
    TEST_ASSERT_EQ(5LL, waffle_llabs(-5LL), "waffle_llabs(-5) should be 5");
    TEST_ASSERT_EQ(1000000000000LL, waffle_llabs(-1000000000000LL), 
                   "waffle_llabs(-1000000000000) should be 1000000000000");
    return TEST_PASSED;
}

int test_llabs_zero(void)
{
    TEST_ASSERT_EQ(0LL, waffle_llabs(0LL), "waffle_llabs(0) should be 0");
    return TEST_PASSED;
}

/* Test cases for waffle_fabs() function */
int test_fabs_positive(void)
{
    TEST_ASSERT_FLOAT_EQ(5.5, waffle_fabs(5.5), 0.0001, "waffle_fabs(5.5) should be 5.5");
    TEST_ASSERT_FLOAT_EQ(3.14159, waffle_fabs(3.14159), 0.0001, "waffle_fabs(3.14159) should be 3.14159");
    return TEST_PASSED;
}

int test_fabs_negative(void)
{
    TEST_ASSERT_FLOAT_EQ(5.5, waffle_fabs(-5.5), 0.0001, "waffle_fabs(-5.5) should be 5.5");
    TEST_ASSERT_FLOAT_EQ(3.14159, waffle_fabs(-3.14159), 0.0001, "waffle_fabs(-3.14159) should be 3.14159");
    return TEST_PASSED;
}

int test_fabs_zero(void)
{
    TEST_ASSERT_FLOAT_EQ(0.0, waffle_fabs(0.0), 0.0001, "waffle_fabs(0.0) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0, waffle_fabs(-0.0), 0.0001, "waffle_fabs(-0.0) should be 0.0");
    return TEST_PASSED;
}

/* Test cases for waffle_fabsf() function */
int test_fabsf_positive(void)
{
    TEST_ASSERT_FLOAT_EQ(5.5f, waffle_fabsf(5.5f), 0.0001f, "waffle_fabsf(5.5) should be 5.5");
    return TEST_PASSED;
}

int test_fabsf_negative(void)
{
    TEST_ASSERT_FLOAT_EQ(5.5f, waffle_fabsf(-5.5f), 0.0001f, "waffle_fabsf(-5.5) should be 5.5");
    return TEST_PASSED;
}

int test_fabsf_zero(void)
{
    TEST_ASSERT_FLOAT_EQ(0.0f, waffle_fabsf(0.0f), 0.0001f, "waffle_fabsf(0.0) should be 0.0");
    return TEST_PASSED;
}

/* Test cases for waffle_fabsl() function */
int test_fabsl_positive(void)
{
    TEST_ASSERT_FLOAT_EQ(5.5L, waffle_fabsl(5.5L), 0.0001L, "waffle_fabsl(5.5) should be 5.5");
    return TEST_PASSED;
}

int test_fabsl_negative(void)
{
    TEST_ASSERT_FLOAT_EQ(5.5L, waffle_fabsl(-5.5L), 0.0001L, "waffle_fabsl(-5.5) should be 5.5");
    return TEST_PASSED;
}

int test_fabsl_zero(void)
{
    TEST_ASSERT_FLOAT_EQ(0.0L, waffle_fabsl(0.0L), 0.0001L, "waffle_fabsl(0.0) should be 0.0");
    return TEST_PASSED;
}

int main(void)
{
    printf("========================================\n");
    printf("Waffle Math Library - Unit Tests\n");
    printf("========================================\n\n");

    printf("--- Testing waffle_abs() ---\n");
    RUN_TEST(test_abs_positive);
    RUN_TEST(test_abs_negative);
    RUN_TEST(test_abs_zero);

    printf("\n--- Testing waffle_labs() ---\n");
    RUN_TEST(test_labs_positive);
    RUN_TEST(test_labs_negative);
    RUN_TEST(test_labs_zero);

    printf("\n--- Testing waffle_llabs() ---\n");
    RUN_TEST(test_llabs_positive);
    RUN_TEST(test_llabs_negative);
    RUN_TEST(test_llabs_zero);

    printf("\n--- Testing waffle_fabs() ---\n");
    RUN_TEST(test_fabs_positive);
    RUN_TEST(test_fabs_negative);
    RUN_TEST(test_fabs_zero);

    printf("\n--- Testing waffle_fabsf() ---\n");
    RUN_TEST(test_fabsf_positive);
    RUN_TEST(test_fabsf_negative);
    RUN_TEST(test_fabsf_zero);

    printf("\n--- Testing waffle_fabsl() ---\n");
    RUN_TEST(test_fabsl_positive);
    RUN_TEST(test_fabsl_negative);
    RUN_TEST(test_fabsl_zero);

    TEST_SUMMARY();
    
    return TEST_EXIT_CODE();
}
