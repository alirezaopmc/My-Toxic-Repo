n = int(input())

a = [-1] * n

for i in range(n):
    x, y = list(map(int, input().split()))
    a[i] = (y, x)

a.sort()

cur = 0
cnt = 0
i = 0
while i < n:
    if cur < a[i][1]:
        cnt += a[i][1] - cur
        cur = a[i][1]
    cur -= a[i][0]
    i += 1
print(cnt)