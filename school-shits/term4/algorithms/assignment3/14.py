def solve_recursion(n, a, b, f, init):
    if n == 0:
        return 0
    if n == 1:
        return init
    
    return a * solve_recursion(n // b, a, b, f, init) + f(n)

f = lambda n: 10 * n
print(solve_recursion(625, 7, 5, f, 1))

# 46801