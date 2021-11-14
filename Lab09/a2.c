/*WAP Write the following menu driven program for the binary search tree
Binary Search Tree Menu
0. Quit
1. Create (Insert a node as per user entered key value.)
2. In-Order Traversal
3. Pre-Order Traversal
4. Post-Order traversal
5. Search an element
6. Find Smallest Element
7. Find Largest Element
8. Deletion of a node as per user entered key value.
 Deletion of the whole Tree
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
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
    printf("> 9. No. of leaves of Tree\n");
    printf("> 10. No. of non-leaves of Tree\n");
    printf("> 11. No. of nodes of Tree\n");
    printf("> 12. Sum of all nodes of Tree\n");
    printf("> 13. Depth of node specified in Tree\n");
    printf("> 14. Height of Tree\n");
    printf("> 15. print Kth Level of Tree\n");
    printf("> 16. Find the ancestor of Tree\n");
    printf("> 17. Is Binary Tree == Binary Search Tree\n");
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
BST *inorderPredessor(BST *subroot) {
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
BST *inorderSuccessor(BST *subroot) {
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


BST *findParentOfNode(BST *root, int key) {
    if (root) {

        // if the root is the key
        if (key == root->key) {
            return root;
        }

        if (key < root->key && root->left) {
            return (root->left->key == key) ? root : findParentOfNode(root->left,key);
        }
        if (key > root->key && root->right) {
            return (root->right->key == key) ? root : findParentOfNode(root->right, key);
        }
    } else {
        return NULL;
    }
}

int isLeaf(BST *root) {
    return (!(root->left) && !(root->right)) ? 1 : 0;
}

BST* deleteNode(BST* root, int key) {
    if (!root)
        return root;

    if (key > root->key)
        root->right = deleteNode(root->right, key);

    else if (key < root->key)
        root->left = deleteNode(root->left, key);

    else {
        // got the answer
        if (!root->left || !root->right) {
            // anyone | both are NULL
            BST* tmp = root->left ? root->left : root->right;

            if (!tmp) {
                // no child
                free(root);
                return NULL;// return NULL from where it was called
            }
            else {
                // root == key
                free(root);
                return tmp;
            }
        }
        else {
            BST* temp = inorderSuccessor(root->right);
            root->key = temp->key;
            //delete the inorder succesor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    return root;
}

int noOfLeafNodes(BST *root) {
    if (!root) {
        return 0;
    }
    if (isLeaf(root))
        return 1;
    return noOfLeafNodes(root->left) + noOfLeafNodes(root->right);
}

int noOfNonLeafNodes(BST *root) {
    if (root) {
        if (isLeaf(root))
            return 0;

        return 1 + noOfNonLeafNodes(root->left) + noOfNonLeafNodes(root->right);
    } else {
        return 0;
    }
}

int noOfNodes(BST *root) {
    if (root) {
        return 1 + noOfNodes(root->left) + noOfNodes(root->right);
    } else {
        return 0;
    }
}

size_t sumOfAllNodes(BST *root) {
    if (root) {
        return root->key + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
    } else {
        return 0;
    }
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
/**
 * @param depth passed 0 initially
 */
int depthOfTree(BST *root, int key, int depth) {
    if (!root) {
        return 0;
    }

    if (root->key == key) {
        return depth;
    }
    return max(depthOfTree(root->left, key, depth + 1), depthOfTree(root->right, key, depth + 1));
}
// max depth == height of tree
int heightOfTree(BST *root) {
    if (!root) {
        return 0; 
    }

    int Hleft = heightOfTree(root->left);
    int Hright = heightOfTree(root->right);
    return max(Hleft, Hright) + 1;// if Hleft is MAX then return Hleft + 1 and vicecersa
}

void printLevel(BST *root, int currlevel, bool toPrint) {
    if (!root)
        return;

    if (currlevel == 1 && toPrint == true) {
        printf("%d ", root->key);
        return;
    }

    printLevel(root->left, currlevel - 1, toPrint);
    printLevel(root->right, currlevel - 1, toPrint);
}

void printKthLevel(BST *root, int K) {
    // using Queue datastructure
    int height = heightOfTree(root);
    for (int i = 1; i <= height; i++)
    {
        printf("{ ");
        // as level + 1 = height
        // here i is height 
        (K + 1 == i) ? printLevel(root, i, true) : printLevel(root, i, false);
        printf("}\n\n");
    }
}

BST* findCommonAncestorUTIL(BST* root, int k1, int k2) {
    if (!root)
        return NULL;

    // If both n1 and n2 are less than root, then ancestor lies in left
    if (root->key > k1 && root->key > k2)
        return findCommonAncestorUTIL(root->left, k1, k2);

    // If both n1 and n2 are greater than root, then ancestor lies in right
    if (root->key < k1 && root->key < k2)
        return findCommonAncestorUTIL(root->right, k1, k2);

    // this means that whenever the k1 and k2 are not in same subtree return root
    /**
     * exaple
     *      ..
     *     /  \
     *   ..   ..
     *  / \   / \
     * .. #  # ..
     * if we selected # then we can see the if statements abpve dont match
     * thus means that this is the last ancestor
     */
    return root;
}

