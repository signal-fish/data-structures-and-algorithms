#include "circular_queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *queue;

void queue_setup(){}

void queue_teardown() {}

#suite Queue

#tcase Queue Util

#test test_init_circular_queue
    queue = init_circular_queue(3);
    ck_assert_msg(queue != NULL, "test_init_circular_queue 1 failed...\n");
    ck_assert_msg(queue->length == 0, "test_init_circular_queue 2 failed...\n");
    ck_assert_msg(queue->capacity == 3, "test_init_circular_queue 3 failed...\n");
    ck_assert_msg(queue->head == -1, "test_init_circular_queue 4 failed...\n");
    ck_assert_msg(queue->tail == -1, "test_init_circular_queue 5 failed...\n");
    destroy(queue);

#test test_init_circular_queue_neg
    ck_assert_msg(init_circular_queue(-1) == NULL, "test_init_circular_queue_neg 1 failed...\n");

#test test_en_queue
    queue = init_circular_queue(3);
    ck_assert_msg(en_queue(queue, 1) == 0, "test_en_queue 1 failed...\n");
    ck_assert_msg(queue->head == 0, "test_en_queue 2 failed...\n");
    ck_assert_msg(queue->tail == 0, "test_en_queue 3 failed...\n");
    ck_assert_msg(queue->length == 1, "test_en_queue 4 failed...\n");
    ck_assert_msg(en_queue(queue, 2) == 0, "test_en_queue 5 failed...\n");
    ck_assert_msg(queue->head == 0, "test_en_queue 6 failed...\n");
    ck_assert_msg(queue->tail == 1, "test_en_queue 7 failed...\n");
    ck_assert_msg(queue->length == 2, "test_en_queue 8 failed...\n");
    ck_assert_msg(en_queue(queue, 3) == 0, "test_en_queue 9 failed...\n");
    ck_assert_msg(queue->head == 0, "test_en_queue 10 failed...\n");
    ck_assert_msg(queue->tail == 2, "test_en_queue 11 failed...\n");
    ck_assert_msg(queue->length == 3, "test_en_queue 12 failed...\n");
    ck_assert_msg(en_queue(queue, 4) == -1, "test_en_queue 9 failed...\n");
    ck_assert_msg(queue->head == 0, "test_en_queue 10 failed...\n");
    ck_assert_msg(queue->tail == 2, "test_en_queue 11 failed...\n");
    ck_assert_msg(queue->length == 3, "test_en_queue 12 failed...\n");
    destroy(queue);
    
#test test_de_queue
    queue = init_circular_queue(3);
    en_queue(queue, 1);
    en_queue(queue, 2);
    en_queue(queue, 3);
    ck_assert_msg(de_queue(queue) == 1, "test_de_queue 1 failed...\n");
    ck_assert_msg(queue->length == 2, "test_de_queue 2 failed...\n");
    ck_assert_msg(queue->head == 1, "test_de_queue 3 failed...\n");
    ck_assert_msg(de_queue(queue) == 2, "test_de_queue 4 failed...\n");
    ck_assert_msg(queue->length == 1, "test_de_queue 5 failed...\n");
    ck_assert_msg(queue->head == 2, "test_de_queue 6 failed...\n");
    ck_assert_msg(de_queue(queue) == 3, "test_de_queue 7 failed...\n");
    ck_assert_msg(queue->length == 0, "test_de_queue 8 failed...\n");
    ck_assert_msg(queue->head == -1, "test_de_queue 9 failed...\n");
    ck_assert_msg(queue->tail == -1, "test_de_queue 10 failed...\n");
    destroy(queue);

#test test_get_head
    queue = init_circular_queue(3);
    en_queue(queue, 1);
    en_queue(queue, 2);
    en_queue(queue, 3);
    ck_assert_msg(get_head(queue) == 1, "test_get_head 1 failed...\n");
    de_queue(queue);
    ck_assert_msg(get_head(queue) == 2, "test_get_head 2 failed...\n");
    de_queue(queue);
    ck_assert_msg(get_head(queue) == 3, "test_get_head 3 failed...\n");
    de_queue(queue);
    ck_assert_msg(get_head(queue) == -1, "test_get_head 4 failed...\n");
    destroy(queue);

#test test_print
    queue = init_circular_queue(3);
    print(queue);
    en_queue(queue, 1);
    print(queue);
    en_queue(queue, 2);
    print(queue);
    en_queue(queue, 3);
    print(queue);
    de_queue(queue);
    print(queue);
    de_queue(queue);
    print(queue);
    de_queue(queue);
    print(queue);

#main-pre
    tcase_add_checked_fixture(tc1_1, queue_setup, queue_teardown);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_set_log(sr, "queue_log.txt");

#main-post
    if (nf != 0) {
        printf("%d tests failed.\n", nf);
    }
    return 0;
