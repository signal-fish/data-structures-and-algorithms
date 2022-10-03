def asc_insertion_sort(arr):
    length = len(arr)
    i = 1
    while (i < length):
        sentry = arr[i]
        j = i - 1
        while (j >= 0) & (arr[j] > sentry):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = sentry
        i += 1

    return arr


def des_insertion_sort(arr):
    length = len(arr)
    i = 1
    while (i < length):
        sentry = arr[i]
        j = i - 1
        while (j >= 0) & (arr[j] < sentry):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = sentry
        i += 1

    return arr


if __name__ == '__main__':
    main()
