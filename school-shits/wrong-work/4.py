A = list(map(int, input().split()))

def binary_search(arr: list, item: int):
    l, r = 0, len(arr)-1
    while l <= r:
        if l == r:
            if arr[l] > item:
                return l
            else:
                return l + 1

        mid = (l + r) // 2

        if arr[mid] == item:
            return mid
        elif arr[mid] < item:
            l = mid + 1
        else:
            r = mid - 1
    
    return l

def binaryInsertionSort(arr: list):
    n = len(arr)
    for i in range(1, n):
        t = arr[i]
        j = binary_search(arr[:i], t)
        arr = arr[:j] + [t] + arr[j:i] + arr[i+1:]
    return arr

