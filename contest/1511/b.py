# i = 1000000000 - 1

# c = 0
# while i > 0:
#     j = 3
#     flag = True
#     while j * j <= i:
#         if i % j == 0:
#             flag = False
#             break
#         j += 2
#     if flag:
#         print(i)
#         c += 1
#         if c == 2:
#             i = i // 10 + 1
#             if i % 2 == 0:
#                 i += 1
#             c = 0
#     i -= 2
p = [
    [
        999999937,
        99999989,
        9999991, 
        999983,  
        99991,
        9973,
        997,
        97,
        7,
        1
    ],[
        999999929,
        99999971,
        9999973,
        999979,
        99989,
        9967,
        983,
        89,
        5,
        1
    ]
]

p[0].reverse()
p[1].reverse()

for _ in range(int(input())):
    a, b, c = map(int, input().split())
    c -= 1

    x = p[int(a == b)][a-c] * (10 ** c)
    y = p[1-int(a == b)][b-c] * (10 ** c)

    print(x, y)

