# Trunc 


- Trunc: implemented
- Accuracy: exact 

Let be: 

$$
\text{trunc}(z) = 
\begin{cases}
\lfloor z \rfloor & \text{if } z \geq 0 \\
\lceil z \rceil & \text{if } z < 0
\end{cases}
$$

With: 

$$
\begin{align*}
m & = \text{mantissa of } z \\
e & = \text{exponent of } z \\
sign & = \text{sign bit of } z \\
\end{align*}
$$

## Remove the sign: 

$$
\begin{align*}
\text{trunc}(sign * m * 2^e) &= sign * \text{trunc}(m * 2^e) \\
&= sign * \left\lfloor m * 2^e \right\rfloor \quad \text{if } sign \geq 0 \\
&= sign * \left\lceil m * 2^e \right\rceil \quad \text{if } sign < 0 \\
\end{align*}
$$

We know that ceil can be obtained with: 

$$


$$

Let: 
$$
\delta = m * 2^e
$$

We know that $m$ is: 

$$
m = 1 + \sum_{i=1}^{p} b_i * 2^{-i}
$$

Thus: 

$$
\begin{align*}
\delta &= 2^e * (1+\sum_{i=1}^{p} b_i * 2^{- i})\\
&= 2^e + \sum_{i=1}^{p} b_i * 2^{e - i} \\
\end{align*}
$$


In the end, we want to set $b_i$ to zero for all $i$ where $e - i < 0$.
(Thus zeroing all bits where $i > e$).

Thus, we can define a mask:
$$
\text{mask} =
\begin{cases}
1 & \text{if } i \leq e \\
0 & \text{if } i > e \\
\end{cases}
$$
And then apply it to the mantissa bits.


## Accuracy

Trunc function only works with bit fields to correctly handle precision and avoid rounding issues.


And thus the precision is only limited by the number of bits in the mantissa. 