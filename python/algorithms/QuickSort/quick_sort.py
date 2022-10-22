from random import randint


def partion(arr, low, high):
    pivot = arr[high]
    i = low
    j = low
    while (i <= high):
        if (arr[i] > pivot):
            i += 1
        else:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j += 1
    return j - 1


def __quick_sort(arr, low, high):
    if low < high:
        p = partion(arr, low, high)
        __quick_sort(arr, low, p-1)
        __quick_sort(arr, p+1, high)


def quick_sort(arr, size):
    __quick_sort(arr, 0, size-1)


arr1 = [randint(i, i+10) for i in range(10)]
print(arr1)
quick_sort(arr1, len(arr1))
print(arr1)
