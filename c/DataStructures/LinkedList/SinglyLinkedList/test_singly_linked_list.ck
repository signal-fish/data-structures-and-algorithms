#include "singly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

List *list;

void list_setup(){
    list = new_singly_linked_list();
    ck_assert_msg(list != NULL, "list_setup failed...\n");
}

void list_teardown() {
    destroy(list);
}

#suite List

#tcase List Util

#test test_append
    list = new_singly_linked_list();
    ck_assert_msg(list->length == 0, "test_append 1 failed...\n");
    ck_assert_msg(append(list, 1) == 0, "test_append 2 failed...\n");
    ck_assert_msg(append(list, 2) == 0, "test_append 2 failed...\n");
    ck_assert_msg(list->length == 2, "test_append 4 failed...\n");

#test test_get_item
    list = new_singly_linked_list();
    ck_assert_msg(get_item(list, 0) == -1, "test_get_item 1 failed...\n");
    append(list, 1);
    ck_assert_msg(get_item(list, 0) == 1, "test_get_item 2 failed...\n");
    ck_assert_msg(get_item(list, 1) == -1, "test_get_item 3 failed...\n");

#test test_prepend
    list = new_singly_linked_list();
    ck_assert_msg(prepend(list, 1) == 0, "test_prepend 1 failed...\n");
    ck_assert_msg(list->length == 1, "test_prepend 2 failed...\n"); 

#test test_insert
    list = new_singly_linked_list();
    append(list, 1);
    append(list, 2);
    ck_assert_msg(insert(list, -1, 1) == -1, "test_insert 1 failed...\n");
    ck_assert_msg(insert(list, 2, 2) == -1, "test_insert 2 failed...\n");
    ck_assert_msg(insert(list, 0, 1) == 0, "test_insert 3 failed...\n");
    ck_assert_msg(list->length == 3, "test_insert 4 failed...\n");

#test test_print
    list = new_singly_linked_list();
    print(list);
    append(list, 1);
    print(list);
    append(list, 2);
    print(list);

#test test_update
    list = new_singly_linked_list();
    ck_assert_msg(update(list, 0, 0) == -1, "test_update 1 failed...\n");
    append(list, 1);
    append(list, 2);
    ck_assert_msg(update(list, -1, 1) == -1, "test_update 2 failed...\n");
    ck_assert_msg(update(list, 0, 0) == 0, "test_update 3 failed...\n");
    ck_assert_msg(update(list, 1, 999) == 0, "test_update 4 failed...\n");
    ck_assert_msg(list->length == 2, "test_update 5 failed...\n");

#test test_delete_node
    list = new_singly_linked_list();
    ck_assert_msg(delete_node(list, 0) == -1, "test_delete_node 1 failed...\n");
    append(list, 1);
    append(list, 2);
    ck_assert_msg(delete_node(list, -1) == -1, "test_delete_node 2 failed...\n");
    ck_assert_msg(delete_node(list, 0) == 0, "test_delete_node 3 failed...\n");
    ck_assert_msg(list->length == 1, "test_delete_node 4 failed...\n");

#test test_clear
    list = new_singly_linked_list();
    ck_assert_msg(clear(list) == 0, "test_clear 1 failed...\n");
    append(list, 1);
    append(list, 2);
    append(list, 3);
    ck_assert_msg(clear(list) == 0, "test_clear 2 failed...\n");
    ck_assert_msg(list->length == 0, "test_clear 3 failed...\n");

#test test_count
    list = new_singly_linked_list();
    ck_assert_msg(count(list, 0) == 0, "test_count 1 failed...\n");
    append(list, 1);
    append(list, 1);
    append(list, 2);
    ck_assert_msg(count(list, 1) == 2, "test_count 2 failed...\n");
    ck_assert_msg(count(list, 2) == 1, "test_count 3 failed...\n");

#test test_asc_sort
    int compare(int *n1, int *n2) {
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
    list = new_singly_linked_list();
    for (int i = 0; i < 100; i++) {
        append(list, (int)(rand() % 100));
    }
    int arr[list->length];
    for (int i = 0; i < list->length; i++) {
        arr[i] = get_item(list, i);
    }
    qsort(arr, list->length, sizeof(int), (void *)compare);
    asc_sort(list);
    for (int i = 0; i < list->length; i++) {
        ck_assert_msg(arr[i] == get_item(list, i), "test_asc_sort failed...\n");
    }


#main-pre
    tcase_add_checked_fixture(tc1_1, list_setup, list_teardown);
    srunner_set_log(sr, "list_log.txt");

#main-post
    if (nf != 0) {
        printf("%d tests failed.", nf);
    }
    return 0;