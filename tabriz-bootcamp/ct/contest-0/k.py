s = input()
a = []
n = len(s)

for i in range(n):
    if len(a) != 0 and ((s[a[-1]] == '(' and s[i] == ')') or (s[a[-1]] == '[' and s[i] == ']')):
        a.pop()
    else:
        a.append(i)

a.append(n)

if len(a) == 1:
    print(s.count('['))
    print(s)
else:
    st, en = -1, a[0]
    c = s[st+1:en].count('[')
    for i in range(len(a)-1):
        if s[a[i]+1:a[i+1]].count('[') > c:
            st = a[i]
            en = a[i+1]
            c = s[st+1:en].count('[')
    
    print(c)
    print(s[st+1:en])