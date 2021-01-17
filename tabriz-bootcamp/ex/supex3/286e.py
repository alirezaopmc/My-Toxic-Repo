n = int(input())
s = [-1] * n
j = 0

for i in range(n):
    l, p = map(int, input().split())
    s[i] = (l, p)
    if p == 100:
        s[i], s[j] = s[j], s[i]
        j += 1

s[j:].sort(key=lambda sng: sng[0] * sng[1] / (100 - sng[1]))

print(s)

