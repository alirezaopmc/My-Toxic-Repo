for _ in range(int(input())):
    a, b = map(int, input().split())
    x = a & b
    print((a ^ x) + (b ^ x))