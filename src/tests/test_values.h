#pragma once

#include <stdint.h>

/*
 * Common test values for waffle math library tests.
 * These arrays can be reused across different test files.
 */

static const float TEST_FLOAT_VALUES[] = {
    /* Zero values */
    0.0f, -0.0f,
    
    /* Small fractions (less than 1) */
    0.1f, -0.1f, 0.5f, -0.5f, 0.9f, -0.9f, 0.99999f, -0.99999f,
    0.0001f, -0.0001f, 0.00001f, -0.00001f,
    
    /* Values around 1 */
    1.0f, -1.0f, 1.1f, -1.1f, 1.5f, -1.5f, 1.9f, -1.9f, 1.99999f, -1.99999f,
    
    /* Small integers with fractions */
    2.3f, -2.3f, 3.7f, -3.7f, 5.5f, -5.5f, 7.9f, -7.9f, 10.1f, -10.1f,
    
    /* Larger values */
    100.001f, -100.001f, 100.999f, -100.999f,
    1000.5f, -1000.5f, 9999.9f, -9999.9f,
    12345.6789f, -12345.6789f,
    
    /* Powers of 2 */
    2.0f, 4.0f, 8.0f, 16.0f, 32.0f, 64.0f, 128.0f, 256.0f, 512.0f, 1024.0f,
    -2.0f, -4.0f, -8.0f, -16.0f, -32.0f, -64.0f, -128.0f, -256.0f, -512.0f, -1024.0f,
    
    /* Powers of 2 with fractions */
    2.5f, 4.25f, 8.125f, 16.0625f, 32.03125f,
    -2.5f, -4.25f, -8.125f, -16.0625f, -32.03125f,
    
    /* Large values */
    1e6f, -1e6f, 1e7f, -1e7f, 1e10f, -1e10f,
    
    /* Edge cases near max float */
    1e30f, -1e30f, 1e38f, -1e38f,
    
    /* Mathematical constants */
    3.14159265f, -3.14159265f,   /* Pi */
    2.71828182f, -2.71828182f,   /* e */
    1.41421356f, -1.41421356f,   /* sqrt(2) */
    1.61803398f, -1.61803398f,   /* golden ratio */
};

#define TEST_FLOAT_VALUES_COUNT (sizeof(TEST_FLOAT_VALUES) / sizeof(TEST_FLOAT_VALUES[0]))

/* ============================================================
 * Double test values
 * ============================================================ */

static const double TEST_DOUBLE_VALUES[] = {
    /* Zero values */
    0.0, -0.0,
    
    /* Small fractions (less than 1) */
    0.1, -0.1, 0.5, -0.5, 0.9, -0.9, 0.999999999, -0.999999999,
    0.0001, -0.0001, 0.00000001, -0.00000001,
    
    /* Values around 1 */
    1.0, -1.0, 1.1, -1.1, 1.5, -1.5, 1.9, -1.9, 1.999999999, -1.999999999,
    
    /* Small integers with fractions */
    2.3, -2.3, 3.7, -3.7, 5.5, -5.5, 7.9, -7.9, 10.1, -10.1,
    
    /* Larger values */
    100.001, -100.001, 100.999, -100.999,
    1000.5, -1000.5, 9999.9, -9999.9,
    12345.6789, -12345.6789,
    
    /* Powers of 2 */
    2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0, 256.0, 512.0, 1024.0,
    -2.0, -4.0, -8.0, -16.0, -32.0, -64.0, -128.0, -256.0, -512.0, -1024.0,
    
    /* Powers of 2 with fractions */
    2.5, 4.25, 8.125, 16.0625, 32.03125, 64.015625,
    -2.5, -4.25, -8.125, -16.0625, -32.03125, -64.015625,
    
    /* Large values */
    1e6, -1e6, 1e9, -1e9, 1e12, -1e12, 1e15, -1e15,
    
    /* Edge cases near max double */
    1e100, -1e100, 1e200, -1e200, 1e307, -1e307,
    
    /* Mathematical constants */
    3.14159265358979323846, -3.14159265358979323846,   /* Pi */
    2.71828182845904523536, -2.71828182845904523536,   /* e */
    1.41421356237309504880, -1.41421356237309504880,   /* sqrt(2) */
    1.61803398874989484820, -1.61803398874989484820,   /* golden ratio */
    0.69314718055994530942, -0.69314718055994530942,   /* ln(2) */
    2.30258509299404568402, -2.30258509299404568402,   /* ln(10) */
};

#define TEST_DOUBLE_VALUES_COUNT (sizeof(TEST_DOUBLE_VALUES) / sizeof(TEST_DOUBLE_VALUES[0]))

/* Double values that stress mantissa boundary handling */
static const double TEST_DOUBLE_MANTISSA_EDGE[] = {
    (double)(1LL << 52) + 0.5, (double)(1LL << 52) - 0.5,
    (double)(1LL << 51) + 0.5, (double)(1LL << 51) - 0.5,
    (double)(1LL << 50) + 0.5, (double)(1LL << 50) - 0.5,
    (double)(1LL << 49) + 0.5, (double)(1LL << 49) - 0.5,
    (double)(1LL << 48) + 0.5, (double)(1LL << 48) - 0.5,
    -(double)(1LL << 52) + 0.5, -(double)(1LL << 52) - 0.5,
    -(double)(1LL << 51) + 0.5, -(double)(1LL << 51) - 0.5,
    -(double)(1LL << 50) + 0.5, -(double)(1LL << 50) - 0.5,
};

#define TEST_DOUBLE_MANTISSA_EDGE_COUNT (sizeof(TEST_DOUBLE_MANTISSA_EDGE) / sizeof(TEST_DOUBLE_MANTISSA_EDGE[0]))

