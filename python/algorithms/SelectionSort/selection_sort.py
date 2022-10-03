def asc_selection_sort(arr):
    length = len(arr)
    i = 0
    while (i < length - 1):
        min = i
        j = i + 1
        while (j < length):
            if (arr[min] > arr[j]):
                min = j
            j += 1
        if (i != min):
            arr[i], arr[min] = arr[min], arr[i]
        i += 1

    return arr


def des_selection_sort(arr):
    length = len(arr)
    i = 0
    while (i < length - 1):
        max = i
        j = i + 1
        while (j < length):
            if (arr[max] < arr[j]):
                max = j
            j += 1
        if (i != max):
            arr[i], arr[max] = arr[max], arr[i]
        i += 1

    return arr


if __name__ == '__main__':
    main()
