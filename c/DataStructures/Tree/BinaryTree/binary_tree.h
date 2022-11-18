/**********************************************
 > File Name: binary_tree.h
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 11/16/2022
 > Desc: This is a header file of binary_tree.c
***********************************************/

typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
  struct Node *parent;
  struct Node *next;
} Node;

typedef struct BinaryTree {
  Node *root;
} Tree;

Node *new_node(int);
Tree *init_binary_tree();
void destroy(Tree *);
int insert(Tree *, int);
Node *find_node(Tree *, int);
Node *find_successor(Node *);
void in_order(Tree *);
int delete (Tree *, int);
void __delete_next(Node *);
void __in_order(Node *);
void __free_node(Node *node);
