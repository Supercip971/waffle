#include "test_framework.h"
#include "test_values.h"
#define WAFFLE_NO_PREFIX
#include "../waffle/math.h"
#include <math.h>  /* libc math functions for comparison */

/* Forward declarations */
void run_trunc_tests(void);

/* Test cases for waffle_truncf() function */
static int test_truncf_positive(void)
{
    TEST_ASSERT_FLOAT_EQ(5.0f, waffle_truncf(5.7f), 0.0001f, "waffle_truncf(5.7) should be 5.0");
    TEST_ASSERT_FLOAT_EQ(3.0f, waffle_truncf(3.14159f), 0.0001f, "waffle_truncf(3.14159) should be 3.0");
    TEST_ASSERT_FLOAT_EQ(100.0f, waffle_truncf(100.999f), 0.0001f, "waffle_truncf(100.999) should be 100.0");
    TEST_ASSERT_FLOAT_EQ(1.0f, waffle_truncf(1.0f), 0.0001f, "waffle_truncf(1.0) should be 1.0");
    return TEST_PASSED;
}

static int test_truncf_negative(void)
{
    TEST_ASSERT_FLOAT_EQ(-5.0f, waffle_truncf(-5.7f), 0.0001f, "waffle_truncf(-5.7) should be -5.0");
    TEST_ASSERT_FLOAT_EQ(-3.0f, waffle_truncf(-3.14159f), 0.0001f, "waffle_truncf(-3.14159) should be -3.0");
    TEST_ASSERT_FLOAT_EQ(-100.0f, waffle_truncf(-100.999f), 0.0001f, "waffle_truncf(-100.999) should be -100.0");
    TEST_ASSERT_FLOAT_EQ(-1.0f, waffle_truncf(-1.0f), 0.0001f, "waffle_truncf(-1.0) should be -1.0");

    return TEST_PASSED;
}

