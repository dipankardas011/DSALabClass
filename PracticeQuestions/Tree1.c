// to implement the inorder, preorder, postorder (iterative method)
// height, depth
// Write a function to display all the paths from root to leaf nodes in a binary tree.
// Write a C function swapTree that takes a binary tree root node and swaps the
// left and right children of every node.
#include <stdio.h>
#include <stdlib.h>
#include "../CustomDS/QueueI.h"


typedef struct n{
	int data;
	struct n*left,*right;
}tree;


tree* allocateMemory(int k){
	tree* t = (tree*)malloc(sizeof(tree));
	t->data = k;
	t->left = t->right = NULL;
	return t;
}

void inorderRec(tree* root){
  if(root){
    inorderRec(root->left);
    printf("%d ", root->data);
    inorderRec(root->right);
  }
}

void preorderRec(tree* root){
  if(root){
    printf("%d ", root->data);
    preorderRec(root->left);
    preorderRec(root->right);
  }
}

void postorderRec(tree* root){
  if(root){
    postorderRec(root->left);
    postorderRec(root->right);
    printf("%d ", root->data);
  }
}

void postorderIter(tree* root){}
void inorderIter(tree* root){}
void preorderIter(tree* root){}


int main(int argc, char **argv) {
  tree* root = 0;
  /**
   *    1
   *   / \
   *  2   3
   * / \  /
   * 4 5  6
   *   \
   *   7
   */
	root = allocateMemory(1);
	root->left = allocateMemory(2);
	root->right = allocateMemory(3);
	root->left->right = allocateMemory(5);
	root->left->left = allocateMemory(4);
	root->left->right->right = allocateMemory(7);
	root->right->left= allocateMemory(6);
  
  remove(argv[0]);
  return EXIT_SUCCESS;
}