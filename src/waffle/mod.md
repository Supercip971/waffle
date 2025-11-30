# mod

Let be: 


$$
\begin{align*}
x & = \text{dividend} \\
y & = \text{divisor} \\
q & = \text{quotient} = \text{trunc}(x / y) \\
r & = \text{remainder} = x - q \cdot y
\end{align*}
$$

Note that trunc is the function that truncates towards zero.
Meaning that: 

$$
\text{trunc}(z) = 
\begin{cases}
\lfloor z \rfloor & \text{if } z \geq 0 \\
\lceil z \rceil & \text{if } z < 0
\end{cases}
$$

And: 

$$
\begin{align*}
m_x & = \text{mantissa of } x \\
e_x & = \text{exponent of } x \\
sign_x & = \text{sign bit of } x \\
m_y & = \text{mantissa of } y \\
e_y & = \text{exponent of } y \\
sign_y & = \text{sign bit of } y \\
\end{align*}
$$

$$
\begin{align*}
x &= (-1)^{sign_x} \cdot m_x \cdot 2^{e_x} \\
y &= (-1)^{sign_y} \cdot m_y \cdot 2^{e_y} \\
\end{align*}
$$

Thus:

$$
\begin{align*}
q &= \text{trunc}\left( \frac{(-1)^{sign_x} \cdot m_x \cdot 2^{e_x}}{(-1)^{sign_y} \cdot m_y \cdot 2^{e_y}} \right) \\
  &= \text{trunc}\left( (-1)^{sign_x - sign_y} \cdot \frac{m_x}{m_y} \cdot 2^{e_x - e_y} \right) \\
\end{align*}
$$
Finally, the remainder can be computed as:

$$
r = x - q \cdot y
$$

$$
\begin{align*}
r &= (-1)^{sign_x} \cdot m_x \cdot 2^{e_x} - \text{trunc}\left( (-1)^{sign_x - sign_y} \cdot \frac{m_x}{m_y} \cdot 2^{e_x - e_y} \right) \cdot (-1)^{sign_y} \cdot m_y \cdot 2^{e_y} \\
\end{align*}
$$

