// to implement the inorder, preorder, postorder (iterative method)
// height, depth
// Write a function to display all the paths from root to leaf nodes in a binary tree.
// Write a C function swapTree that takes a binary tree root node and swaps the
// left and right children of every node.
#include <stdio.h>
#include <stdlib.h>
#include "../CustomDS/Stack.h"

typedef struct n
{
    int data;
    struct n *left, *right;
} tree;

tree *allocateMemory(int k)
{
    tree *t = (tree *)malloc(sizeof(tree));
    t->data = k;
    t->left = t->right = NULL;
    return t;
}

void inorderRec(tree *root)
{
    if (root){
        inorderRec(root->left);
        printf("%d ", root->data);
        inorderRec(root->right);
    }
}

void preorderRec(tree *root)
{
    if (root){
        printf("%d ", root->data);
        preorderRec(root->left);
        preorderRec(root->right);
    }
}

void postorderRec(tree *root)
{
    if (root){
        postorderRec(root->left);
        postorderRec(root->right);
        printf("%d ", root->data);
    }
}

/**
 * @def postorderIter Push directly root node two times while traversing to the left. While poping if you find stack top() is same as root then go for root->right else print root.
 * @param root root of the tree
 */
void postorderIter(tree *root)
{
    // left-right-root
    Stack *stk = NULL;
    while (1)
    {
        while(root) {
            push(&stk, root);
            push(&stk, root);
            root = root->left;
        }
         
        // Check for empty stack
        if(isEmpty(&stk))
            break;
        root = (tree *)peek(&stk);
        pop(&stk);

        // when there is duplicate of root.data means that right must be traversed
        // if right has been traversed then the same / duplicat is removed before check 
        if(!isEmpty(&stk) && (tree *)peek(&stk) == root) 
            root = root->right;

        else {
            printf("%d ",root->data); 
            root = NULL;
        }
    }
    printf("\n\n");
}

void inorderIter(tree *root)
{
    // left - root - right
    // always go towards the left
    tree *iter = root;
    Stack* stk = NULL;
    while(iter || !isEmpty(&stk)){
        while(iter){
            push(&stk, iter);
            iter = iter->left;
        }

        iter = (tree *)peek(&stk);
        pop(&stk);
        printf("%d ", iter->data);
        iter = iter->right;
    }
    printf("\n\n");
}

void preorderIter(tree *root)
{
    // root-left-right
    Stack *stk = NULL;
    push(&stk, root);
    while(!isEmpty(&stk)){
        tree *ii = (tree*)peek(&stk);
        printf("%d ", ii->data);
        pop(&stk);

        if(ii->right)
            push(&stk, ii->right);
        if(ii->left)
            push(&stk, ii->left);
    }
    printf("\n\n");
}


void pathPrinter(tree *root, int* path, int index)
{
    if (root){
        // printf("%d -> ", root->data);
        path[index] = root->data;
        index++;
        if (root->left == NULL && root->right == NULL){
            for (int i = 0; i < index;i++){
                printf("%d -> ", path[i]);
            }
            printf("X\n");
        }
        else{
            pathPrinter(root->left, path, index);
            pathPrinter(root->right, path, index);
        }
    }
}

tree* swapTreeNodes(tree* root){
    if(root){
        tree* t = root->left;
        root->left = root->right;
        root->right = t;
        root->left = swapTreeNodes(root->left);
        root->right = swapTreeNodes(root->right);
        return root;
    }
    else
    {
        return NULL;
    }
}

int main(int argc, char **argv)
{
    tree *root = 0;
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
    root->right->left = allocateMemory(6);

    printf("~~~ inorder method ~~~\n");
    inorderRec(root);
    printf("\n");
    inorderIter(root);

    printf("~~~ preorder method ~~~\n");
    preorderRec(root);
    printf("\n");
    preorderIter(root);

    printf("~~~ postorder method ~~~\n");
    postorderRec(root);
    printf("\n");
    postorderIter(root);

    int path[1000]={0};

    pathPrinter(root,path,0);

    root = swapTreeNodes(root);
    /**
     *    1
     *   / \
     *  3   2
     *  \  / \
     *  6  5 4
     *    /
     *   7
     */

    inorderRec(root);
    printf("\n");

    remove(argv[0]);
    return EXIT_SUCCESS;
}