/* ============================================================
 * Long double test values
 * ============================================================ */

static const long double TEST_LONG_DOUBLE_VALUES[] = {
    /* Zero values */
    0.0L, -0.0L,
    
    /* Small fractions (less than 1) */
    0.1L, -0.1L, 0.5L, -0.5L, 0.9L, -0.9L, 
    0.999999999999L, -0.999999999999L,
    0.0001L, -0.0001L, 0.00000001L, -0.00000001L,
    
    /* Values around 1 */
    1.0L, -1.0L, 1.1L, -1.1L, 1.5L, -1.5L, 1.9L, -1.9L,
    1.999999999999L, -1.999999999999L,
    
    /* Small integers with fractions */
    2.3L, -2.3L, 3.7L, -3.7L, 5.5L, -5.5L, 7.9L, -7.9L, 10.1L, -10.1L,
    
    /* Larger values */
    100.001L, -100.001L, 100.999L, -100.999L,
    1000.5L, -1000.5L, 9999.9L, -9999.9L,
    12345.6789L, -12345.6789L,
    
    /* Powers of 2 */
    2.0L, 4.0L, 8.0L, 16.0L, 32.0L, 64.0L, 128.0L, 256.0L, 512.0L, 1024.0L,
    -2.0L, -4.0L, -8.0L, -16.0L, -32.0L, -64.0L, -128.0L, -256.0L, -512.0L, -1024.0L,
    
    /* Powers of 2 with fractions */
    2.5L, 4.25L, 8.125L, 16.0625L, 32.03125L, 64.015625L,
    -2.5L, -4.25L, -8.125L, -16.0625L, -32.03125L, -64.015625L,
    
    /* Large values */
    1e6L, -1e6L, 1e9L, -1e9L, 1e12L, -1e12L, 1e15L, -1e15L, 1e18L, -1e18L,
    
    /* Edge cases for long double precision */
    1e100L, -1e100L, 1e1000L, -1e1000L,
    
    /* Mathematical constants with high precision */
    3.14159265358979323846264338327950288L, -3.14159265358979323846264338327950288L,   /* Pi */
    2.71828182845904523536028747135266250L, -2.71828182845904523536028747135266250L,   /* e */
    1.41421356237309504880168872420969808L, -1.41421356237309504880168872420969808L,   /* sqrt(2) */
    1.61803398874989484820458683436563812L, -1.61803398874989484820458683436563812L,   /* golden ratio */
};

#define TEST_LONG_DOUBLE_VALUES_COUNT (sizeof(TEST_LONG_DOUBLE_VALUES) / sizeof(TEST_LONG_DOUBLE_VALUES[0]))

/* Long double values that stress mantissa boundary handling (64-bit mantissa) */
static const long double TEST_LONG_DOUBLE_MANTISSA_EDGE[] = {
    (long double)(1ULL << 62) + 0.5L, (long double)(1ULL << 62) - 0.5L,
    (long double)(1ULL << 61) + 0.5L, (long double)(1ULL << 61) - 0.5L,
    (long double)(1ULL << 60) + 0.5L, (long double)(1ULL << 60) - 0.5L,
    (long double)(1ULL << 59) + 0.5L, (long double)(1ULL << 59) - 0.5L,
    (long double)(1ULL << 58) + 0.5L, (long double)(1ULL << 58) - 0.5L,
    -(long double)(1ULL << 62) + 0.5L, -(long double)(1ULL << 62) - 0.5L,
    -(long double)(1ULL << 61) + 0.5L, -(long double)(1ULL << 61) - 0.5L,
    -(long double)(1ULL << 60) + 0.5L, -(long double)(1ULL << 60) - 0.5L,
};

#define TEST_LONG_DOUBLE_MANTISSA_EDGE_COUNT (sizeof(TEST_LONG_DOUBLE_MANTISSA_EDGE) / sizeof(TEST_LONG_DOUBLE_MANTISSA_EDGE[0]))

/* ============================================================
 * Integer test values (for abs, etc.)
 * ============================================================ */

static const int TEST_INT_VALUES[] = {
    0, 1, -1, 2, -2, 5, -5, 10, -10,
    100, -100, 1000, -1000, 10000, -10000,
    2147483647, -2147483647, -2147483648,  /* INT_MAX, etc */
    0x7FFFFFFF, 0x80000000,
};

#define TEST_INT_VALUES_COUNT (sizeof(TEST_INT_VALUES) / sizeof(TEST_INT_VALUES[0]))

static const long TEST_LONG_VALUES[] = {
    0L, 1L, -1L, 2L, -2L, 5L, -5L, 10L, -10L,
    100L, -100L, 1000L, -1000L, 10000L, -10000L,
    1000000L, -1000000L, 1000000000L, -1000000000L,
};

#define TEST_LONG_VALUES_COUNT (sizeof(TEST_LONG_VALUES) / sizeof(TEST_LONG_VALUES[0]))

static const long long TEST_LLONG_VALUES[] = {
    0LL, 1LL, -1LL, 2LL, -2LL, 5LL, -5LL, 10LL, -10LL,
    100LL, -100LL, 1000LL, -1000LL, 10000LL, -10000LL,
    1000000LL, -1000000LL, 1000000000LL, -1000000000LL,
    1000000000000LL, -1000000000000LL,
    9223372036854775807LL, -9223372036854775807LL,  /* LLONG_MAX */
};

#define TEST_LLONG_VALUES_COUNT (sizeof(TEST_LLONG_VALUES) / sizeof(TEST_LLONG_VALUES[0]))
