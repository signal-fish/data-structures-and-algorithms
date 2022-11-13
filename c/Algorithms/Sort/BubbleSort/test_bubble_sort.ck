#include "bubble_sort.h"
#include <stdio.h>
#include <stdlib.h>


void bubble_sort_setup() {
}

void bubble_sort_teardown() {
}

#suite BubbleSort

#tcase BubbleSort Util

#test test_bubble_sort
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
    bubble_sort(arr2, size);
    for (int i = 0; i < size; i++) {
        ck_assert_msg(arr1[i] == arr2[i], "test_bubble_sort failed...\n");
    }

#main-pre
    tcase_add_checked_fixture(tc1_1, bubble_sort_setup, bubble_sort_teardown);
    srunner_set_log(sr, "bubble_sort_log.txt");

#main-post
    if (nf != 0) {
        printf("%d tests failed.", nf);
    }
    return 0;