static int test_truncf_zero(void)
{
    TEST_ASSERT_FLOAT_EQ(0.0f, waffle_truncf(0.0f), 0.0001f, "waffle_truncf(0.0) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0f, waffle_truncf(-0.0f), 0.0001f, "waffle_truncf(-0.0) should be 0.0");
    return TEST_PASSED;
}

static int test_truncf_fractional_less_than_one(void)
{
    TEST_ASSERT_FLOAT_EQ(0.0f, waffle_truncf(0.5f), 0.0001f, "waffle_truncf(0.5) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0f, waffle_truncf(0.999f), 0.0001f, "waffle_truncf(0.999) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0f, waffle_truncf(-0.5f), 0.0001f, "waffle_truncf(-0.5) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0f, waffle_truncf(-0.999f), 0.0001f, "waffle_truncf(-0.999) should be 0.0");
    return TEST_PASSED;
}

static int test_truncf_large_values(void)
{
    TEST_ASSERT_FLOAT_EQ(1000000.0f, waffle_truncf(1000000.5f), 0.0001f, "waffle_truncf(1000000.5) should be 1000000.0");
    TEST_ASSERT_FLOAT_EQ(-1000000.0f, waffle_truncf(-1000000.5f), 0.0001f, "waffle_truncf(-1000000.5) should be -1000000.0");
    return TEST_PASSED;
}

static int test_truncf_special_values(void)
{
    /* Test infinity */
    TEST_ASSERT(waffle_truncf(INFINITY) == INFINITY, "waffle_truncf(INFINITY) should be INFINITY");
    TEST_ASSERT(waffle_truncf(-INFINITY) == -INFINITY, "waffle_truncf(-INFINITY) should be -INFINITY");

    /* Test NaN - NaN != NaN, so we check using the property */
    float nan_result = waffle_truncf(NAN);
    TEST_ASSERT(nan_result != nan_result, "waffle_truncf(NAN) should be NAN");
    return TEST_PASSED;
}

/* Test cases for waffle_trunc() function */
static int test_trunc_positive(void)
{
    TEST_ASSERT_FLOAT_EQ(5.0, waffle_trunc(5.7), 0.0001, "waffle_trunc(5.7) should be 5.0");
    TEST_ASSERT_FLOAT_EQ(3.0, waffle_trunc(3.14159265358979), 0.0001, "waffle_trunc(3.14159...) should be 3.0");
    TEST_ASSERT_FLOAT_EQ(100.0, waffle_trunc(100.999), 0.0001, "waffle_trunc(100.999) should be 100.0");
    TEST_ASSERT_FLOAT_EQ(1.0, waffle_trunc(1.0), 0.0001, "waffle_trunc(1.0) should be 1.0");
    return TEST_PASSED;
}

static int test_trunc_negative(void)
{
    TEST_ASSERT_FLOAT_EQ(-5.0, waffle_trunc(-5.7), 0.0001, "waffle_trunc(-5.7) should be -5.0");
    TEST_ASSERT_FLOAT_EQ(-3.0, waffle_trunc(-3.14159265358979), 0.0001, "waffle_trunc(-3.14159...) should be -3.0");
    TEST_ASSERT_FLOAT_EQ(-100.0, waffle_trunc(-100.999), 0.0001, "waffle_trunc(-100.999) should be -100.0");
    TEST_ASSERT_FLOAT_EQ(-1.0, waffle_trunc(-1.0), 0.0001, "waffle_trunc(-1.0) should be -1.0");
    return TEST_PASSED;
}

static int test_trunc_zero(void)
{
    TEST_ASSERT_FLOAT_EQ(0.0, waffle_trunc(0.0), 0.0001, "waffle_trunc(0.0) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0, waffle_trunc(-0.0), 0.0001, "waffle_trunc(-0.0) should be 0.0");
    return TEST_PASSED;
}

static int test_trunc_fractional_less_than_one(void)
{

    TEST_ASSERT_FLOAT_EQ(0.0, waffle_trunc(0.5), 0.0001, "waffle_trunc(0.5) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0, waffle_trunc(0.999999999), 0.0001, "waffle_trunc(0.999999999) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0, waffle_trunc(-0.5), 0.0001, "waffle_trunc(-0.5) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0, waffle_trunc(-0.999999999), 0.0001, "waffle_trunc(-0.999999999) should be 0.0");
    return TEST_PASSED;
}

static int test_trunc_large_values(void)
{
    TEST_ASSERT_FLOAT_EQ(1000000000000.0, waffle_trunc(1000000000000.5), 0.0001, "waffle_trunc(1000000000000.5) should be 1000000000000.0");
    TEST_ASSERT_FLOAT_EQ(-1000000000000.0, waffle_trunc(-1000000000000.5), 0.0001, "waffle_trunc(-1000000000000.5) should be -1000000000000.0");
    return TEST_PASSED;
}

static int test_trunc_special_values(void)
{
    /* Test infinity */
    TEST_ASSERT(waffle_trunc(INFINITY) == INFINITY, "waffle_trunc(INFINITY) should be INFINITY");
    TEST_ASSERT(waffle_trunc(-INFINITY) == -INFINITY, "waffle_trunc(-INFINITY) should be -INFINITY");

    /* Test NaN */
    double nan_result = waffle_trunc(NAN);
    TEST_ASSERT(nan_result != nan_result, "waffle_trunc(NAN) should be NAN");
    return TEST_PASSED;
}

/* Test cases for waffle_truncl() function */
static int test_truncl_positive(void)
{
    TEST_ASSERT_FLOAT_EQ(5.0L, waffle_truncl(5.7L), 0.0001L, "waffle_truncl(5.7) should be 5.0");
    TEST_ASSERT_FLOAT_EQ(3.0L, waffle_truncl(3.14159265358979323846L), 0.0001L, "waffle_truncl(3.14159...) should be 3.0");
    TEST_ASSERT_FLOAT_EQ(100.0L, waffle_truncl(100.999L), 0.0001L, "waffle_truncl(100.999) should be 100.0");
    return TEST_PASSED;
}

static int test_truncl_negative(void)
{
    TEST_ASSERT_FLOAT_EQ(-5.0L, waffle_truncl(-5.7L), 0.0001L, "waffle_truncl(-5.7) should be -5.0");
    TEST_ASSERT_FLOAT_EQ(-3.0L, waffle_truncl(-3.14159265358979323846L), 0.0001L, "waffle_truncl(-3.14159...) should be -3.0");
    TEST_ASSERT_FLOAT_EQ(-100.0L, waffle_truncl(-100.999L), 0.0001L, "waffle_truncl(-100.999) should be -100.0");
    return TEST_PASSED;
}

static int test_truncl_zero(void)
{
    TEST_ASSERT_FLOAT_EQ(0.0L, waffle_truncl(0.0L), 0.0001L, "waffle_truncl(0.0) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0L, waffle_truncl(-0.0L), 0.0001L, "waffle_truncl(-0.0) should be 0.0");
    return TEST_PASSED;
}

static int test_truncl_fractional_less_than_one(void)
{
    TEST_ASSERT_FLOAT_EQ(0.0L, waffle_truncl(0.5L), 0.0001L, "waffle_truncl(0.5) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0L, waffle_truncl(0.999999999999L), 0.0001L, "waffle_truncl(0.999...) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0L, waffle_truncl(-0.5L), 0.0001L, "waffle_truncl(-0.5) should be 0.0");
    TEST_ASSERT_FLOAT_EQ(0.0L, waffle_truncl(-0.999999999999L), 0.0001L, "waffle_truncl(-0.999...) should be 0.0");
    return TEST_PASSED;
}

static int test_truncl_special_values(void)
{
    /* Test infinity */
    TEST_ASSERT(waffle_truncl(INFINITY) == INFINITY, "waffle_truncl(INFINITY) should be INFINITY");
    TEST_ASSERT(waffle_truncl(-INFINITY) == -INFINITY, "waffle_truncl(-INFINITY) should be -INFINITY");

    /* Test NaN */
    long double nan_result = waffle_truncl(NAN);
    TEST_ASSERT(nan_result != nan_result, "waffle_truncl(NAN) should be NAN");
    return TEST_PASSED;
}

/* ============================================================
 * Comprehensive tests comparing against libc functions
 * ============================================================ */

/* Test float values against libc truncf */
static int test_truncf_vs_libc(void)
{
    for (size_t i = 0; i < TEST_FLOAT_VALUES_COUNT; i++) {
        float input = TEST_FLOAT_VALUES[i];
        float expected = truncf(input);  /* libc */
        float actual = waffle_truncf(input);
        
        /* Handle NaN comparison */
        if (expected != expected && actual != actual) {
            continue;  /* Both NaN, OK */
        }
        
        if (expected != actual) {
            printf("  [FAIL] waffle_truncf(%g) = %g, expected %g (libc)\n", 
                   input, actual, expected);
            _test_count++;
            _test_failed++;
            return TEST_FAILED;
        }
    }
    
    _test_count++;
    _test_passed++;
    return TEST_PASSED;
}

/* Test double values against libc trunc */
static int test_trunc_vs_libc(void)
{
    /* Test main values */
    for (size_t i = 0; i < TEST_DOUBLE_VALUES_COUNT; i++) {
        double input = TEST_DOUBLE_VALUES[i];
        double expected = trunc(input);  /* libc */
        double actual = waffle_trunc(input);
        
        /* Handle NaN comparison */
        if (expected != expected && actual != actual) {
            continue;  /* Both NaN, OK */
        }
        
        if (expected != actual) {
            printf("  [FAIL] waffle_trunc(%g) = %g, expected %g (libc)\n", 
                   input, actual, expected);
            _test_count++;
            _test_failed++;
            return TEST_FAILED;
        }
    }
    
    /* Test mantissa edge cases */
    for (size_t i = 0; i < TEST_DOUBLE_MANTISSA_EDGE_COUNT; i++) {
        double input = TEST_DOUBLE_MANTISSA_EDGE[i];
        double expected = trunc(input);  /* libc */
        double actual = waffle_trunc(input);
        
        if (expected != actual) {
            printf("  [FAIL] waffle_trunc(%g) = %g, expected %g (libc)\n", 
                   input, actual, expected);
            _test_count++;
            _test_failed++;
            return TEST_FAILED;
        }
    }
    
    _test_count++;
    _test_passed++;
    return TEST_PASSED;
}

/* Test long double values against libc truncl */
static int test_truncl_vs_libc(void)
{
    /* Test main values */
    for (size_t i = 0; i < TEST_LONG_DOUBLE_VALUES_COUNT; i++) {
        long double input = TEST_LONG_DOUBLE_VALUES[i];
        long double expected = truncl(input);  /* libc */
        long double actual = waffle_truncl(input);
        
        /* Handle NaN comparison */
        if (expected != expected && actual != actual) {
            continue;  /* Both NaN, OK */
        }
        
        if (expected != actual) {
            printf("  [FAIL] waffle_truncl(%Lg) = %Lg, expected %Lg (libc)\n", 
                   input, actual, expected);
            _test_count++;
            _test_failed++;
            return TEST_FAILED;
        }
    }
    
    /* Test mantissa edge cases */
    for (size_t i = 0; i < TEST_LONG_DOUBLE_MANTISSA_EDGE_COUNT; i++) {
        long double input = TEST_LONG_DOUBLE_MANTISSA_EDGE[i];
        long double expected = truncl(input);  /* libc */
        long double actual = waffle_truncl(input);
        
        if (expected != actual) {
            printf("  [FAIL] waffle_truncl(%Lg) = %Lg, expected %Lg (libc)\n", 
                   input, actual, expected);
            _test_count++;
            _test_failed++;
            return TEST_FAILED;
        }
    }
    
    _test_count++;
    _test_passed++;
    return TEST_PASSED;
}

/* Test with random-ish patterns using bit manipulation */
static int test_trunc_random_patterns(void)
{
    /* Generate test values using interesting bit patterns */
    for (uint64_t i = 0; i < 1000; i++) {
        /* Create various patterns */
        union {
            double d;
            uint64_t bits;
        } u;
        
        /* Generate a valid double (avoid NaN/Inf for this test) */
        u.bits = (i * 0x123456789ABCDEFULL) & 0x7FEFFFFFFFFFFFFFULL;
        if ((u.bits & 0x7FF0000000000000ULL) == 0x7FF0000000000000ULL) {
            continue;  /* Skip NaN/Inf */
        }
        
        double input = u.d;
        double expected = trunc(input);
        double actual = waffle_trunc(input);
        
        if (expected != actual) {
            printf("  [FAIL] Pattern test: waffle_trunc(%g) = %g, expected %g\n", 
                   input, actual, expected);
            _test_count++;
            _test_failed++;
            return TEST_FAILED;
        }
        
        /* Also test negative */
        input = -u.d;
        expected = trunc(input);
        actual = waffle_trunc(input);
        
        if (expected != actual) {
            printf("  [FAIL] Pattern test: waffle_trunc(%g) = %g, expected %g\n", 
                   input, actual, expected);
            _test_count++;
            _test_failed++;
            return TEST_FAILED;
        }
    }
    
    _test_count++;
    _test_passed++;
    return TEST_PASSED;
}

void run_trunc_tests(void)
{
    printf("--- Testing waffle_truncf() ---\n");
    RUN_TEST(test_truncf_positive);
    RUN_TEST(test_truncf_negative);
    RUN_TEST(test_truncf_zero);
    RUN_TEST(test_truncf_fractional_less_than_one);
    RUN_TEST(test_truncf_large_values);
    RUN_TEST(test_truncf_special_values);

    printf("\n--- Testing waffle_trunc() ---\n");
    RUN_TEST(test_trunc_positive);
    RUN_TEST(test_trunc_negative);
    RUN_TEST(test_trunc_zero);
    RUN_TEST(test_trunc_fractional_less_than_one);
    RUN_TEST(test_trunc_large_values);
    RUN_TEST(test_trunc_special_values);

    printf("\n--- Testing waffle_truncl() ---\n");
    RUN_TEST(test_truncl_positive);
    RUN_TEST(test_truncl_negative);
    RUN_TEST(test_truncl_zero);
    RUN_TEST(test_truncl_fractional_less_than_one);
    RUN_TEST(test_truncl_special_values);

    printf("\n--- Comparison tests against libc ---\n");
    RUN_TEST(test_truncf_vs_libc);
    RUN_TEST(test_trunc_vs_libc);
    RUN_TEST(test_truncl_vs_libc);
    RUN_TEST(test_trunc_random_patterns);
}
