def low(k):
    return k * (k+1) // 2

def high(n, k):
    return (n + n - k + 1) * k // 2

for _ in range(int(input())):
    n, l, r, s = map(int, input().split())
    k = r - l + 1
    perm = [-1] * k
    ind = 0

    mp = {}


    for i in range(n):
        mp[i+1] = True

    if low(k) <= s <= high(n, k):
        i = n
        while i > 0:
            t = s - i

            if low(k-1) <= t <= high(i-1, k-1):
                s -= i
                k -= 1
                perm[ind] = i
                mp[i] = False
                ind += 1
            i -= 1

        i = 1
        cnt = 0
        k = r - l + 1
        while i <= n:
            # print('i=', i)
            if cnt + 1 == l:
                # print('perm case')
                for j in perm:
                    print(j, end=' ')
                cnt += k
                continue
            elif mp[i]:
                # print('true case')
                print(i, end=' ')
                i += 1
                cnt += 1
            else:
                # print('false case')
                i += 1
        print()

    else:
        print(-1)
    