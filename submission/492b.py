n, l = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

left = 1
right = 2 * l

ans = -1

while left <= right:
    twoR = (left + right + 1) // 2
    d = twoR / 2

    flag = True
    if a[0] - d > 0:
        flag = False
    else:
        tmp = a[0] + d
        for i in range(1, n):
            if a[i] - d - tmp > 0:
                flag = False
                break
            tmp = a[i] + d
        if tmp < l:
            flag = False
    
    if flag:
        ans = d
        right = twoR - 1
    else:
        left = twoR + 1

print(ans)