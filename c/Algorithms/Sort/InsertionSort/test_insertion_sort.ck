#include "insertion_sort.h"
#include <stdio.h>
#include <stdlib.h>


void insertion_sort_setup() {
}

void insertion_sort_teardown() {
}

#suite insertionSort

#tcase insertionSort Util

#test test_insertion_sort
    int size = 100;
    int arr1[size];
    int arr2[size];

    for (int i = 0; i < size; i++) {
        arr1[i] = (int)(rand() % 101);
    } 
    for (int i = 0; i < size; i++) {
        arr2[i] = arr1[i];
    }
    int compare(const int * n1, const int * n2) {
        if (*n1 == *n2) {
            return 0;
        } else if (*n1 > *n2) {
            return 1;
        } else if (*n1 < *n2) {
            return -1;
        } else {
            return 0;
        }
    }
    qsort(arr1, size, sizeof(int), (void *)compare);
    insertion_sort(arr2, size);
    for (int i = 0; i < size; i++) {
        ck_assert_msg(arr1[i] == arr2[i], "test_insertion_sort failed...\n");
    }

#main-pre
    tcase_add_checked_fixture(tc1_1, insertion_sort_setup, insertion_sort_teardown);
    srunner_set_log(sr, "insertion_sort_log.txt");

#main-post
    if (nf != 0) {
        printf("%d tests failed.", nf);
    }
    return 0;
