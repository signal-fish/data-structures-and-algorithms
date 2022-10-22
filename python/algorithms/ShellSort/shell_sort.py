from random import randint


def asc_shell_sort(arr):
    size = len(arr)
    gap = size // 2
    while gap > 0:
        i = gap
        while i < size:
            temp = arr[i]
            j = i
            while j >= gap and (arr[j-gap] > temp):
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp
            i += 1
        gap //= 2


arr1 = [randint(i, i+10) for i in range(10)]
print(arr1)
asc_shell_sort(arr1)
print(arr1)