BST* findCommonAncestor(BST* root, int k1, int k2) {
    return findCommonAncestorUTIL(root, k1, k2); 
}

void printPath(BST* root, int k) {
    if (!root)
        return;
    
    if (root->key == k) {
        printf("%d", root->key);
        return;
    }

    // else recursive call
    printf("%d->", root->key);
    (root->key > k) ? printPath(root->left, k) : printPath(root->right, k);
}

void findCommonAncestor_PrintPath(BST* root, int k1, int k2) {
    BST* ancestor = findCommonAncestor(root, k1, k2);
    printf("{");
    printPath(ancestor, k1);
    printf("}\n");
    printf("{");
    printPath(ancestor, k2);
    printf("}\n");
}

int isRelationCorrect(BST* root, int min, int max) {
    if (!root)
        return 1;

    if (root->key < min || root->key > max)
        return 0;

    return isRelationCorrect(root->left, min, root->key) &&
        isRelationCorrect(root->right, root->key + 1, max);
}

int isBinarySearchTree(BST* root) {
    // it must return true
    return isRelationCorrect(root, INT_MIN, INT_MAX);
}

int main(int argc, char **argv) {
    BST *root = 0;
    int ch = 0;
    do {
        welcomePage();
        printf("Enter choice[0/17] -> ");
        scanf("%d",&ch);
        int kk=0;
        switch(ch) {
            case 1: {
                printf("\tEnter the key to insert: ");
                scanf("%d",&kk);
                insertNode(&root, kk);
                break;
            }

            case 2: {
                printf("=====================\n");
                printf("InorderTraversal [ ");
                inorderTraversal(root);
                printf("]\n");
                printf("=====================\n");
                break;
            }

            case 3: {
                printf("=====================\n");
                printf("PreorderTraversal [ ");
                preorderTraversal(root);
                printf("]\n");
                printf("=====================\n");
                break;
            }

            case 4: {
                printf("=====================\n");
                printf("PostorderTraversal [ ");
                postorderTraversal(root);
                printf("]\n");
                printf("=====================\n");
                break;
            }

            case 5: {
                printf("\tEnter the key to search: ");
                scanf("%d",&kk);
                BST *search = searchKey(root,kk);
                (search) ? printf("FOUND! (key){%d}\n",search->key) : printf("NOT FOUND\n");
                break;
            }

            case 6: {
                printf("Smallest Element: %d\n",leftMostNode(root)->key);
                break;
            }

            case 7: {
                printf("Largest Element: %d\n",rightMostNode(root)->key);
                break;
            }

            case 8: {
                printf("\tEnter key to delete: ");
                scanf("%d",&kk);
                root = deleteNode(root, kk);
                break;
            }

            case 9: {
                printf("No. of leaves: %d\n", noOfLeafNodes(root));
                break;
            }

            case 10: {
                printf("No. non-leaf nodes: %d\n", noOfNonLeafNodes(root));
                break;
            }

            case 11: {
                printf("Total no. nodes: %d\n", noOfNodes(root));
                break;
            }

            case 12: {
                printf("Sum of all nodes: %ld\n", sumOfAllNodes(root));
                break;
            }

            case 13: {
                printf("Enter the key whose depth is to be found: ");
                scanf("%d", &kk);
                assert(searchKey(root, kk) != NULL);
                printf("Depth of key{%d}: %d\n", kk, depthOfTree(root, kk, 0));
                break;
            }

            case 14: {
                printf("Enter the key whose height is to be found: ");
                scanf("%d", &kk);
                BST *node = searchKey(root, kk);
                assert(node != NULL);
                printf("Height: %d\n", heightOfTree(node));
                break;
            }

            case 15: {
                printf("Enter the level to be printed: ");
                scanf("%d", &kk);
                printKthLevel(root, kk);
                break;
            }

            case 16: {
                printf("Enter the 2 keys to be searched of there common ansestor: ");
                int k1;
                int k2;
                scanf("%d %d", &k1, &k2);
                assert(searchKey(root, k1) != NULL);
                assert(searchKey(root, k2) != NULL);
                printf("Ancestor key value: %d\n", findCommonAncestor(root, k1, k2)->key);
                findCommonAncestor_PrintPath(root, k1, k2);
                break;
            }
            case 17: {
                printf("%d\n", isBinarySearchTree(root));
                break;
            }
        }
    }while (ch);


    deleteBST(root);
    remove(argv[0]);
    return EXIT_SUCCESS;
}