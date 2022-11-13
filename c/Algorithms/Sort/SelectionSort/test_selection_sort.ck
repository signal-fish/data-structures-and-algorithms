#include "selection_sort.h"
#include <stdio.h>
#include <stdlib.h>


void selection_sort_setup() {
}

void selection_sort_teardown() {
}

#suite selectionSort

#tcase selectionSort Util

#test test_selection_sort
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
    selection_sort(arr2, size);
    for (int i = 0; i < size; i++) {
        ck_assert_msg(arr1[i] == arr2[i], "test_selection_sort failed...\n");
    }

#main-pre
    tcase_add_checked_fixture(tc1_1, selection_sort_setup, selection_sort_teardown);
    srunner_set_log(sr, "selection_sort_log.txt");

#main-post
    if (nf != 0) {
        printf("%d tests failed.", nf);
    }
    return 0;
