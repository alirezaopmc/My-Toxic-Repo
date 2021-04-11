A = list(map(int, input().split()))

n = len(A)

def find_min_and_max(arr: list) -> tuple:
    result = [arr[0], arr[0]]
    for x in arr:
        if x > result[1]:
            result[1] = x
        
        if x < result[0]:
            result[0] = x
    return tuple(result)