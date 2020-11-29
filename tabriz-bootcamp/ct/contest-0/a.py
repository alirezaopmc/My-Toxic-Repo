def get():
    return list(map(int, input().split()))

n = get()[0]
a = get()

l = [-1] * n
r = [n] * n

st = []
for i in range(n):
    while len(st) and a[st[-1]] >= a[i]:
        st.pop()
    
    if len(st):
        l[i] = st[-1]
    
    st.append(i)

st = []
for i in range(n-1, -1, -1):
    while len(st) and a[st[-1]] >= a[i]:
        st.pop()
    
    if len(st):
        r[i] = st[-1]
    
    st.append(i)

ans = [-1] * n
for i in range(n):
    ans[r[i] - l[i] - 2] = max(ans[r[i] - l[i] - 2], a[i])

ans[n-1] = min(a)

for i in range(1,n):
    ans[n-i-1] = max(ans[n-i], ans[n-i-1])

print(*ans)