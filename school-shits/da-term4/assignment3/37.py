def factorial(n):
    if n == 1:
        return 1
    else:
        return factorial(n-1) * n


"""

T(n) = T(n-1) + 1 => T(n) = n
it's linear, not exponential

"""