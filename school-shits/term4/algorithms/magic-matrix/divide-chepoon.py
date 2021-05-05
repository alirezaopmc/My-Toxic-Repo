st = set()

def mult_submat(mat, a, b, c, d, k):
    m = 1
    for i in range(a, c+1):
        for j in range(b, d+1):
            m *= mat[i][j]
    if m != k: return 0
    st.add((a, b, c, d))
    return 1

def magic_matrix(mat, a, b, c, d, k):
    if a == c and b == d:
        return mult_submat(mat, a, b, c, d, k)

    x, y = a + (c - a) // 2, b + (d - b) // 2

    ans = magic_matrix(mat, a, b, x, y, k)
    if y+1 <= d: ans += magic_matrix(mat, a, y+1, x, d, k)
    if x+1 <= c: ans += magic_matrix(mat, x+1, b, c, y, k)
    if x+1 <= d and x+1 <= c: ans += magic_matrix(mat, x+1, y+1, c, d, k)
    

    for i1 in range(a, x+1):
        for j1 in range(b, y+1):
            for i2 in range(a, c+1):
                for j2 in range(y+1, d+1):
                    ans += mult_submat(mat, i1, j1, i2, j2, k)
    
    for i1 in range(a, x+1):
        for j1 in range(b, y+1):
            for i2 in range(x+1, c+1):
                for j2 in range(b, y+1):
                    ans += mult_submat(mat, i1, j1, i2, j2, k)
    
    for i1 in range(a, x+1):
        for j1 in range(y+1, d+1):
            for i2 in range(x+1, c+1):
                for j2 in range(y+1, d+1):
                    ans += mult_submat(mat, i1, j1, i2, j2, k)
    
    for i1 in range(x+1, c+1):
        for j1 in range(b, y+1):
            for i2 in range(x+1, c+1):
                for j2 in range(y+1, d+1):
                    ans += mult_submat(mat, i1, j1, i2, j2, k)

    return ans

a = [
    [1, 1, 2, 3],
    [3, 2, 1, 1],
    [2, 3, 2, 6]
]


print(magic_matrix(a, 0, 0, 2, 3, 12))

# all answers are stored in set `st`