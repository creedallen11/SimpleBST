#include <bst.h>

int main() {

	bst_t *tree = create_bst_t();
	int entries[] = {8, 3, 10, 1, 6, 4, 7, 14, 13};

	int size = 9;
	for (int i = 0; i < size; i++) {
		printf("Inserting...%d\n", entries[i]);
		bst_insert(tree, entries[i]);
	}

	bst_print_in_order(tree);

	printf("\nShow find results on 1-20...should match above tree output.\n");

	int *found = 0;
	for (int j = 1; j <= 20; j++) {
		if (bst_find(tree, j, found) == j) {
			printf("Found %d in BST\n", j);
		}
		else printf("Did not find %d.\n", j);
	}

	printf("Will show delete edge cases maintain correct tree.\n");
	printf("CURRENT TREE: ");
	bst_print_in_order(tree);
	printf("\n");

	printf("Remove node %d with no children...", 4);
	bst_delete(tree, 4);
	bst_print_in_order(tree);
	printf("\n");
	printf("Remove node %d with left child...", 14);
	bst_delete(tree, 14);
	bst_print_in_order(tree);
	printf("\n");
	printf("Remove node %d with right child...", 6);
	bst_delete(tree, 6);
	bst_print_in_order(tree);
	printf("\n");
	printf("Remove node %d with two children...", 3);
	bst_delete(tree, 3);
	bst_print_in_order(tree);
	printf("\n");
	printf("Remove root node %d", 8);
	bst_delete(tree, 8);
	printf("CURRENT TREE: ");
	bst_print_in_order(tree);
	printf("\n");

	return (0);
}