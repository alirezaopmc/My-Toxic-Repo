/*
Determine the time complexity of Algorithm 1.6 (nth Fibonacci Term,
Recursive) in terms of its input size.
*/

/*
f(n) = f(n-1) + f(n-2)
T(n) = T(n-1) + T(n-2) + c

T(n-1) > T(n-2)
    => T(n) >= 2T(n-2) + c
    => T(n) >= (2^(n/2) - 1) * c
    &
    => T(n) <= 2T(n-1) + c
    => T(n) <= (2^n-1) * c
*/