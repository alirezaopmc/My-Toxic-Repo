for _ in range(int(input())):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    a.sort()
    b.sort()

    cnt = 0

    i = 0
    j = 0

    while i < len(a) or j < len(b):
        if a[i] == b[j]:
            cnt += 1
            if i+1 >= len(a) and j+1 >= len(b): break
            if i+1 < len(a): i += 1
            if j+1 < len(b): j += 1
        elif a[i] < b[j]:
            if i+1 < len(a):
                i += 1
            else:
                break
        else:
            if j+1 < len(b):
                j += 1
            else:
                break
    
    print(cnt)