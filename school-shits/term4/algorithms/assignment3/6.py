def ternary_search(arr, left, right, element):
    if left > right: return -1

    first = left = left + (right - left) // 3
    second = first + (right - left) // 3

    if arr[first] == element: return first
    if arr[second] == element: return second

    if arr[first] > element:
        return ternary_search(arr, left, first-1, element)
    elif arr[second] < element:
        return ternary_search(arr, first+1, right, element)
    else:
        return ternary_search(arr, first+1, second-1, element)


a = [3, 9, 1, 4, 4, 3, 7]
r1 = ternary_search(a, 0, len(a), 1)
r2 = ternary_search(a, 0, len(a), 5)
print(r1, r2)