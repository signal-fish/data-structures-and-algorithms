/**********************************************
 > File Name: array_stack.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: Implement stack with array
***********************************************/

#include "array_stack.h"

#include <stdio.h>
#include <stdlib.h>

// Initialize a stack
Stack *init_stack(int cap) {
  if (cap == 0) {
    return NULL;
  }
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
  if (stack == NULL || stack->arr == NULL) {
    return;
  }
  stack->capacity = 0;
  stack->top = -1;
  free(stack->arr);
  stack->arr = NULL;
  free(stack);
  stack = NULL;
  return;
}

// Add an element to the stack
int push(Stack *stack, int data) {
  if (stack == NULL || stack->arr == NULL) {
    return -1;
  }
  if (is_full(stack)) {
    return -1;
  }
  stack->top++;
  stack->arr[stack->top] = data;
  return 0;
}

// Remove an element from the stack
int pop(Stack *stack) {
  if (stack == NULL || stack->arr == NULL) {
    return -1;
  }
  if (is_empty(stack)) {
    return -1;
  }
  int data = stack->arr[stack->top];
  stack->top--;
  return data;
}

// Get the element of stack at the top position
int get_top(Stack *stack) {
  if (stack == NULL || stack->arr == NULL) {
    return -1;
  }
  if (is_empty(stack)) {
    return -1;
  }
  return stack->arr[stack->top];
}

// Print stack
void print(Stack *stack) {
  if (stack == NULL || stack->arr == NULL) {
    return;
  }
  if (is_empty(stack)) {
    printf("[|\n");
    return;
  }
  printf("[");
  for (int i = 0; i <= stack->top; i++) {
    if (i != stack->top) {
      printf("%d[", stack->arr[i]);
    } else {
      printf("%d|\n", stack->arr[i]);
    }
  }
  return;
}