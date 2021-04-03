/*
Show the correctness of the following statements.
(a) lg n = O(n)
(b) n = O(n lg n)
(c) n lg n = O(n^2)
(d) 2^n = Omega(5^ln n)
(e) lg^3 n = o(n^0.5)


(a) lg n <= n
(b) n <= n lg n
(c) lg n <= n => n lg n <= n^2
(d) 5 < 8 = 2 ^ 3 => 5^ln n < 2^(3ln n)
    => n >= 3ln n => 2^n = Omega(5^ln n)
(e) ?
*/