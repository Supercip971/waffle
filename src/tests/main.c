#include "test_framework.h"

/* External test suite functions */
extern void run_abs_tests(void);
extern void run_trunc_tests(void);
extern void run_fmod_tests(void);



int _test_count = 0;
int _test_passed = 0;
int _test_failed = 0;
int main(void)
{
    printf("========================================\n");
    printf("Waffle Math Library - Unit Tests\n");
    printf("========================================\n\n");

    printf("=== ABS FUNCTIONS ===\n\n");
    run_abs_tests();

    printf("\n\n=== TRUNC FUNCTIONS ===\n\n");
    run_trunc_tests();

    printf("\n\n=== FMOD FUNCTIONS ===\n\n");
    run_fmod_tests();

    TEST_SUMMARY();
    
    return TEST_EXIT_CODE();
}
