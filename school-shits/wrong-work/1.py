A = list(map(int, input().split()))

def findMax(arr: list) -> int:
    b = arr[0]
    for x in arr:
        if x > b: b = x
    return b

m = findMax(A)
print(m)