/**********************************************
 > File Name: array_stack.h
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: This is a header file of array_stack.c
***********************************************/

typedef struct array_stack {
  int capacity;
  int top;
  int *arr;
} Stack;

#define is_empty(stack) (stack->top == -1)
#define is_full(stack) (stack->top == (stack->capacity - 1))

Stack *init_stack(int);
void destroy(Stack *);
int push(Stack *, int);
int pop(Stack *);
int get_top(Stack *);
void print(Stack *);