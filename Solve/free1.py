import sys
import math
 
# Constants
mod = 998244353
 
# Functions Settings
dynamic_factorial = False
 
# Pre-defined function

# Begin
 
# Testcase handler
def main(test_case = False):
    n = int(input()) if test_case else 1
    for _ in range(n):
        test()
        print()
 
# Binary method of power
def fast_pow(a:int, b:int):
    res = 1
    while b > 0:
        if b & 1:
            res *= a
        a *= a
        b >>= 1
    return res
 
# Combination of 2
def c2(n):
    return n * (n-1) // 2
 
# Get the list form of input
def get():
    return list(map(int, input().split()))
 
# Number of 1s in binary form
def bits(n: int):
    return list(bin(n)).count('1')
 
# For interactive problems
def flush():
    sys.stdout.flush()
 
# Print array and split it with space
def parr(arr):
    print(*arr, sep=' ')
 
# GCD (int a, int b)
# Return: value of GCD(a, b)
def gcd(a, b):
    while b:
        if b % a == 0:
            break
        tmp = a
        a = b % a
        b = tmp
    return a
 
# Extended GCD (int a, int b)
# Return: array of [GCD(a, b), [x0, y0]]
# Where a * x0 + b * y0 = 1
# If GCD(a, b) != 1 then return False
def ext_gcd(a: int, b: int):
    if (b == 0):
        return [a, [1, 0]]
 
    res = ext_gcd(b, a % b)
    g = res[0]
    if g != 1:
        return False
    x1 = res[1][0]
    y1 = res[1][1]
    x = y1
    y = x1 - y1 * (a // b)
 
    return [g, [x, y]]
 
# Get all different values of array a with their count
def get_set(a):
    res = {}
    for x in a:
        if x in res:
            res[x] += 1
        else:
            res[x] = 1
    return res
 
# Factorial
fact = {0: 1}
def factorial(n):
    if dynamic_factorial:
        if n not in fact:
            fact[n] = factorial(n-1) * n
        return fact[n]
    else:
        res = 1
        while n > 0:
            res = (res * n) % mod
            n -= 1
        return res
 
# Sum of array
def sum_of(a):
    res = 0
    for x in a:
        res = (res + x) % mod
    return res
 
# Prod of array
def prod_of(a):
    res = 1
    for x in a:
        res = (res * x) % mod
    return res
 
# Number of different elements
def different_elements(arr):
    ans = 0
    n = len(arr)
    i = 0
    while i < n:
        ans += 1
        while i < n-1 and arr[i] == arr[i+1]:
            i += 1
        i += 1
    return ans
# End
 
def test():
    n, m = get()
    a = get()
    p = [(-1, -1)] * 100

    b = sorted(a)
    i = 0
    l = 0
    while i < n:
        l = i
        while i < n-1 and b[i] == b[i+1]: i += 1
        p[b[i]-1] = (i-l+1, b[i])
        i += 1
    
    p.sort()
    i = 99
    while i > 0 and p[i-1][0] != -1: i -= 1
    p = p[i:]
    mostCnt = p[-1][0]
    mostNum = p[-1][1]
        
main(test_case = True)