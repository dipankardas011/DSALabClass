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
/**
 * @def right most node of left subtree
 * it requires the root->left to be passed to get the result
 * @return right most node of left subtree
 */
BST *inorderSuccessor(BST *subroot) {
    while (subroot->right) {
        subroot = subroot->right;
    }
    return subroot;
}

/**
 * @def left most node of right subtree
 * it requires the root->right to be passed to get the result
 * @return left most node of right subtree
 */
BST *inorderPredessor(BST *subroot) {
    while (subroot->left) {
        subroot = subroot->left;
    }
    return subroot;
}

/**
 * @def return the minimum key value from left subtree of the tree
 */

BST *leftMostNode(BST *root) {
    while (root->left)
        root = root->left;

    return root;
}

/**
 * @def return the maximum key value from right subtree of the tree
 */

BST *rightMostNode(BST *root) {
    while (root->right)
        root = root->right;

    return root;
}

BST *searchKey(BST *root, int searchkey) {
    if (root) {
        if (root->key == searchkey) {
            return root;
        }

        if (searchkey > root->key) {
            return searchKey(root->right, searchkey);
        }
        if (searchkey < root->key) {
            return searchKey(root->left, searchkey);
        }
    } else {
        return NULL;
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
            printf("InorderTraversal [ ");
            inorderTraversal(root);
            printf("]\n");
            printf("=====================\n");
            break;

            case 3:
            printf("=====================\n");
            printf("PreorderTraversal [");
            preorderTraversal(root);
            printf("]\n");
            printf("=====================\n");
            break;

            case 4:
            printf("=====================\n");
            printf("PostorderTraversal [");
            postorderTraversal(root);
            printf("]\n");
            printf("=====================\n");
            break;

            case 5:
            printf("\tEnter the key to search: ");
            scanf("%d",&kk);
            BST *search = searchKey(root,kk);
            (search) ? printf("FOUND! (key){%d}\n",search->key) : printf("NOT FOUND\n");
            break;

            case 6:
            printf("Smallest Element: %d\n",leftMostNode(root)->key);
            break;

            case 7:
            printf("Largest Element: %d\n",rightMostNode(root)->key);
            break;

            case 8:
            break;
        }
    }while (ch);


    deleteBST(root);
    remove(argv[0]);
    return EXIT_SUCCESS;
}