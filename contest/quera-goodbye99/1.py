n, m = map(int, input().split())

if n == m:
    print('Saal Noo Mobarak!')
elif n > m:
    print('L' * (n-m))
else:
    print('R' * (m-n))