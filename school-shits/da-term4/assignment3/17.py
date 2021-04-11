def hanoi(bars, n, a, b, c):
    def move(i, j):
        bars[j].append(bars[i].pop())
    
    if n == 1:
        move(a, c)
        return
    
    hanoi(bars, n-1, a, c, b)
    move(a, c)
    hanoi(bars, n-1, b, a, c)

bars = [
    [3, 2, 1],
    [],
    []
]

hanoi(bars, len(bars), 0, 1, 2)