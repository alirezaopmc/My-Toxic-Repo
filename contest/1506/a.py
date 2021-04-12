def get_coords_columns(n, m, v):
    j = (v - 1) // n
    i = (v - 1) % n
    return i, j

def get_value_rows(n, m, i, j):
    # print(n, m, i, j)
    return i * m + j + 1


for _ in range(int(input())):
    n, m, x = map(int, input().split())
    i, j = get_coords_columns(n, m, x)
    print(get_value_rows(n, m, i, j))

