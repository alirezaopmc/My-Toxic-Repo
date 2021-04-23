arr1 = [8,4,2]

def bubble_like_sort(arr):
    n = len(arr)
    i = 0
    while i < n:
        if i > 0:
            if arr[i] < arr[i-1]:
                arr[i], arr[i-1] = arr[i-1], arr[i]
                i -= 1
                continue
        i += 1