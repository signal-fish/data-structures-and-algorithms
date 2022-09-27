def asc_bubble_sort(arr):
    i = 0
    swap = True

    while (i < len(arr) - 1) & swap:
        swap = False
        j = len(arr) - 2
        while j >= i:
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swap = True
            j -= 1
        i += 1
    return arr

def des_bubble_sort(arr):
    i = len(arr) - 1
    swap = True

    while i > 0 & swap:
        swap = False
        j = 0
        while j < i:
            if arr[j] < arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swap = True
            j += 1
        i -= 1
    return arr


if __name__ == "__main__":
    main()
