#include "waffle/math.h"
#include <stdio.h>
float waffle_fmodf(float x, float y)
{
    union mfloat_bits fb_x, fb_y;
    fb_x.f = x;
    fb_y.f = y;

    // printf("Debug: abs_x=%f, abs_y=%f, q=%f\n", x, y, x/y); // Debug line
    // Handle special cases
    if (fb_y.parts.exponent == 0xFF && fb_y.parts.mantissa != 0)
    {
        return NAN; // y is NaN
    }
    if (fb_x.parts.exponent == 0xFF && fb_x.parts.mantissa != 0)
    {
        return NAN; // x is NaN
    }
    // x is inf -> return NaN
    if (fb_x.parts.exponent == 0xFF && fb_x.parts.mantissa == 0)
    {
        return NAN;
    }

    // y is zero -> return NaN
    if (y == 0.0f)
    {
        return NAN;
    }

    // y is inf -> return x (when x is finite)
    if (fb_y.parts.exponent == 0xFF && fb_y.parts.mantissa == 0)
    {
        return x;
    }

    float abs_x = waffle_fabsf(x);
    float abs_y = waffle_fabsf(y);

    float q = waffle_truncf(abs_x / abs_y); // = 2

    float r = abs_x - q * abs_y; // 5 - 2 * 2 = 1
    union mfloat_bits result;
    result.f = r;
    result.parts.sign = fb_x.parts.sign;

    return result.f;
}
double waffle_fmod(double x, double y)
{
    union mdouble_bits fb_x, fb_y;
    fb_x.d = x;
    fb_y.d = y;

    // Handle special cases
    if (fb_y.parts.exponent == 0x7FF && fb_y.parts.mantissa != 0)
    {
        return NAN; // y is NaN
    }
    if (fb_x.parts.exponent == 0x7FF && fb_x.parts.mantissa != 0)
    {
        return NAN; // x is NaN
    }
    // x is inf -> return NaN
    if (fb_x.parts.exponent == 0x7FF && fb_x.parts.mantissa == 0)
    {
        return NAN;
    }

    // y is zero -> return NaN
    if (y == 0.0)
    {
        return NAN;
    }

    // y is inf -> return x (when x is finite)
    if (fb_y.parts.exponent == 0x7FF && fb_y.parts.mantissa == 0)
    {
        return x;
    }

    double abs_x = waffle_fabs(x);
    double abs_y = waffle_fabs(y);

    double q = waffle_trunc(abs_x / abs_y); // = 2

    double r = abs_x - q * abs_y; // 5 - 2 * 2 = 1
    union mdouble_bits result;
    result.d = r;
    result.parts.sign = fb_x.parts.sign;

    return result.d;
}
long double waffle_fmodl(long double x, long double y)
{
    union mlong_double_bits fb_x, fb_y;
    fb_x.ld = x;
    fb_y.ld = y;

    // Handle special cases
    if (fb_y.parts.exponent == 0x7FFF && fb_y.parts.mantissa != 0)
    {
        return NAN; // y is NaN
    }
    if (fb_x.parts.exponent == 0x7FFF && fb_x.parts.mantissa != 0)
    {
        return NAN; // x is NaN
    }
    // x is inf -> return NaN
    if (fb_x.parts.exponent == 0x7FFF && fb_x.parts.mantissa == 0)
    {
        return NAN;
    }

    // y is zero -> return NaN
    if (y == 0.0L)
    {
        return NAN;
    }

    // y is inf -> return x (when x is finite)
    if (fb_y.parts.exponent == 0x7FFF && fb_y.parts.mantissa == 0)
    {
        return x;
    }

    long double abs_x = waffle_fabsl(x);
    long double abs_y = waffle_fabsl(y);

    long double q = waffle_truncl(abs_x / abs_y); // = 2

    long double r = abs_x - q * abs_y; // 5 - 2 * 2 = 1
    union mlong_double_bits result;
    result.ld = r;
    result.parts.sign = fb_x.parts.sign;

    return result.ld;
}
