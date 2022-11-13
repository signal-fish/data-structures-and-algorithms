/**********************************************
 > File Name: doubly_linked_list.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/22/2022
 > Desc: Implement doubly linked list with
   struct
***********************************************/

#include "doubly_linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node *new_node(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    return NULL;
  }
  node->prev = NULL;
  node->next = NULL;
  node->val = data;
  return node;
}

List *new_doubly_linked_list() {
  List *list = (List *)malloc(sizeof(List));
  if (list == NULL) {
    return NULL;
  }
  list->head = NULL;
  list->length = 0;

  return list;
}

int append(List *list, int data) {
  Node *n_node = new_node(data);
  if (n_node == NULL) {
    return -1;
  }
  if (is_empty(list)) {
    list->head = n_node;
    list->length++;
    return 0;
  }
  Node *cur = list->head;
  while (cur->next != NULL) {
    cur = cur->next;
  }
  cur->next = n_node;
  n_node->prev = cur;
  list->length++;
  return 0;
}

// print doubly linked list
void print(List *list) {
  if (is_empty(list)) {
    printf("<head>->NULL\n");
    return;
  }
  printf("NULL<-");
  Node *cur = list->head;
  while (cur->next != NULL) {
    printf("[%d]⇄", cur->val);
    cur = cur->next;
  }
  printf("[%d]->NULL\n", cur->val);
  return;
}

int prepend(List *list, int data) {
  Node *n_node = new_node(data);
  if (n_node == NULL) {
    return -1;
  }
  if (is_empty(list)) {
    list->head = n_node;
    list->length++;
    return 0;
  }
  Node *cur = list->head;
  cur->prev = n_node;
  n_node->next = cur;
  list->head = n_node;
  list->length++;
  return 0;
}

int insert(List *list, int idx, int data) {
  if (idx < 0 || idx >= list->length) {
    return -1;
  }
  Node *n_node = new_node(data);
  if (n_node == NULL) {
    return -1;
  }
  if (idx == 0) {
    Node *cur = list->head;
    cur->prev = n_node;
    n_node->next = cur;
    list->head = n_node;
    list->length++;
    return 0;
  }
  Node *cur = list->head;
  for (int i = 0; i < idx; i++) {
    cur = cur->next;
  }
  Node *prev = cur->prev;
  prev->next = n_node;
  n_node->prev = prev;
  n_node->next = cur;
  cur->prev = n_node;
  list->length++;
  return 0;
}

int delete_note(List *list, int idx) {
  if (idx < 0 || idx >= len(list) || is_empty(list)) {
    return -1;
  }
  Node *cur = list->head;
  if (idx == 0) {
    list->head = cur->next;
    free(cur);
    cur = NULL;
    list->length--;
    return 0;
  }
  for (int i = 0; i < idx; i++) {
    cur = cur->next;
  }
  if (idx == len(list) - 1) {
    cur->prev->next = NULL;
    free(cur);
    cur = NULL;
    list->length--;
    return 0;
  }
  cur->prev->next = cur->next;
  cur->next->prev = cur->prev;
  free(cur);
  cur = NULL;
  list->length--;
  return 0;
}

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

int clear(List *list) {
  if (is_empty(list)) {
    return 0;
  }
  Node *cur = list->head;
  while (cur->next != NULL) {
    Node *tmp = cur;
    cur = cur->next;
    free(tmp);
  }
  free(cur);
  cur = NULL;
  list->head = NULL;
  list->length = 0;
  return 0;
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
