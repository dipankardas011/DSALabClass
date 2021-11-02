/*•	WAP Write the following menu driven program for the binary search tree
----------------------------------------
Binary Search Tree Menu
----------------------------------------
0. Quit
1. Create
2. In-Order Traversal
3. Pre-Order Traversal
4. Post-Order traversal
5. Search
6. Find Smallest Element
7. Find Largest Element
8. Deletion node of Tree
----------------------------------------
Enter your choice:
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left, *right;
} BST;

BST *allocateMemory(int key) {
    BST *t = (BST*)malloc(sizeof(BST));
    t->key = key;
    t->left=t->right=NULL;
    return t;
}

// void insertNode(BST **root, int key) {
//     if ((*root)) {
//         if ((*root)->key < key) {
//             if ((*root)->right) {
//                 insertNode((*root)->right, key);
//             } else {
//                 (*root)->right = allocateMemory(key);
//                 return ;
//             }
//         }
//         else if ((*root)->key > key) {
//             if ((*root)->left) {
//                 insertNode((*root)->left, key);
//             } else {
//                 (*root)->left = allocateMemory(key);
//                 return ;
//             }
//         }
//         else {
//             return;
//         }
//     } else {
//         // means no entry for root itself as in other cases it will not reach here
//         *root = allocateMemory(key);
//     }
// }

void insertNode(BST **root, int key) {
    if (!(*root)) {
        *root = allocateMemory(key);
    }

    if(key > (*root)->key) 
        if ((*root)->right)
            insertNode(&(*root)->right, key);
        else
            (*root)->right = allocateMemory(key);
    
    if(key < (*root)->key)
        if ((*root)->left)
            insertNode(&(*root)->left, key);
        else
            (*root)->left = allocateMemory(key);
}

void deleteBST(BST *root) {
    if (root) {
        deleteBST(root->left);
        deleteBST(root->right);
        free(root);
    }
}

void welcomePage() {
    printf("# Menu\n");
    printf("> 0. Quit\n");
    printf("> 1. Create\n");
    printf("> 2. In-Order Traversal\n");
    printf("> 3. Pre-Order Traversal\n");
    printf("> 4. Post-Order traversal\n");
    printf("> 5. Search\n");
    printf("> 6. Find Smallest Element\n");
    printf("> 7. Find Largest Element\n");
    printf("> 8. Deletion node of Tree\n");
}

void inorderTraversal(BST *root) {
    if(root) {
        inorderTraversal(root->left);
        printf("%d ",root->key);
        inorderTraversal(root->right);
    }
}


void preorderTraversal(BST *root) {
    if(root) {
        printf("%d ",root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(BST *root) {
    if(root) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ",root->key);
    }
}

int main(int argc, char **argv) {
    BST *root = 0;
    int ch = 0;
    do {
        welcomePage();
        printf("Enter choice[0/9] -> ");
        scanf("%d",&ch);
        int kk=0;
        switch(ch) {
            case 1:
            printf("\tEnter the key to insert: ");
            scanf("%d",&kk);
            insertNode(&root, kk);
            break;

            case 2:
            printf("=====================\n");
            printf("[");
            inorderTraversal(root);
            printf("]\n");
            printf("=====================\n");
            break;

            case 3:
            printf("=====================\n");
            printf("[");
            preorderTraversal(root);
            printf("]\n");
            printf("=====================\n");
            break;

            case 4:
            printf("=====================\n");
            printf("[");
            postorderTraversal(root);
            printf("]\n");
            printf("=====================\n");
            break;

            case 5:
            break;

            case 6:
            break;

            case 7:
            break;

            case 8:
            break;
        }
    }while (ch);


    deleteBST(root);
    remove(argv[0]);
    return EXIT_SUCCESS;
}