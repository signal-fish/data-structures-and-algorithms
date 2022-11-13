/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "test_array_stack.ck" instead.
 */

#include <check.h>

#line 1 "test_array_stack.ck"
#include "array_stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stack;

void stack_setup(){
    stack = init_stack(1);
    ck_assert_msg(stack->capacity == 1, "stack_setup 1 failed...\n");
    ck_assert_msg(stack->top == -1, "stack_setup 2 failed...\n");
    ck_assert_msg(stack != NULL, "stack_setup failed...\n");
}

void stack_teardown() {
    destroy(stack);
}



START_TEST(test_init_stack_neg)
{
#line 23
    ck_assert_msg(init_stack(-1) == NULL, "test_init_stack_neg 1 failed...\n");
    ck_assert_msg(init_stack(0) == NULL, "test_init_stack_neg 2 failed...\n");

}
END_TEST

START_TEST(test_push)
{
#line 27
    stack = init_stack(2);
    ck_assert_msg(push(stack, 1) == 0, "test_push 1 failed...\n");
    ck_assert_msg(push(stack, 2) == 0, "test_push 2 failed...\n");
    ck_assert_msg(push(stack, 3) == -1, "test_push 3 failed...\n");
    ck_assert_msg(stack->top == 1, "test_push 4 failed...\n");

}
END_TEST

START_TEST(test_pop)
{
#line 34
    stack = init_stack(2);
    ck_assert_msg(pop(stack) == -1, "test_pop 1 failed...\n");
    push(stack, 1);    
    push(stack, 2);
    ck_assert_msg(pop(stack) == 2, "test_pop 2 failed...\n");    
    ck_assert_msg(pop(stack) == 1, "test_pop 3 failed...\n");    
    ck_assert_msg(stack->top == -1, "test_pop 4 failed...\n");

}
END_TEST

START_TEST(test_get_top)
{
#line 43
    stack = init_stack(2);
    ck_assert_msg(get_top(stack) == -1, "test_get_top 1 failed...\n");
    push(stack, 1);
    push(stack, 2);
    ck_assert_msg(get_top(stack) == 2, "test_get_top 2 failed...\n");

}
END_TEST

START_TEST(test_print)
{
#line 50
    stack = init_stack(5);
    print(stack);
    push(stack, 1);
    print(stack);
    push(stack, 2);
    print(stack);
    push(stack, 3);
    push(stack, 4);
    print(stack);

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Stack");
    TCase *tc1_1 = tcase_create("Stack Util");
    SRunner *sr = srunner_create(s1);
    int nf;

    /* User-specified pre-run code */
#line 61
    tcase_add_checked_fixture(tc1_1, stack_setup, stack_teardown);
    srunner_set_log(sr, "stack_log.txt");


    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_init_stack_neg);
    tcase_add_test(tc1_1, test_push);
    tcase_add_test(tc1_1, test_pop);
    tcase_add_test(tc1_1, test_get_top);
    tcase_add_test(tc1_1, test_print);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    /* User-specified post-run code */
#line 65
    if (nf != 0) {
        printf("%d tests failed.", nf);
    }
    return 0;
}
