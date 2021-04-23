def ternary_merge(arr, temp_arr, left, first, second ,right):
    i, j, k, l = left, first, second, left

    while i < first and j < second and k < right:
        if arr[i]  < arr[j]:
            if arr[i] < arr[k]:
                temp_arr[l] = arr[i]
                i += 1
            else:
                temp_arr[l] = arr[k]
                k += 1
        else:
            if arr[j] < arr[k]:
                temp_arr[l] = arr[j]
                j += 1
            else:
                temp_arr[l] = arr[k]
                k += 1
        l += 1
    
    while i < first and j < second:
        if arr[i] < arr[j]:
            temp_arr[l] = arr[i]
            i += 1
        else:
            temp_arr[l] = arr[j]
            j += 1
        l += 1
    
    
    while j < second and k < right:
        if arr[j] < arr[k]:
            temp_arr[l] = arr[j]
            j += 1
        else:
            temp_arr[l] = arr[k]
            k += 1
        l += 1
    
    
    while i < first and k < right:
        if arr[i] < arr[k]:
            temp_arr[l] = arr[i]
            i += 1
        else:
            temp_arr[l] = arr[k]
            k += 1
        l += 1

    while i < first:
        temp_arr[l] = arr[i]
        l += 1
        i += 1
    
    while j < second:
        temp_arr[l] = arr[j]
        l += 1
        j += 1
    
    while k < right:
        temp_arr[l] = arr[k]
        l += 1
        k += 1


# will sort @param arr and store it in temp_arr
def ternary_merge_sort(arr, temp_arr, left, right):
    if right - left < 2: return

    first = left + (right - left) // 3
    second = left + 2 * (right - left) // 3

    ternary_merge_sort(temp_arr, arr, left, first)
    ternary_merge_sort(temp_arr, arr, first, second)
    ternary_merge_sort(temp_arr, arr, second, right)

    ternary_merge(temp_arr, arr, left, first, second, right)

arr = [1, -2, 5, -5, -3, 2]
sorted_arr = arr.copy()
ternary_merge_sort(sorted_arr, arr, 0, len(arr))
print(sorted_arr)

    