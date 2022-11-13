/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "test_selection_sort.ck" instead.
 */

#include <check.h>

#line 1 "test_selection_sort.ck"
#include "selection_sort.h"
#include <stdio.h>
#include <stdlib.h>


void selection_sort_setup() {
}

void selection_sort_teardown() {
}



START_TEST(test_selection_sort)
{
#line 17
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

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("selectionSort");
    TCase *tc1_1 = tcase_create("selectionSort Util");
    SRunner *sr = srunner_create(s1);
    int nf;

    /* User-specified pre-run code */
#line 45
    tcase_add_checked_fixture(tc1_1, selection_sort_setup, selection_sort_teardown);
    srunner_set_log(sr, "selection_sort_log.txt");


    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_selection_sort);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    /* User-specified post-run code */
#line 49
    if (nf != 0) {
        printf("%d tests failed.", nf);
    }
    return 0;
}
