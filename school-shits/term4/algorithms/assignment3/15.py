"""

a.
T(n) = 5T(n/3) + g(n)
T(1) = 1 (or 0)

b.
???

c.
1484 (T(1) = 1)
1359 (T(1) = 0)

d.
T(n) = 5T(n/3)
    => T(n) = c 5^log(n)

"""

def solve_recursion(n, a, b, f, init):
    if n == 0:
        return 0
    if n == 1:
        return init
    
    return a * solve_recursion(n // b, a, b, f, init) + f(n)

f = lambda n: n ** 2
print(solve_recursion(27, 5, 3, f, 0))

# 1484 (init = 1)
# 1359 (init = 0)