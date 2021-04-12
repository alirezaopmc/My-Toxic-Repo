n, m = map(int, input().split())

INF = 10 ** 10

S = [INF] * n
E = [INF] * n

for _ in range(m):
    r, c = map(int, input().split)
    S[r] = min(S[r], c)
    E[r] = min(E[r], c)

def solve(i: int, s: int, e: int):
    global S, E

    if i == n-1:
        pass

    