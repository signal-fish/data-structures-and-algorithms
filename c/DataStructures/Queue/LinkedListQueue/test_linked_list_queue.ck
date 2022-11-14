#include "linked_list_queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *queue;
Node *node;

void queue_setup(){}

void queue_teardown() {}

#suite Queue

#tcase Queue Util

#test test_new_node
    node = new_node(1);
    ck_assert_msg(node != NULL, "test_new_node 1 failed...\n");
    ck_assert_msg(node->val == 1, "test_new_node 2 failed...\n");
    ck_assert_msg(node->next == NULL, "test_new_node 3 failed...\n");
    free(node);
    node = NULL;

#test test_init_list_queue
    queue = init_list_queue();
    ck_assert_msg(queue != NULL, "queue_setup 1 failed...\n");
    ck_assert_msg(queue->head == NULL, "queue_setup 2 failed...\n");
    ck_assert_msg(queue->tail == NULL, "queue_setup 3 failed...\n");
    ck_assert_msg(queue->length == 0, "queue_setup 4 failed...\n");
    destroy(queue);


#test test_en_queue
    queue = init_list_queue();
    ck_assert_msg(en_queue(queue, 1) == 0, "test_en_queue 1 failed...\n");
    ck_assert_msg(queue->length == 1, "test_en_queue 2 failed...\n");
    ck_assert_msg(queue->head != NULL, "test_en_queue 3 failed...\n");
    ck_assert_msg(queue->tail != NULL, "test_en_queue 4 failed...\n");
    ck_assert_msg(en_queue(queue, 1) == 0, "test_en_queue 5 failed...\n");
    ck_assert_msg(queue->length == 2, "test_en_queue 6 failed...\n");
    ck_assert_msg(queue->head != NULL, "test_en_queue 7 failed...\n");
    ck_assert_msg(queue->tail != NULL, "test_en_queue 8 failed...\n");
    ck_assert_msg(en_queue(queue, 1) == 0, "test_en_queue 9 failed...\n");
    ck_assert_msg(queue->length == 3, "test_en_queue 10 failed...\n");
    ck_assert_msg(queue->head != NULL, "test_en_queue 11 failed...\n");
    ck_assert_msg(queue->tail != NULL, "test_en_queue 12 failed...\n");
    destroy(queue);

#test test_de_queue
    queue = init_list_queue();
    ck_assert_msg(de_queue(queue) == -1, "test_de_queue 1 failed...\n");
    en_queue(queue, 1);
    en_queue(queue, 2);
    en_queue(queue, 3);
    ck_assert_msg(de_queue(queue) == 1, "test_de_queue 2 failed...\n");
    ck_assert_msg(queue->head != NULL, "test_de_queue 3 failed...\n");
    ck_assert_msg(queue->tail != NULL, "test_de_queue 4 failed...\n");
    ck_assert_msg(de_queue(queue) == 2, "test_de_queue 5 failed...\n");
    ck_assert_msg(queue->head != NULL, "test_de_queue 6 failed...\n");
    ck_assert_msg(queue->tail != NULL, "test_de_queue 7 failed...\n");
    ck_assert_msg(de_queue(queue) == 3, "test_de_queue 8 failed...\n");
    ck_assert_msg(queue->head == NULL, "test_de_queue 9 failed...\n");
    ck_assert_msg(queue->tail == NULL, "test_de_queue 10 failed...\n");
    ck_assert_msg(de_queue(queue) == -1, "test_de_queue 11 failed...\n");
    destroy(queue);

#test test_print
    queue = init_list_queue();
    print(queue);
    en_queue(queue, 1);
    print(queue);
    en_queue(queue, 2);
    print(queue);
    en_queue(queue, 3);
    print(queue);
    destroy(queue);

#main-pre
    tcase_add_checked_fixture(tc1_1, queue_setup, queue_teardown);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_set_log(sr, "queue_log.txt");

#main-post
    if (nf != 0) {
        printf("%d tests failed.", nf);
    }
    return 0;
