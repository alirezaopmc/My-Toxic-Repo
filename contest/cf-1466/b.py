for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort
    x = {}
    cnt = 0
    for i in range(n):
        if a[i] not in x:
            x[a[i]] = 1
            cnt += 1
        else:
            x[a[i]] += 1
    
    for i in range(n-1, -1, -1):
        if a[i]+1 not in x:
            x[a[i]] -= 1
            x[a[i]+1] = 1
            if x[a[i]] == 0:
                del x[a[i]]
            else:
                cnt += 1
    # print(x)
    print(cnt)