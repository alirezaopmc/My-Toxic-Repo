for _ in range(int(input())):
    n = int(input())
    s = input()

    t = 0
    m = 0
    flag = False
    for i in range(n):
        if s[i] == 'T':
            t += 1
        elif s[i] == 'M':
            m += 1
        
        if m > t:
            print('NO')
            flag = True
            break

    if flag: continue
    

    t = 0
    m = 0
    for j in range(n):
        i = n - j - 1
        if s[i] == 'T':
            t += 1
        elif s[i] == 'M':
            m += 1
        
        if m > t:
            print('NO')
            flag = True
            break
    

    if flag: continue

    if t == 2 * m:
        print('YES')
    else:
        print('NO')