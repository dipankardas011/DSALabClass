/*WAP Write the following menu driven program for the binary search tree
----------------------------------------
Binary Search Tree Menu
----------------------------------------
0. Quit
1. Create
2. In-Order Traversal
3. Pre-Order Traversal
4. Post-Order traversal
Enter your choice:*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
}Btree;

Btree *createMemory(int key) {
    Btree *t = (Btree*)malloc(sizeof(Btree));
    t->key = key;
    t->left = t->right = NULL;

    return t;
}

Btree *queue[1000]={0};
int front = -1;
int rear = -1;

void push(Btree *k){
    if (front==-1 && rear==-1) {
        front = rear = 0;
        queue[rear]=k;
    } else {
        queue[++rear]=k;
    }
}

Btree *peek() {
    if (front!=-1 && rear!=-1)
        return queue[front];
    return NULL;
}

void pop() {
    if (front == -1 && front == rear)
        return;

    if (front == rear){
        queue[front] = NULL;
        front = rear = -1;
    }
    else {
        queue[front++] = NULL;
    }
}

int isEmpty() {
    if (front== -1 && front==rear)
        return 1;
    return 0;
}

/**
 * @def to insert the elements in level order (left -> right) direction
 * @param root the root of the Binary tree
 * @param key the element to be inserted
 * @return return the root of the modified Binary tree
 */
Btree *insertLeaves(Btree *root, int key) {

    if (!root) {
        return createMemory(key);
    }

    //// Queue datastructure is used ////
    push(root);
    while (!isEmpty()) {
        Btree *parent = peek();
        pop();

        if (parent->left!=NULL) {
            push(parent->left);
        } else {
            parent->left = createMemory(key);
            return root;
        }

        if (parent->right!=NULL) {
            push(parent->right);
        } else {
            parent->right = createMemory(key);
            return root;
        }
    }
    return root;
}

void inorderTraversal(Btree *root) {
    if(root) {
        inorderTraversal(root->left);
        printf("%d ",root->key);
        inorderTraversal(root->right);
    }
}


void preorderTraversal(Btree *root) {
    if(root) {
        printf("%d ",root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Btree *root) {
    if(root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->key);
    }
}

void deleteTree(Btree *root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

void welcomePage() {
    printf("> 0. Quit\n");
    printf("> 1. Create\n");
    printf("> 2. In-Order Traversal\n");
    printf("> 3. Pre-Order Traversal\n");
    printf("> 4. Post-Order traversal\n");
}

/**
 * Example
 *       1
 *     /  \
 *    2    3
 *   / \  / \
 *  4  5 6  7
 * 
 * inorder = 4 2 5 1 6 3 7
 * preorder = 1 2 4 5 3 6 7
 * postorder = 4 5 2 6 7 3 1
 */

int main(int argc, char **argv) {
    Btree *root = NULL; 
    int choice = 0;
    do {
        welcomePage();
        printf("Your choice-> ");
        scanf("%d",&choice);
        int ele = 0;
        switch(choice) {
            case 1:{
                printf("\tEnter the element to be inserted-> ");
                scanf("%d",&ele);
                root = insertLeaves(root, ele);
            }
            break;

            case 2:{
                printf("Inorder traversal: [ ");
                inorderTraversal(root);
                printf("]\n");
            }
            break;

            case 3:{
                printf("Preorder traversal: [ ");
                preorderTraversal(root);
                printf("]\n");
            }
            break;

            case 4:{
                printf("Postorder traversal: [ ");
                postorderTraversal(root);
                printf("]\n");
            }
            break;

        }
    } while(choice!=0);

    deleteTree(root);
    remove(argv[0]);
    return EXIT_SUCCESS;
}