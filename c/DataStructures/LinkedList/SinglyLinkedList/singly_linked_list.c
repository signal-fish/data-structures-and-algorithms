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
int get_item(List *list, int idx) {
  if (idx < 0 || idx >= len(list)) {
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
  if (idx < 0 || idx >= len(list)) {
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
  if (idx < 0 || idx >= len(list)) {
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
    return 0;
  }
  Node *cur = list->head;
  while (cur->next != NULL) {
    Node *tmp = cur;
    cur = cur->next;
    free(tmp);
    tmp = NULL;
  }
  free(cur);
  cur = NULL;
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
  if (len(list) <= 1) {
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

int destroy(List *list) {
  if (list == NULL) {
    return -1;
  }
  if (is_empty(list)) {
    free(list);
    return 0;
  }
  Node *cur = list->head;
  while (cur->next != NULL) {
    Node *tmp = cur;
    cur = cur->next;
    free(tmp);
    tmp = NULL;
  }
  free(cur);
  cur = NULL;
  list->head = NULL;
  list->length = 0;
  free(list);
  return 0;
}
