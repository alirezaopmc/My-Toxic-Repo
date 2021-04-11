def binary_search_2d(matrix, element):
    n, m = len(matrix), len(matrix[0])
    start, end = 0, n * m - 1

    while start <= end:
        mid = start + (end - start) // 2
        row = mid // m
        col = mid % m
        val = matrix[row][col]

        if val == element:
            return (row, col)
        elif val > element:
            end = mid - 1
        else:
            start = mid + 1
    
    return (-1, -1)

mat = [
    [1, 5, 6],
    [2, 7, 8],
    [5, 8, 9]
]

print(binary_search_2d(mat, 7))
print(binary_search_2d(mat, 8))
print(binary_search_2d(mat, 4))