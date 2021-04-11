"""

a.
T(c^k) = a T(c^k-1) + g(c^k)
    = a ( a T(c^k-2) + g(c^k-1)) + g(c^k)
    = ...
    = a^k T(1) + Sum_{i=1}^k [ a^k-i g(c^i)]

    it's equal to the equation in problem if let d = T(1)


b.
T(n) = c n^log a


"""