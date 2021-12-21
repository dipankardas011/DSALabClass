#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
typedef struct n{
	int key;
	struct n *left, *right;
} BSTNode;

bool isBST(BSTNode* root, int minRange, int maxRange)
{
	if(!root)
		return true;
	
	if(root->key < minRange || root->key>maxRange)
		return false;

	return isBST(root->left, minRange, root->key) && isBST(root->right, root->key, maxRange);
}

BSTNode* createNode(int d){
	BSTNode *t = (BSTNode *)malloc(sizeof(BSTNode));
	t->key = d;
	t->left = t->right = NULL;
	return t;
}

BSTNode* insertion(BSTNode* root, int ikey){
	if(!root)
		return createNode(ikey);
	
	if(root->key > ikey)
		root->left = insertion(root->left, ikey);
	if(root->key < ikey)
		root->right = insertion(root->right, ikey);
	return root;
}

void inorder(BSTNode* r){
	if(r){
		inorder(r->left);
		printf("%d ", r->key);
		inorder(r->right);
	}
}

int main(int argc, char const *argv[])
{
	BSTNode *root = NULL;

	int arr[] = {2, 5, 6, 8, 1};
	int i = 0;
	while(i<(sizeof(arr)/sizeof(int))){
		root = insertion(root, arr[i]);
		i++;
	}
	inorder(root);
	printf("\n");

	isBST(root, INT_MIN, INT_MAX) ? printf("BST!\n") : printf("Tree!\n");
	remove(argv[0]);
	return 0;
}
