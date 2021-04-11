A = list(set(map(int, input().split())))

def showSubsets(arr: list):
    n = len(arr)
    for i in range(n-2):
        for j in range(i+1, n-1):
            for k in range(j+1, n):
                print('{} {} {}'.format(arr[i], arr[j], arr[k]))

showSubsets(A)