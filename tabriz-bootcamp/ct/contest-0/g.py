n, m, w = map(int, input().split())
a = list(map(int, input().split()))

def can(arr, days, w, t):
    k = len(arr)
    if min(arr) + days < t: return False
    partial = [0] * k
    acc = 0
    q = 0
    for i in range(k):
        acc += partial[i]
        arr[i] += acc
        if arr[i]< t:
            acc += t - arr[i]
            q += t - arr[i]
            if i+w < k: partial[i+w] -= t - arr[i]
            arr[i] = t
        if q > days:
            return False
    return min(arr) >= t


l, r = 0, 10**10

ok = min(a)

while l <= r:
    mid = (l + r + 1) // 2
    b = can(a.copy(), m, w, mid)
    # print('check: {}'.format(b))
    if b:
        ok = max(mid, ok)
        l = mid + 1
    else:
        r = mid - 1



# while can(a, m, w, ok+1): ok += 1
# while not can(a, m, w, ok): ok -= 1
# while can(a, m, w, ok+1): ok += 1

print(ok)