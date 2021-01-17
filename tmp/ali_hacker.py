n = int(input())
a = sorted(list(map(int, input().split())))
print(sum(a[:n//3]))