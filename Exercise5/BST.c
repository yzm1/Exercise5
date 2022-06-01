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
void printTreeInorder(BST* bst) {
	if (bst->root != NULL) {

		inorder(bst->root);
	}
	else {
		printf("Empty tree");
	}
	printf("\n");
}
void inorder(TreeNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d,", root->element);
		inorder(root->right);
	}
}

void destroyBST(BST* bst) {
	if (bst->root != NULL) {
		destroy(bst->root);
	}
}

void destroy(TreeNode* root) {
	if (root != NULL) {
		destroy(root->right);
		free(root->right);
		destroy(root->left);
		free(root->left);
	}
}
int findIndexNFromLast(BST* bst, int N) {
	if (bst->root != NULL) {
		int* count = 0;
		return findIndex(bst->root, N, count);
	}
}

int findIndex(TreeNode* root, int N, int* count) {
	
	if(*count > 0 && *count != N)
		*count++;
	else if (*count == N) { //
		return root->element;
	}
	else if(root->left == NULL && root->right == NULL && count == 0)
		return ++(*count);
	else if (root->right != NULL) //prefer right
		return findIndex(root->right, N, count);
	else if (root->left != NULL)
		return findIndex(root->left, N, count);//settle for left
}


int findIndex2(TreeNode* root, int N, int* count) {
	int value = 0;
	if (count == 0) {
		if (root->left == NULL && root->right == NULL)
			value = ++(*count);
		else if (root->right != NULL) //prefer right
			value = findIndex(root->right, N, count);
		else if (root->left != NULL)
			value = findIndex(root->left, N, count);//settle for left
	}
	else if (count < N) {
		++(*count);
		if (root->right != NULL) //prefer right
			value = findIndex(root->right, N, count);
		else if (root->left != NULL)
			value = findIndex(root->left, N, count);//settle for left
	}
	else if (count == N) {
		++(*count);
		value = root->element;
	}
	return value;
}

