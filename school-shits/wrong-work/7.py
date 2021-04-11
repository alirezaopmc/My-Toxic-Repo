# bst is implemented in array for simplicity
H = list(map(int, input().split()))

def is_heap(arr: list, i: int) -> bool:
    if i >= len(arr): return True
    if arr[i] < arr[2*i+1] or arr[i] >= arr[2*i+2]: return False
    return is_heap(arr, 2*i+1) and is_heap(arr, 2*i+2)
