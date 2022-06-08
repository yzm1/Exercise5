#include <stdio.h>
#include <stdlib.h>
#include "BST.h"
#include "TreePrintLibrary.h"

void main() {
	BST* bst = (BST*)malloc(sizeof(BST));
	
	initBST(bst);
	insertBST(bst, 5);
	insertBST(bst, 10);
	insertBST(bst, 9);
	insertBST(bst, 7);
	insertBST(bst, 8);
	insertBST(bst, 5);
	insertBST(bst, 12);
	insertBST(bst, 13);
	insertBST(bst, 14);
	insertBST(bst, 4);
	insertBST(bst, 3);
	//insertBST(bst, 2);

	printf("\n");

	//print_ascii_tree(bst->root);
	
	printf("\n");
	
	printTreeInorder(bst);

	printf("\n");

	int N = 1;
	int value = findIndexNFromLast(bst, N);
	printf("N from last (%d) => %d\n", N, value);

	N = 3;
	value = findIndexNFromLast(bst, N);
	printf("N from last (%d) => %d\n", N, value);

	N = 6;
	value = findIndexNFromLast(bst, N);
	printf("N from last (%d) => %d\n", N, value);

	int sameHeight = sameHeightLeaves(bst);
	printf("%s", sameHeight ? "same height" : "not same height");
	printf("\n");

	destroyBST(bst);
}
