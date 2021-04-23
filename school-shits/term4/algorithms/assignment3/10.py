"""

Because the problem is being maximum difference
it's a simple greedy problem. Partion elements
such a way those smaller one be in same group,
so the sorting idea comes up.

According to the required complexity merge sort
is the answer.


"""

def merge(arr, left, right):
    # arr = merged [ left + right]
    pass

def merge_sort(arr, left, right):
    mid = (left + right) // 2
    merge_sort(arr, left, mid)
    merge_sort(arr, mid, right)
    pass