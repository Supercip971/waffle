#pragma once

#include <stdio.h>
#include <string.h>

/* Simple unit test framework for waffle */

#define TEST_PASSED 0
#define TEST_FAILED 1

extern  int _test_count;
extern  int _test_passed;
extern  int _test_failed;

#define TEST_ASSERT(condition, message)                                       \
    do {                                                                      \
        _test_count++;                                                        \
        if (!(condition)) {                                                   \
            printf("  [FAIL] %s:%d: %s\n", __FILE__, __LINE__, message);      \
            _test_failed++;                                                   \
            return TEST_FAILED;                                               \
        } else {                                                              \
            _test_passed++;                                                   \
        }                                                                     \
    } while (0)

#define TEST_ASSERT_EQ(expected, actual, message)                             \
    do {                                                                      \
        _test_count++;                                                        \
        if ((expected) != (actual)) {                                         \
            printf("  [FAIL] %s:%d: %s (expected %lld, got %lld)\n",          \
                   __FILE__, __LINE__, message,                               \
                   (long long)(expected), (long long)(actual));               \
            _test_failed++;                                                   \
            return TEST_FAILED;                                               \
        } else {                                                              \
            _test_passed++;                                                   \
        }                                                                     \
    } while (0)

#define TEST_ASSERT_FLOAT_EQ(expected, actual, epsilon, message)              \
    do {                                                                      \
        _test_count++;                                                        \
        long double _diff = (expected) - (actual);                                 \
        if (_diff < 0) _diff = -_diff;                                        \
        if (_diff > (epsilon)) {                                              \
            printf("  [FAIL] %s:%d: %s (expected %f, got %f)\n",              \
                   __FILE__, __LINE__, message,                               \
                   (double)(expected), (double)(actual));                     \
            _test_failed++;                                                   \
            return TEST_FAILED;                                               \
        } else {                                                              \
            _test_passed++;                                                   \
        }                                                                     \
    } while (0)

#define RUN_TEST(test_func)                                                   \
    do {                                                                      \
        printf("Running %s...\n", #test_func);                                \
        int _result = test_func();                                            \
        if (_result == TEST_PASSED) {                                         \
            printf("  [PASS] %s\n", #test_func);                              \
        }                                                                     \
    } while (0)

#define TEST_SUMMARY()                                                        \
    do {                                                                      \
        printf("\n========================================\n");               \
        printf("Test Summary: %d/%d passed\n", _test_passed, _test_count);    \
        if (_test_failed > 0) {                                               \
            printf("FAILED: %d tests failed\n", _test_failed);                \
        } else {                                                              \
            printf("SUCCESS: All tests passed!\n");                           \
        }                                                                     \
        printf("========================================\n");                 \
    } while (0)

#define TEST_EXIT_CODE() (_test_failed > 0 ? 1 : 0)
