#include "waffle/math.h"

float waffle_truncf(float x)
{
    union mfloat_bits fb;
    fb.f = x;

    // If exponent is all 1s or all 0s, return x (NaN or Inf or zero)
    if  (w_unlikely(fb.parts.exponent == 0xFF || fb.parts.exponent == 0)) {
        return x;
    }

    int exponent = (unsigned int)fb.parts.exponent - FLOAT_MANTISSA_ABS_BASE; // Unbias exponent

    if (exponent < 0) {
        // Absolute value less than 1.0
        fb.parts.mantissa = 0;
        fb.parts.exponent = 0;
    } else if (exponent < FLOAT_MANTISSA_BITS) {
        // Clears every fractional bit
        unsigned int mask = (1U << (FLOAT_MANTISSA_BITS - exponent)) - 1;
        fb.parts.mantissa &= ~mask;

    }
    // If exponent >= 23, number is already an integer

    return fb.f;
}

double waffle_trunc(double x)
{
    union mdouble_bits db;
    db.d = x;

    // If exponent is all 1s or all 0s, return x (NaN or Inf or zero)
    if (w_unlikely(db.parts.exponent == 0x7FF || db.parts.exponent == 0)) {
        return x;
    }

    long exponent = (unsigned long long)db.parts.exponent - DOUBLE_MANTISSA_ABS_BASE; // Unbias exponent

    if (exponent < 0) {
        // Absolute value less than 1.0
        db.parts.mantissa = 0;
        db.parts.exponent = 0;
    } else if (exponent < DOUBLE_MANTISSA_BITS) {
        // Clear fractional bits
        unsigned long long mask = (1ULL << (DOUBLE_MANTISSA_BITS - exponent)) - 1ULL;
        db.parts.mantissa &= ~mask;
    }
    // If exponent >= 52, number is already an integer

    return db.d;
}

long double waffle_truncl(long double x)
{
    union mlong_double_bits ldb;
    ldb.ld = x;

    // If exponent is all 1s or all 0s, return x (NaN or Inf or zero)
    if (w_unlikely(ldb.parts.exponent == 0x7FFF || ldb.parts.exponent == 0)) {
        return x;
    }

    long exponent = (long)ldb.parts.exponent - LONG_DOUBLE_MANTISSA_ABS_BASE; // Unbias exponent

    if (exponent < 0) {
        // Absolute value less than 1.0
        ldb.parts.mantissa = 0;
        ldb.parts.exponent = 0;
    } else if (exponent < LONG_DOUBLE_MANTISSA_BITS - 1) {
        // Clear fractional bits
        // Note: x86 long double has 64-bit mantissa with explicit integer bit,
        // so we have 63 fractional bits (bit 63 is the integer bit)
        unsigned long long mask = ~((1ULL << (LONG_DOUBLE_MANTISSA_BITS - 1 - exponent)) - 1ULL);
        ldb.parts.mantissa &= mask;
    }
    // If exponent >= 63, number is already an integer

    return ldb.ld;
}