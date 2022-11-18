#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

Tree *tree;
Node *node;

void tree_setup(){
}

void tree_teardown() {
}

#suite Tree

#tcase Tree Util

#test test_new_node
    node = new_node(1);
    ck_assert_msg(node != NULL, "test_new_node 1 failed...\n");
    ck_assert_msg(node->val = 1, "test_new_node 2 failed...\n");
    ck_assert_msg(node->left == NULL, "test_new_node 3 failed...\n");
    ck_assert_msg(node->right == NULL, "test_new_node 4 failed...\n");
    ck_assert_msg(node->parent == NULL, "test_new_node 5 failed...\n");
    ck_assert_msg(node->next == NULL, "test_new_node 6 failed...\n");
    free(node);

#test test_init_binary_tree 
    tree = init_binary_tree();
    ck_assert_msg(tree != NULL, "test_init_binary_tree 1 failed...\n");
    ck_assert_msg(tree->root == NULL, "test_init_binary_tree 2 failed...\n");
    destroy(tree);

#test test_insert
    tree = init_binary_tree();
    int arr[42] = {20, 10, 30, 5, 15, 25, 35, 3, 9, 12, 17, 22, 28, 33, 38, 2, 4, 7, 11, 13, 16, 19, 21, 24, 27, 29, 32, 34, 37, 39, 1, 6, 8, 14, 18, 23, 26, 31, 36, 40, 20, 30};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        ck_assert_msg(insert(tree, arr[i]) == 0, "test_insert failed...\n");
    }
    ck_assert_msg(tree->root->left->left->left->val == 3, "test_insert 2 failed...\n");
    destroy(tree);
    
#test test_in_order
    tree = init_binary_tree();
    int arr[50] = {20, 10, 30, 5, 15, 25, 35, 3, 9, 12, 17, 22, 28, 33, 38, 2, 4, 7, 11, 13, 16, 19, 21, 24, 27, 29, 32, 34, 37, 39, 1, 6, 8, 14, 18, 23, 26, 31, 36, 40, 20, 30, 20, 10, 5, 5, 5, 5, 28, 1};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        ck_assert_msg(insert(tree, arr[i]) == 0, "test_insert failed...\n");
    }
    in_order(tree);
    destroy(tree);

#test test_find_node
    tree = init_binary_tree();
    ck_assert_msg(find_node(tree, 1) == NULL, "test_find_node 1 failed...\n");
    insert(tree, 2);
    insert(tree, 1);
    insert(tree, 3);
    ck_assert_msg(find_node(tree, 2) == tree->root, "test_find_node 2 filed...\n");
    ck_assert_msg(find_node(tree, 1) == tree->root->left, "test_find_node 3 filed...\n");
    ck_assert_msg(find_node(tree, 3) == tree->root->right, "test_find_node 4 filed...\n");
    destroy(tree);

#test test_find_successor
    tree = init_binary_tree();
    ck_assert_msg(find_successor(tree->root) == NULL, "test_find_successor 1 failed...\n");
    insert(tree, 10);
    insert(tree, 15);
    insert(tree, 5);
    insert(tree, 13);
    ck_assert_msg(find_successor(tree->root) == tree->root->right->left, "test_find_successor 2 failed...\n");
    ck_assert_msg(find_successor(tree->root->left) == tree->root->left, "test_find_successor 3 failed...\n");
    ck_assert_msg(find_successor(tree->root->right) == tree->root->right, "test_find_successor 4 failed...\n");
    destroy(tree);

#test test_delete
    tree = init_binary_tree();
    ck_assert_msg(delete(tree, 1) == -1, "test_delete 1 failed...\n");
    int size = 10000;
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] =  rand() % 1000 + 1;
    }
    for (int i = 0; i < size; i++) {
        insert(tree, arr[i]);
    }
    for (int i = 0; i < size; i++) {
        delete(tree, arr[i]);
    }
    destroy(tree);

#test test_destroy
    tree = init_binary_tree();
    int arr[50] = {20, 10, 30, 5, 15, 25, 35, 3, 9, 12, 17, 22, 28, 33, 38, 2, 4, 7, 11, 13, 16, 19, 21, 24, 27, 29, 32, 34, 37, 39, 1, 6, 8, 14, 18, 23, 26, 31, 36, 40, 20, 30, 20, 1, 1, 5, 9, 22, 34, 37};
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
        insert(tree, arr[i]);
    }
   destroy(tree);



#main-pre
    tcase_add_checked_fixture(tc1_1, tree_setup, tree_teardown);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_set_log(sr, "tree_log.txt");

#main-post
    if (nf != 0) {
        printf("%d tests failed.", nf);
    }
    return 0;