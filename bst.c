#include <stdio.h>
#include <stdlib.h>
#include "bst.h"


bst_t *create_bst_t() {
	bst_t *tree = malloc(sizeof(bst_t));
	tree->root = tree->last_found = NULL;
	return tree;
}

bst_node *create_node(int data) {
	bst_node *new_node = malloc(sizeof(bst_node));
	new_node->data = data;
	new_node->parent = new_node->left = new_node->right = NULL;
	return new_node;
}

void destroy_bst_node(bst_node *b) {
	free(b);
}
void destroy_bst(bst_t *tree) {
	free(tree);
}

void bst_insert(bst_t *tree, int data) {
    // Iterative solution, CLRS
    bst_node *y = NULL; // will be z's parent 
    bst_node *x = tree->root;
    while (x != NULL) {
        y = x;
        if (data < (x->data)) x = x->left;
        else x = x->right;
    }
    bst_node *z = create_node(data);

    if (y == NULL) {
        tree->root = z;
    }
    else if ((z->data) < (y->data)) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    z->parent = y;
}

void bst_print_in_order(bst_t *tree) {
    if (tree->root != NULL) {
        bst_t left = {tree->root->left};
        bst_t *l = &left;
        bst_print_in_order(l);
        printf("%d->", tree->root->data);
        bst_t right = {tree->root->right};
        bst_t *r = &right;
        bst_print_in_order(r);
    }
}

int bst_find(bst_t *tree, int data, int *found) {
	bst_node *current = tree->root;
	while (current != NULL && data != current->data) {
		if (data < current->data){
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	if (current == NULL) return -1;
	else {
		tree->last_found = current;
		return current->data;
	}
}

void transplant(bst_t *T, bst_node *u, bst_node *v) {
	if (u->parent == NULL)
		T->root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
}

void bst_delete(bst_t *tree, int data) {
	int *found = 0;
	bst_find(tree, data, found);
	if (tree->root == NULL) return; // test for empty BST
	if (tree->last_found->data != data)
		return; // test for data not in BST 
	bst_node *z = tree->last_found;

	if (z->left == NULL)
		transplant(tree, z, z->right);
	else if (z->right == NULL)
		transplant(tree, z, z->left);
	else {
		bst_node *y = z->right;
		while (y->left != NULL) {
			y = y->left;
		}
		if (y->parent != z) {
			transplant(tree, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(tree, z, y);
		y->left = z->left;
		y->left->parent = y;
	}

	destroy_bst_node(z); // Free the allocated memory for node
}