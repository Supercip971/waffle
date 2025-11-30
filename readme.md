# Waffle 

Waffle is a lightweight C library for mathematical operations and data structures, designed for high performance and ease of use in scientific computing and graphics applications.

It is initially made for WingOS but can be ported to any OS.


It is not intended for perfect accuracy in mathematical computations, but rather for speed and efficiency in scenarios where approximate results are acceptable.

Note that each function comes with a markdown file explaining the approximation methods used and their potential limitations.

Also note that Waffle uses custom implementations for many standard functions to optimize performance, which may lead to differences in results compared to standard library functions. But Waffle will always follow the C standard. As an example: 

```c
> libc_fmodf(5.0f, 0.1f) => 0.1f // (due to precision issues in libc) 
> waffle_fmodf(5.0f, 0.1f) => 0.0f // (mathematically correct)
```

