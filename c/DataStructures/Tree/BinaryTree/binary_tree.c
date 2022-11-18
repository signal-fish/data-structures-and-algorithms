/**********************************************
 > File Name: binary_tree.c
 > Author: Signal Yu
 > Mail: signalfish38861721@gmail.com
 > Time: 11/16/2022
 > Desc: Implement unbalanced banary tree
***********************************************/
#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

Node *new_node(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (node == NULL) {
    return NULL;
  }
  node->val = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  node->next = NULL;
  return node;
}

Tree *init_binary_tree() {
  Tree *tree = (Tree *)malloc(sizeof(Tree));
  if (tree == NULL) {
    return NULL;
  }
  tree->root = NULL;
  return tree;
}

void destroy(Tree *tree) {
  if (tree == NULL) {
    return;
  }
  __free_node(tree->root);
  free(tree);
  tree = NULL;
  return;
}

int insert(Tree *tree, int data) {
  if (tree == NULL) {
    return -1;
  }
  Node *n_node = new_node(data);
  if (n_node == NULL) {
    return -1;
  }
  if (tree->root == NULL) {
    tree->root = n_node;
    return 0;
  }
  Node *cur = tree->root;
  while (cur != NULL) {
    if (data > cur->val && cur->right != NULL) {
      cur = cur->right;
    } else if (data > cur->val && cur->right == NULL) {
      cur->right = n_node;
      n_node->parent = cur;
      return 0;
    } else if (data < cur->val && cur->left != NULL) {
      cur = cur->left;
    } else if (data < cur->val && cur->left == NULL) {
      cur->left = n_node;
      n_node->parent = cur;
      return 0;
    } else {
      while (cur->next != NULL) {
        cur = cur->next;
      }
      cur->next = n_node;
      return 0;
    }
  }
}

void __in_order(Node *node) {
  if (node != NULL) {
    __in_order(node->left);
    if (node->next != NULL) {
      Node *temp = node;
      printf("[");
      while (temp != NULL) {
        printf(" %d ", temp->val);
        temp = temp->next;
      }
      printf("]");
    } else {
      printf(" %d ", node->val);
    }
    __in_order(node->right);
  }
}

void in_order(Tree *tree) {
  printf("[");
  __in_order(tree->root);
  printf("]\n");
}

void __delete_next(Node *node) {
  if (node == NULL) {
    return;
  }
  Node *temp = NULL;
  while (node != NULL) {
    temp = node;
    node = node->next;
    free(temp);
    temp = NULL;
  }
  return;
}

Node *find_node(Tree *tree, int data) {
  if (tree == NULL || tree->root == NULL) {
    return NULL;
  }
  Node *cur = tree->root;
  while (cur != NULL) {
    if (data < cur->val) {
      if (cur->left == NULL) {
        return cur; // The node doesn't exist
      }
      cur = cur->left;
    } else if (data > cur->val) {
      if (cur->right == NULL) {
        return cur;
      }
      cur = cur->right;
    } else {
      return cur; // Find the node and return it
    }
  }
}

Node *find_successor(Node *node) {
  if (node == NULL) {
    return NULL;
  }
  if (node->right == NULL) {
    return node;
  }
  Node *cur = node->right;
  while (cur->left != NULL) {
    cur = cur->left;
  }
  return cur;
}

int delete (Tree *tree, int data) {
  if (tree == NULL || tree->root == NULL) {
    return -1;
  }
  Node *temp = find_node(tree, data);
  if (temp->val != data) {
    return -1;
  }
  __delete_next(temp->next);
  // no children
  if (temp->left == NULL && temp->right == NULL) {
    if (temp == tree->root) {
      tree->root = NULL;
    } else if (temp->val > temp->parent->val) {
      temp->parent->right = NULL;
    } else {
      temp->parent->left = NULL;
    }
    free(temp);
    temp = NULL;
    return 0;
  } else if (temp->left != NULL && temp->right != NULL) {
    Node *successor = find_successor(temp);
    // The left tree of temp is made the left tree of the successor
    // handle successor's left sub-tree
    successor->left = temp->left;
    successor->left->parent = successor;
    // handle successor's right sub-tree
    if (successor->parent != temp) {
      if (successor->right != NULL) {
        // If the successor has a right child, the child's grandparent is it's new parent
        successor->right->parent = successor->parent;
        successor->parent->left = successor->right;
      } else {
        successor->parent->left = NULL;
      }
      successor->right = temp->right;
      successor->right->parent = successor;
    }

    // handle successor's parent
    if (temp == tree->root) {
      successor->parent = NULL;
      tree->root = successor;
    } else {
      successor->parent = temp->parent;
      if (temp->val < temp->parent->val) {
        temp->parent->left = successor;
      } else {
        temp->parent->right = successor;
      }
    }
    free(temp);
    temp = NULL;
    return 0;
  } else {
    // temp has a right child
    if (temp->right != NULL) {
      if (temp == tree->root) {
        tree->root = temp->right;
      } else {
        temp->right->parent = temp->parent;
        if (temp->val < temp->parent->val) {
          temp->parent->left = temp->right;
        } else {
          temp->parent->right = temp->right;
        }
      }
    } else { // temp has a left child
      if (temp == tree->root) {
        tree->root = temp->left;
      } else {
        temp->left->parent = temp->parent;
        if (temp->val < temp->parent->val) {
          temp->parent->left = temp->left;
        } else {
          temp->parent->right = temp->left;
        }
      }
    }
    free(temp);
    temp = NULL;
    return 0;
  }
}

void __free_node(Node *node) {
  if (node == NULL) {
    return;
  }
  if (node->left != NULL) {
    __free_node(node->left);
  }
  if (node->right != NULL) {
    __free_node(node->right);
  }
  __delete_next(node->next);
  free(node);
  node = NULL;
  return;
}