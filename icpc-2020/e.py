n, k = map(int, input().split())
s = input()
t = reversed(s)
s = list(s)
t = list(t)

cnt = 0
if k == 2:
    i = 1
    while i < n:
        if s[i] == s[i-1]:
            s[i] = chr(ord('A') + ord('B') - ord(s[i]))
            cnt += 1
        i += 1
    cnt2 = 0
    j = 1
    while j < n:
        if t[j] == t[j-1]:
            t[j] = chr(ord('A') + ord('B') - ord(t[j]))
            cnt2 += 1
        j += 1
    print(min(cnt, cnt2))
else:
    i = 1
    while i < n:
        if s[i] == s[i-1]:
            cnt += 1
            i += 1
        i += 1
    j = 1
    while j < n:
        if t[i] == t[i-1]:
            cnt += 1
            j += 1
        j += 1
    print(cnt)