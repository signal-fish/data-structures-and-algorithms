def merge(arr, low, mid, high):
    n1 = mid - low + 1
    n2 = high - mid

    L = arr[:n1]
    R = arr[(mid+1):high+1]

    for i in range(n1):
        L[i] = arr[low+i]

    for j in range(n2):
        R[j] = arr[mid+1+j]

    i = 0
    j = 0
    k = low

    while (i < n1 and j < n2):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1


def __merge_sort(arr, low, high):
    if (low < high):
        mid = int((low + high) / 2)
        __merge_sort(arr, low, mid)
        __merge_sort(arr, mid+1, high)
        merge(arr, low, mid, high)


def merge_sort(arr, size):
    __merge_sort(arr, 0, size - 1)


a = [6, 5, 12, 10, 9, 1]
print(a)
merge_sort(a, len(a))
print(a)
