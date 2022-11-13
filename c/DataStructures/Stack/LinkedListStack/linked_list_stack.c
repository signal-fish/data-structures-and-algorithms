/**********************************************
 > File Name: linked_list_stack.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/17/2022
 > Desc: Implement stack with linked_list
***********************************************/
#include "linked_list_stack.h"
#include <stdio.h>
#include <stdlib.h>

Node *new_node(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    return NULL;
  }
  node->val = data;
  node->next = NULL;
  return node;
}

Stack *init_stack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (stack == NULL) {
    return NULL;
  }
  stack->topNode = NULL;
  stack->length = 0;
  return stack;
}

void destroy(Stack *stack) {
  if (stack == NULL) {
    return;
  }
  if (is_empty(stack)) {
    free(stack);
    stack = NULL;
    return;
  }
  Node *cur = stack->topNode;
  while (cur->next != NULL) {
    Node *temp = cur;
    cur = cur->next;
    free(temp);
    temp = NULL;
  }
  free(cur);
  cur = NULL;
  stack->length = 0;
  free(stack);
  stack = NULL;
  return;
}

int push(Stack *stack, int data) {
  Node *n_node = new_node(data);
  if (n_node == NULL) {
    return -1;
  }
  Node *temp = stack->topNode;
  stack->topNode = n_node;
  n_node->next = temp;
  stack->length++;
  return 0;
}

int pop(Stack *stack) {
  if (is_empty(stack)) {
    return -1;
  }
  int res = stack->topNode->val;
  Node *temp = stack->topNode;
  stack->topNode = stack->topNode->next;
  free(temp);
  temp = NULL;
  stack->length--;
  return res;
}

int get_top(Stack *stack) {
  return is_empty(stack) ? -1 : stack->topNode->val;
}

void print(Stack *stack) {
  printf("TOP->");
  if (is_empty(stack)) {
    printf("NULL]\n");
    return;
  }
  Node *cur = stack->topNode;
  while (cur->next != NULL) {
    printf("%d->", cur->val);
    cur = cur->next;
  }
  printf("%d->NULL]\n", cur->val);
  return;
}