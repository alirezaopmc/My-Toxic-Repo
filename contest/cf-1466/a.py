for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    x = {}
    cnt = 0
    for i in range(n-1):
        for j in range(i, n):
            y = abs(a[i] - a[j])
            if y == 0:
                continue
            if y not in x:
                x[y] = 1
                cnt += 1
    # print(x)
    print(cnt)