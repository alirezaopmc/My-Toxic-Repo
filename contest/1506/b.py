for _ in range(int(input())):
    n, k = map(int, input().split())
    s = input()

    a = [-1] * n
    for i in range(n):
        if s[i] == '.': continue
        for j in range(i+1, i+k+1):
            if j >= n: break
            if s[j] == '*':
                a[i] = j
    # print('debug')

    c = 1
    
    i = 0
    while i < n:
        if s[i] == '*':
            break
        i += 1

    while a[i] != -1:
        c += 1
        i = a[i]
    
    print(c)
    
    # j = n-1
    # while j >= 0:
    #     if s[j] == '*':
    #         break
    #     j -= 1

    # print(i, j)
    
    # if i == j:
    #     print(1)
    # else:

    #     jump = 1

    #     # j+1 or j ?
    #     while i < j+1:
    #         t = -1
    #         # i+1 ? i
    #         _i = i+k-1
    #         while _i > i and _i < n:
    #             if s[_i] == '*':
    #                 t = _i
    #                 break
    #             _i -= 1
            
    #         jump += 1
    #         if _i >= n: break
    #         i = t

    #         i += 1
    
    #     print(jump)
    