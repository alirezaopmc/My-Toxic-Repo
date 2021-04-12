mat = [
    [12, 22, 32, 42],
    [23, 27, 28, 13],
    [37, 25, 36, 47],
    [62, 28, 17, 29]
]

def min_of_matrix(mat, ax, ay, bx, by):
    mins = []
    n, m = len(mat), len(mat[0])

    if ax >= m <= bx or ay >= n <= by:
        return mins

    def is_min(i, j):
        if i-1 >= 0:
            if mat[i-1][j] <= mat[i][j]: return False
        if j-1 >= 0:
            if mat[i][j-1] <= mat[i][j]: return False
        if i+1 < n:
            if mat[i+1][j] <= mat[i][j]: return False
        if j+1 < m:
            if mat[i][j+1] <= mat[i][j]: return False
        return True

    def add(l):
        for x in l:
            mins.append(x)

    if ax == bx and ay == by:
        if is_min(ay, ax):
           mins.append((ax, ay))
        return mins
    
    mx = (ax + bx) // 2
    my = (ay + by) // 2

    add(
        min_of_matrix(mat, ax, ay, mx, my)
    )

    add(
        min_of_matrix(mat, ax, my+1, mx, by)
    )

    add(
        min_of_matrix(mat, mx+1, ay, bx, my)
    )

    add(
        min_of_matrix(mat, mx+1, my+1, bx, by)
    )

    return mins

print(min_of_matrix(mat, 0, 0, 3, 3))