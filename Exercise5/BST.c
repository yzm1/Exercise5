#include "BST.h"
#include <stdlib.h>
#define CheckNULL(node) if((temp) == NULL){ printf("Memmory allocation failed"); exit(1); }

void initBST(BST* bst) {
	bst->root = NULL;
}

void insertBST(BST* bst, int value) {
	if (bst->root == NULL)
		bst->root = createNode(value);
	else
		insert(bst->root, createNode(value));
}

TreeNode* createNode(int value) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	CheckNULL(temp);
	temp->left = NULL;
	temp->right = NULL;
	temp->element = value;
	return temp;
}

void insert(TreeNode* root, TreeNode* newNode)
{
	if (newNode->element <= root->element) //left subtree (<=)
		if (root->left == NULL)
			root->left = newNode;
		else
			insert(root->left, newNode);
	if (newNode->element > root->element) //right subtree (>)
		if (root->right == NULL)
			root->right = newNode;
		else
			insert(root->right, newNode);
}