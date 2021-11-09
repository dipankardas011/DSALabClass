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

BST *deleteNode(BST *root, int key) {

    BST *deleteIt = searchKey(root, key);
    if (deleteIt!=NULL) {
        BST *parent = findParentOfNode(root,key);

        if (isLeaf(deleteIt)) {// no child 
            if (deleteIt->key == root->key) {
                free(root);
                root = NULL;
                return root;
            }
            // remove the node simply
            if (parent->left && parent->left->key == deleteIt->key) 
                parent->left = NULL;
            else
                parent->right = NULL;

            free(deleteIt);
            return root;
        }
        if (deleteIt->left && deleteIt->right == NULL) { // only left child
            // left is present only
            if (deleteIt->key == root->key) {
                root = root->left;
                free(deleteIt);
                return root;
            }
            if (parent->left && parent->left->key == deleteIt->key) 
                parent->left = deleteIt->left;
            else
                parent->right = deleteIt->left;

            free(deleteIt);
            return root;
        }

        if (deleteIt->right && deleteIt->left == NULL) { // only right child
            // right is present only
            if (deleteIt->key == root->key) {
                root = root->right;
                free(deleteIt);
                return root;
            }
            if (parent->right && parent->right->key == deleteIt->key) 
                parent->right = deleteIt->right;
            else
                parent->left = deleteIt->right;

            free(deleteIt);
            return root;
        }

        // both children are present
        // use the inorderSuccessor(highest in left subtree of the deleteIt node)
        if (deleteIt->key == root->key) {
            BST *highestLeftSubtree = inorderPredessor(deleteIt->left);
            BST *parent_ofHighLeft = findParentOfNode(root, highestLeftSubtree->key);

            deleteIt->key = highestLeftSubtree->key;
            // we know that remove the highestLeftSubtree
            // we set the link to the
            if (parent_ofHighLeft->left && parent_ofHighLeft->left->key == highestLeftSubtree->key)
                parent_ofHighLeft->left = highestLeftSubtree->left;
            else
                parent_ofHighLeft->right = highestLeftSubtree->left;
            free(highestLeftSubtree);
            return root;
        }
        BST *highestLeftSubtree = inorderPredessor(deleteIt->left);
        BST *parent_ofHighLeft = findParentOfNode(root, highestLeftSubtree->key);
        deleteIt->key = highestLeftSubtree->key;
        if (parent_ofHighLeft->left && parent_ofHighLeft->left->key == highestLeftSubtree->key)
            parent_ofHighLeft->left = highestLeftSubtree->left;
        else
            parent_ofHighLeft->right = highestLeftSubtree->left;
        free(highestLeftSubtree);
        return root;
    } else {
        printf("Not Present\n");
        return root;
    }
}

BST* deleteNode2v(BST* root, int key)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            BST* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BST* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        BST* temp = inorderSuccessor(root->right);
 
        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
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

BST *findCommonAncestor_PrintPath(BST *root) {}

int isBinarySearchTree(BST *root) {}

int main(int argc, char **argv) {
    BST *root = 0;
    int ch = 0;
    do {
        welcomePage();
        printf("Enter choice[0/15] -> ");
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
        }
    }while (ch);


    deleteBST(root);
    remove(argv[0]);
    return EXIT_SUCCESS;
}