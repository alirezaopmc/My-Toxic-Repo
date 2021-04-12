n, x, y = map(int, input().split())
a = sorted(list(map(int, input().split())))
s = 100 * (n-1) - sum(a[1:])
m = a[0]

need = (s + y - 1) // y

if need * x <= m:
    print('YES')
else:
    print('NO')
