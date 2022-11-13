#include "array.h"
#include <stdio.h>
#include <stdlib.h>

Array *array, *_array;

void array_setup() {
    array = init_array(10);
    ck_assert_msg(array != NULL, "array initialized failed;");
}

void array_teardown() {
    destroy(array);
}

#suite Array

#tcase Array Util

#test test_init_array_neg
    array = init_array(-1);
    ck_assert_msg(array == NULL, "test_init_array_neg failed...\n");

#test test_append
    array = init_array(1);
    ck_assert_msg(append(array, 1) == 0, "test_append 1 failed...\n");
    ck_assert_msg(append(array, 2) == -1, "test_append 2 failed...\n");

#test test_pop
    array = init_array(2);
    ck_assert_msg(pop(array) == -1, "test_pop 1 failed...\n");
    append(array, 1);
    ck_assert_msg(pop(array) == 1, "test_pop 2 failed...\n");

#test test_print
    printf("test_print begin...\n");
    array = init_array(1);
    print(array);
    append(array, 1);
    print(array);
    printf("test_print end...\n");

#test test_get
    array = init_array(3);
    ck_assert_msg(get(array, -1) == -1, "test_get 1 failed...\n");
    ck_assert_msg(get(array, 3) == -1, "test_get 2 failed...\n");
    append(array, 1);
    append(array, 2);
    append(array, 3);
    ck_assert_msg(get(array, 0) == 1, "test_get 3 failed...\n");
    ck_assert_msg(get(array, 1) == 2, "test_get 4 failed...\n");
    ck_assert_msg(get(array, 2) == 3, "test_get 5 failed...\n");


#test test_insert
    array = init_array(1);
    ck_assert_msg(insert(array, -1, 0) == -1, "test_insert 1 failed...\n");
    ck_assert_msg(insert(array, 2, 1) == -1, "test_insert 2 failed...\n");
    ck_assert_msg(insert(array, 0, 1) == 0, "test_insert 3 failed...\n");

#test test_count
    array = init_array(2);
    ck_assert_msg(count(array, 1) == 0, "test_count 1 failed...\n");
    append(array, 1);
    append(array, 1);
    ck_assert_msg(count(array, 1) == 2, "test_count 2 failed...\n");

#test test_array_index
    array = init_array(3);
    ck_assert_msg(array_index(array, 1) == -1, "test_array_index 1 failed...\n");
    append(array, 1);
    append(array, 2);
    append(array, 3);
    ck_assert_msg(array_index(array, 1) == 0, "test_array_index 2 failed...\n");
    ck_assert_msg(array_index(array, 2) == 1, "test_array_index 3 failed...\n");

#test test_array_last_index
    array = init_array(3);
    ck_assert_msg(array_last_index(array, 1) == -1, "test_array_last_index 1 failed...\n");
    append(array, 1);
    append(array, 2);
    append(array, 2);
    ck_assert_msg(array_last_index(array, 1) == 0, "test_array_last_index 2 failed...\n");
    ck_assert_msg(array_last_index(array, 2) == 2, "test_array_last_index 3 failed...\n");

#test test_update
    array = init_array(1);
    ck_assert_msg(update(array, 0, 999) == -1, "test_update 1 failed...\n");
    append(array, 1);
    ck_assert_msg(update(array, -1, 1) == -1, "test_update 2 failed...\n");
    ck_assert_msg(update(array, 0, 999) == 0, "test_update 3 failed...\n");

#test test_reverse
    array = init_array(100);
    for (int i = 0; i < 100; i++){
        append(array, (int)(rand() % 100));
    }
    _array = init_array(array->size);
    for (int i = 0; i < array->size; i++){
        append(_array, array->arr[i]);
    }
    reverse(array);
    for (int i = 0, j = array->size - 1; i < array->size && j >= 0; i++, j--){
        ck_assert_msg(array->arr[i] == _array->arr[j], "test_reverse failed...\n");
    }

#test test_asc_sort
    int compare(const int *n1, const int *n2){
        if (*n1 == *n2){
            return 0;
        } else if (*n1 < *n2) {
            return -1;
        } else if (*n1 > *n2) {
            return 1;
        } else {
            return 0;
        }
    }
    array = init_array(100);
    for (int i = 0; i < 100; i++){
        append(array, (int)(rand() % 100));
    }
    int tArray[array->size];
    for (int i = 0; i < array->size; i++){
        tArray[i] = array->arr[i];
    }
    qsort(tArray, array->size, sizeof(int), (void *)compare);
    asc_sort(array);
    for (int i = 0; i < array->size; i++){
        ck_assert_msg(array->arr[i] == tArray[i], "test_reverse failed...\n");
    }

#test test_remove_item
    array = init_array(3);
    ck_assert_msg(remove_item(array, 1) == -1, "test_remove_item 1 failed...\n");
    append(array, 1);
    append(array, 2);
    append(array, 3);
    ck_assert_msg(remove_item(array, 9) == -1, "test_remove_item 2 failed...\n");
    ck_assert_msg(remove_item(array, 0) == 1, "test_remove_item 3 failed...\n");

#test test_clear
    array = init_array(2);
    append(array, 1);
    append(array, 2);
    ck_assert_msg(clear(array) == 0, "test_clear 1 failed...\n");


#main-pre
    tcase_add_checked_fixture(tc1_1, array_setup, array_teardown);
    srunner_set_log(sr, "array_log.txt");

#main-post
    if (nf != 0) {
        printf("%d tests failed.", nf);
    }
    return 0;
