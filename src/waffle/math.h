#pragma once 

#include <float.h>




union mfloat_bits {
    float f;
    struct __attribute__((__packed__)) {
        unsigned int mantissa : 23;
        unsigned int exponent : 8;
        unsigned int sign : 1;
    } parts;
};

union mdouble_bits {
    double d;
    struct __attribute__((__packed__)) {
        unsigned long long mantissa : 52;
        unsigned long long exponent : 11;
        unsigned long long sign : 1;
    } parts;
};

union mlong_double_bits {
    long double ld;
    struct __attribute__((__packed__)) {
        unsigned long long mantissa : 64;
        unsigned int exponent : 15;
        unsigned int sign : 1;
    } parts;
};

#ifndef INFINITY 
#  define INFINITY (__builtin_inff())
#endif 

#ifndef NAN
#  define NAN (__builtin_nanf(""))
#endif 

/* Core waffle functions (always available with waffle_ prefix) */
int waffle_abs(int x);
long waffle_labs(long j);
long long waffle_llabs(long long x);

double waffle_fabs(double x);
float waffle_fabsf(float x);
long double waffle_fabsl(long double x);

/* 
 * Define WAFFLE_NO_PREFIX to disable standard name aliases.
 * This is useful when you want to avoid conflicts with system math library.
 */
#ifndef WAFFLE_NO_PREFIX
#  define abs    waffle_abs
#  define labs   waffle_labs
#  define llabs  waffle_llabs
#  define fabs   waffle_fabs
#  define fabsf  waffle_fabsf
#  define fabsl  waffle_fabsl
#endif
