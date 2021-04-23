/*
Justify the correctness of the following
statements assuming that f(n) and g(n)
are asymptotically positive functions.

(a) f(n) + g(n) = O(max(f(n), g(n)))
(b) f^2(n) = Omega(f(n))
(c) f(n) + o(f(n)) = Theta(f(n)), where
    means any function g(n) = o(f(n))

(a) f(n) + g(n
    = min(f(n), g(n)) + max(f(n), g(n)))
    <= 2 * max(f(n), g(n))
    <=> min(f(n), g(n)) <= max(f(n), g(n))

(b) f(n) > 1 (positive)
    f^2(n) > f(n) <=> f(n) > 1

(c) ?
*/