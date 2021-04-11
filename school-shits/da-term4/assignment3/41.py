"""

a.
f(n) = n/2 + f(n/2)
f(2) = 1

b.
f(64) = 32 + 16 + 8 + 4 + 2 + 1 = 63

c.
induction of n
suppose f(n) = n - 1
base is ok f(2) = n - 1 = 1

prove f(2n) = 2n - 1
we have f(2n) = n + f(n)
from induction hypothesis we have f(n) = n - 1
so f(2n) = n + n - 1 = 2n - 1

"""