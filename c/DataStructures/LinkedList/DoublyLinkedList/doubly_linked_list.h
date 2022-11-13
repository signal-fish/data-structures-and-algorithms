/**********************************************
 > File Name: doubly_linked_list.h
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 10/22/2022
 > Desc: This is a header file of
   doubly_linked_list.c
***********************************************/

typedef struct node {
  int val;
  struct node *prev;
  struct node *next;
} Node;

typedef struct doubly_linked_list {
  int length;
  Node *head;
} List;

#define is_empty(list) (list->length == 0)
#define len(list) (list->length)

Node *new_node(int);
List *new_doubly_linked_list();
int destroy(List *);
int append(List *, int);
void print(List *);
int prepend(List *, int);
int insert(List *, int, int);
int delete_note(List *, int);
int count(List *, int);
void asc_sort(List *);
int get_item(List *, int);
int update(List *, int, int);
int clear(List *);