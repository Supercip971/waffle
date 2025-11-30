#pragma once 

#include <float.h>


#ifndef W_NO_UNLIKELY
#define w_likely(x)       __builtin_expect(!!(x), 1)
#define w_unlikely(x)     __builtin_expect(!!(x), 0)
#else 
#define w_likely(x)       (x)
#define w_unlikely(x)     (x)
#endif

#define FLOAT_MANTISSA_BITS 23
#define DOUBLE_MANTISSA_BITS 52
#define LONG_DOUBLE_MANTISSA_BITS 64

#define FLOAT_MANTISSA_ABS_BASE 127
#define DOUBLE_MANTISSA_ABS_BASE 1023
#define LONG_DOUBLE_MANTISSA_ABS_BASE 16383

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
        unsigned int exponent : 11;
        unsigned int sign : 1;
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



// --- ABS ---- 
int waffle_abs(int x);
long waffle_labs(long j);
long long waffle_llabs(long long x);

double waffle_fabs(double x);
float waffle_fabsf(float x);
long double waffle_fabsl(long double x);


// ---- trunc ----

float waffle_truncf(float x);
double waffle_trunc(double x);
long double waffle_truncl(long double x);

// ---- fmod ----

float waffle_fmodf(float x, float y);
double waffle_fmod(double x, double y);
long double waffle_fmodl(long double x, long double y);


/* 
 * Define NO_WAFFLE_PREFIX to disable standard name aliases.
 * This is useful when you want to avoid conflicts with system math library.
 */
#ifdef NO_WAFFLE_PREFIX
#  define abs    waffle_abs
#  define labs   waffle_labs
#  define llabs  waffle_llabs
#  define fabs   waffle_fabs
#  define fabsf  waffle_fabsf
#  define fabsl  waffle_fabsl

#  define fmodf  waffle_fmodf
#  define fmod   waffle_fmod
#  define fmodl  waffle_fmodl

#define truncf waffle_truncf
#define trunc  waffle_trunc
#define truncl waffle_truncl
#endif
