/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "test_circular_queue.ck" instead.
 */

#include <check.h>

#line 1 "test_circular_queue.ck"
#include "circular_queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *queue;

void queue_setup(){}

void queue_teardown() {}



START_TEST(test_init_circular_queue)
{
#line 16
    queue = init_circular_queue(3);
    ck_assert_msg(queue != NULL, "test_init_circular_queue 1 failed...\n");
    ck_assert_msg(queue->length == 0, "test_init_circular_queue 2 failed...\n");
    ck_assert_msg(queue->capacity == 3, "test_init_circular_queue 3 failed...\n");
    ck_assert_msg(queue->head == -1, "test_init_circular_queue 4 failed...\n");
    ck_assert_msg(queue->tail == -1, "test_init_circular_queue 5 failed...\n");
    destroy(queue);

}
END_TEST

START_TEST(test_init_circular_queue_neg)
{
#line 25
    ck_assert_msg(init_circular_queue(-1) == NULL, "test_init_circular_queue_neg 1 failed...\n");

}
END_TEST

START_TEST(test_en_queue)
{
#line 28
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
    
}
END_TEST

START_TEST(test_de_queue)
{
#line 48
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

}
END_TEST

START_TEST(test_get_head)
{
#line 65
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

}
END_TEST

START_TEST(test_print)
{
#line 79
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

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Queue");
    TCase *tc1_1 = tcase_create("Queue Util");
    SRunner *sr = srunner_create(s1);
    int nf;

    /* User-specified pre-run code */
#line 95
    tcase_add_checked_fixture(tc1_1, queue_setup, queue_teardown);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_set_log(sr, "queue_log.txt");


    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_init_circular_queue);
    tcase_add_test(tc1_1, test_init_circular_queue_neg);
    tcase_add_test(tc1_1, test_en_queue);
    tcase_add_test(tc1_1, test_de_queue);
    tcase_add_test(tc1_1, test_get_head);
    tcase_add_test(tc1_1, test_print);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    /* User-specified post-run code */
#line 100
    if (nf != 0) {
        printf("%d tests failed.\n", nf);
    }
    return 0;
}
