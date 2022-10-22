/**********************************************
 > File Name: stack.h
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: This is a header file of stack.c
***********************************************/

typedef struct array_stack {
  int capacity;
  int top;
  int *arr;
} Stack;

#define is_empty(stack) (stack->top == -1)
#define is_full(stack) (stack->top == (stack->capacity - 1))