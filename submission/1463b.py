for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))

    for i in range(n):
        j = 0
        while not (1 << j) > a[i] / 2: j += 1
        print((1 << j), end=' ')
    print()