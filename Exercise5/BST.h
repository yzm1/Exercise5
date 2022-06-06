#ifndef _BST_ADT_H
#define _BST_ADT_H

typedef struct TreeNode TreeNode;

struct TreeNode
{
    TreeNode* left;
    TreeNode* right;
    int element;
};

typedef struct BST
{
    TreeNode* root;
}BST;


void initBST(BST* bst);
void insertBST(BST* bst, int value);
TreeNode* createNode(int value);
void insert(TreeNode* root, TreeNode* newNode);
void printTreeInorder(BST* bst);
void inorder(TreeNode* root);
void destroyBST(BST* bst);
void destroy(TreeNode* root);
int findIndexNFromLast(BST* bst, int N);
int fintIndex(TreeNode*, int N, int *count, int *value);

#endif // !_BST_ADT_H