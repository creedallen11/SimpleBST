#ifndef BST_H
#define BST_H
#include <stdio.h>

typedef struct bst_node {
    int data;
    struct bst_node *parent;
    struct bst_node *left;
    struct bst_node *right;
} bst_node;

typedef struct bst_t {
    bst_node *root;
    bst_node *last_found;
} bst_t;


// Functions
bst_t *create_bst_t();
bst_node *create_node(int data);
void destroy_bst(bst_t *tree);
void destroy_bst_node(bst_node *b);
void bst_print_in_order(bst_t *tree);
void bst_insert(bst_t *tree, int data);
int bst_find(bst_t *tree, int data, int *found);
void transplant(bst_t *T, bst_node *u, bst_node *v);
void bst_delete(bst_t *tree, int data);


#endif