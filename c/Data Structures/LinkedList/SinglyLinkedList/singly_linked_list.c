/**********************************************
 > File Name: singly_linked_list.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/18/2022
 > Desc: Implement singly linked list with
   struct
***********************************************/

#include "singly_linked_list.h"

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

List *new_singly_linked_list() {
  List *list = (List *)malloc(sizeof(List));
  if (list == NULL) {
    return NULL;
  }
  list->head = NULL;
  list->length = 0;
  return list;
}

// Adds an element at the end of the linked list
int append(List *list, int data) {
  Node *n_node = new_node(data);
  if (n_node == NULL) {
    return -1;
  }
  if (len(list) == 0) {
    list->head = n_node;
    list->length++;
    return 0;
  }
  Node *cur = list->head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = n_node;
  list->length++;
  return 0;
}

// Get the element of the ith Node
int get_elem(List *list, int idx) {
  if (idx < 0 || idx > len(list) - 1) {
    return -1;
  }
  Node *cur = list->head;
  for (int i = 0; i < idx; i++) {
    cur = cur->next;
  }
  return cur->val;
}

// Insert a node before the first element of the linked list
int prepend(List *list, int data) {
  Node *n_node = new_node(data);
  n_node->next = list->head;
  list->head = n_node;
  list->length++;
  return 0;
}

// Insert an element before the ith node
int insert(List *list, int idx, int data) {
  if (idx < 0 || idx >= len(list)) {
    return -1;
  }
  if (len(list) <= 1 || idx == 0) {
    prepend(list, data);
    return 0;
  }
  Node *n_node = new_node(data);
  Node *cur = list->head;
  for (int i = 1; i < idx; i++) {
    cur = cur->next;
  }
  n_node->next = cur->next;
  cur->next = n_node;
  list->length++;
  return 0;
}

// Print a linked list
void print(List *list) {
  printf("<head>->");
  if (is_empty(list)) {
    printf("<NULL>\n");
    return;
  }
  Node *cur = list->head;
  while (cur != NULL) {
    printf("[%d]->", cur->val);
    cur = cur->next;
  }
  printf("<NULL>\n");
  return;
}

// Update the node lement of the linked list at the specified position
int update(List *list, int idx, int data) {
  if (idx < 0 || idx > len(list) - 1 || is_empty(list)) {
    return -1;
  }
  Node *cur = list->head;
  for (int i = 0; i < idx; i++) {
    cur = cur->next;
  }
  cur->val = data;
  return 0;
}

// Delete a node at the specified position
int delete_node(List *list, int idx) {
  if (idx < 0 || idx > len(list) - 1 || is_empty(list)) {
    return -1;
  }
  Node *prev = list->head;
  for (int i = 0; i < idx - 1; i++) {
    prev = prev->next;
  }
  Node *cur = prev->next;
  prev->next = cur->next;
  free(cur);
  list->length--;
  return 0;
}

// Clear all nodes of the linked list
int clear(List *list) {
  if (is_empty(list)) {
    return -1;
  }
  Node *cur = list->head;
  Node *next;
  while (cur != NULL) {
    next = cur->next;
    free(cur);
    cur = next;
  }
  list->head = NULL;
  list->length = 0;
  return 0;
}

// Find the number of specified element in the linked list
int count(List *list, int data) {
  int count = 0;
  if (is_empty(list)) {
    return count;
  }
  Node *cur = list->head;
  for (int i = 0; i < len(list); i++) {
    if (cur->val == data) {
      count++;
    }
    cur = cur->next;
  }
  return count;
}

// Sort the linked list in ascending order
void asc_sort(List *list) {
  if (len(list) < 2) {
    return;
  }
  Node *i_node = list->head;
  while (i_node->next != NULL) {
    Node *min_node = i_node;
    Node *j_node = i_node->next;
    while (j_node != NULL) {
      if (min_node->val > j_node->val) {
        min_node = j_node;
      }
      j_node = j_node->next;
    }
    if (i_node != min_node) {
      int temp = i_node->val;
      i_node->val = min_node->val;
      min_node->val = temp;
    }
    i_node = i_node->next;
  }
}

int main() {
  List *list = new_singly_linked_list();
  printf("list = %p\n", list);
  printf("list->head = %p\n", list->head);
  print(list);

  append(list, 2);
  append(list, 1);
  print(list);

  prepend(list, 0);
  print(list);

  insert(list, 2, 666);
  insert(list, 999, 666);
  insert(list, -1, 666);
  print(list);

  printf("get_elem(list, 2) = %d\n", get_elem(list, 2));
  update(list, 2, 999);
  update(list, 999, 0);
  update(list, -1, 0);
  print(list);
  printf("get_elem(list, 2) = %d\n", get_elem(list, 2));

  delete_node(list, 2);
  delete_node(list, 999);
  delete_node(list, -1);
  print(list);

  prepend(list, 9);
  prepend(list, 9);
  prepend(list, 9);
  print(list);
  printf("no. of 9 = %d\n", count(list, 9));
  printf("no. of 0 = %d\n", count(list, 0));
  printf("no. of -1 = %d\n", count(list, -1));

  asc_sort(list);
  print(list);

  clear(list);
  print(list);
  printf("list: %p\n", list);
  printf("list->head: %p\n", list->head);

  for (int n = 0; n < 1000; n++) {
    append(list, n);
  }
  // printf("list->head: %p\n", list);
  // printf("list->head: %p\n", list->head);
  // int i = 10;
  // while (i > 0) {
  //   prepend(list, i);
  //   i--;
  // }
  print(list);
  printf("%d\n", len(list));
  asc_sort(list);
  print(list);
  // printf("%d\n", len(list));
  print(list);
  clear(list);
  free(list);
  return 0;
}