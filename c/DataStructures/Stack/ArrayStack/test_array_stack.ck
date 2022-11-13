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

#suite Stack

#tcase Stack Util

#test test_init_stack_neg
    ck_assert_msg(init_stack(-1) == NULL, "test_init_stack_neg 1 failed...\n");
    ck_assert_msg(init_stack(0) == NULL, "test_init_stack_neg 2 failed...\n");

#test test_push
    stack = init_stack(2);
    ck_assert_msg(push(stack, 1) == 0, "test_push 1 failed...\n");
    ck_assert_msg(push(stack, 2) == 0, "test_push 2 failed...\n");
    ck_assert_msg(push(stack, 3) == -1, "test_push 3 failed...\n");
    ck_assert_msg(stack->top == 1, "test_push 4 failed...\n");

#test test_pop
    stack = init_stack(2);
    ck_assert_msg(pop(stack) == -1, "test_pop 1 failed...\n");
    push(stack, 1);    
    push(stack, 2);
    ck_assert_msg(pop(stack) == 2, "test_pop 2 failed...\n");    
    ck_assert_msg(pop(stack) == 1, "test_pop 3 failed...\n");    
    ck_assert_msg(stack->top == -1, "test_pop 4 failed...\n");

#test test_get_top
    stack = init_stack(2);
    ck_assert_msg(get_top(stack) == -1, "test_get_top 1 failed...\n");
    push(stack, 1);
    push(stack, 2);
    ck_assert_msg(get_top(stack) == 2, "test_get_top 2 failed...\n");

#test test_print
    stack = init_stack(5);
    print(stack);
    push(stack, 1);
    print(stack);
    push(stack, 2);
    print(stack);
    push(stack, 3);
    push(stack, 4);
    print(stack);

#main-pre
    tcase_add_checked_fixture(tc1_1, stack_setup, stack_teardown);
    srunner_set_log(sr, "stack_log.txt");

#main-post
    if (nf != 0) {
        printf("%d tests failed.", nf);
    }
    return 0;
