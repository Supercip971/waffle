#include "waffle/math.h"
float waffle_fmodf(float x, float y)
{
    union mfloat_bits fb ;
    fb.f = x;
    union mfloat_bits fy ;
    fy.f = y;
    return fb.f;
}
double waffle_fmod(double x, double y);
long double waffle_fmodl(long double x, long double y);

