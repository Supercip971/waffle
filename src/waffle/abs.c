#include "math.h"
int waffle_abs(int x)
{

    return (x < 0) ? -x : x;
}

long waffle_labs(long j)
{
    return (j < 0) ? -j : j;
}

long long waffle_llabs(long long x)
{
    return (x < 0) ? -x : x;
}

double waffle_fabs(double x)
{
    union mdouble_bits db;
    db.d = x;
    db.parts.sign = 0;
    return db.d;
}

float waffle_fabsf(float x)
{
    union mfloat_bits fb;
    fb.f = x;
    fb.parts.sign = 0;
    return fb.f;
}

long double waffle_fabsl(long double x)
{
    union mlong_double_bits ldb;
    ldb.ld = x;
    ldb.parts.sign = 0;
    return ldb.ld;
}


