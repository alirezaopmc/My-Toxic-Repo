"""

T(n) = 3T(n/3) + n-1
T(1) = 0


n=3^k
T(3^k) = 3T(3^k-1) + 3^k - 1

log1 = 0 < n-1

so

T(n) = nlogn - (n-1)

"""