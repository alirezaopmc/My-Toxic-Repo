s = input()

if len(s) & 1:
    exit(print("No"))

st = []
for i in range(len(s)):
    if len(st) == 0:
        st.append(s[i])
    elif st[-1] == s[i]:
        st.pop()
    else:
        st.append(s[i])

print("No" if len(st) else "Yes")