/**********************************************
 > File Name: stack.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: Implement stack with array
***********************************************/

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void non_exist(Stack *stack) {
  if (stack == NULL || stack->arr == NULL) {
    perror("non_exist stack");
    exit(EXIT_FAILURE);
  }
}

// Initialize a stack
Stack *init_stack(int cap) {
  Stack *stack = NULL;
  stack = (Stack *)malloc(sizeof(stack));
  if (stack == NULL) {
    return NULL;
  }
  stack->capacity = cap;
  stack->top = -1;
  stack->arr = (int *)malloc(sizeof(int) * cap);
  if (stack->arr == NULL) {
    free(stack);
    stack = NULL;
    return NULL;
  }
  return stack;
}

// Destroy a stack
void destroy(Stack *stack) {
  non_exist(stack);
  stack->capacity = 0;
  stack->top = -1;
  free(stack->arr);
  stack->arr = NULL;
  free(stack);
  stack = NULL;
  return;
}

// Remove an element from the stack
int pop(Stack *stack) {
  non_exist(stack);
  if (is_empty(stack)) {
    return -1;
  }
  int data = stack->arr[stack->top];
  stack->top--;
  return data;
}

// Add an element to the stack
int push(Stack *stack, int data) {
  non_exist(stack);
  if (is_full(stack)) {
    return -1;
  }
  stack->top++;
  stack->arr[stack->top] = data;
  return 0;
}

// Get the element of stack at the top position
int get_top(Stack *stack) {
  non_exist(stack);
  if (is_empty(stack)) {
    return -1;
  }
  return stack->arr[stack->top];
}

// Print stack
void print(Stack *stack) {
  if (stack->arr == NULL) {
    non_exist(stack);
    return;
  }
  if (is_empty(stack)) {
    printf("[");
    return;
  }
  printf("[");
  for (int i = 0; i <= stack->top; i++) {
    if (i != stack->top) {
      printf("%d[", stack->arr[i]);
    } else {
      printf("%d\n", stack->arr[i]);
    }
  }
  return;
}

int main() {
  Stack *stack = init_stack(5);
  // destroy(stack);
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  print(stack);

  printf("%d\n", get_top(stack));

  pop(stack);
  print(stack);

  // destroy(stack);
  push(stack, 1);
  print(stack);

  return 0;
}