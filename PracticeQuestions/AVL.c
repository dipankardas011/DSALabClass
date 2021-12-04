#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int data;
    int height;
    struct n *left, *right;
} avl;

avl* createNode(int k){
    avl *t = (avl *)malloc(sizeof(avl));

    t->data = k;
    t->left = t->right = NULL;
    t->height = 1;
    return t;
}

void inorderTraversal(avl* tree){
    if(tree){
        inorderTraversal(tree->left);
        printf("%d ",tree->data);
        inorderTraversal(tree->right);
    }
}

int height(avl* root){
    if(root)
        return root->height;
    else
        return 0;
}

int max(int a, int b){
    return a>b ? a : b;
}

int Balance(avl* root){
    if(!root)
        return 0;

    return height(root->left) - height(root->right);
}


/**
 * @def rightRotation
 * 
 *    ..
 *   / \
 *  {} &
 * / \
 *M  []
 * 
 *   {}
 *  / \
 * M  ..
 *   / \
 *  [] &
 */

avl* rightRotation(avl* parent){
    /***
     * @param parent ..
     * @param l {}
     */
    avl* l = parent->left;
    avl* lRight = parent->left->right;
    l->right = parent;
    parent->left = lRight;


    l->height = max(height(l->left), height(l->right)) + 1;
    parent->height = max(height(parent->left), height(parent->right)) + 1;


    return l;
}


/**
 * @def leftRotation
 * 
 *    ..
 *   / \
 *  &  {}
 *    / \
 *   [] M
 * 
 *    {}
 *   / \
 *  .. M
 * / \
 *&  []
 */

avl* leftRotation(avl* parent){
    /***
     * @param parent ..
     * @param r {}
     */
    avl* r = parent->right;
    avl* rLeft = parent->right->left;
    parent->right = rLeft;
    r->left = parent;

    r->height = max(height(r->left), height(r->right)) + 1;
    parent->height = max(height(parent->left), height(parent->right)) + 1;

    return r;
}


avl* insertKey(avl* root, int ikey){
    if(!root)
        return createNode(ikey);

    if(root->data < ikey)
        root->right = insertKey(root->right, ikey);
    else if(root->data > ikey)
        root->left = insertKey(root->left, ikey);
    else     // duplication
        return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    // here the balacing will take place
    int balance = Balance(root);

    if(balance > 1 && root->left->data > ikey){
        // right-right
        return rightRotation(root);
    }

    if(balance < -1 && root->right->data < ikey){
        // left-left
        return leftRotation(root);
    }

    if(balance > 1 && root->left->data < ikey){
        // left-right
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    if(balance < -1 && root->right->data > ikey){
        // right-left
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    

    // after the edit return the root for further left stack calls
    return root;
}

avl* inorderSuccessor(avl* node){
    if(!node)
        return NULL;
    while(node->left)
        node = node->left;
    return node;
}

avl* deleteKey(avl* root, int dkey){
    if(!root){
        return NULL;
    }

    if(root->data > dkey)
        root->left = deleteKey(root->left, dkey);
    else if(root->data < dkey)
        root->right = deleteKey(root->right, dkey);

    else {
        // found the element to be deleted
        if(!root->left || !root->right){
            avl* temp = root->left ? root->left : root->right;

            if(!temp){
                // no children
                free(root);
                root = NULL;
            } else {
                // only one children
                free(root);
                root = temp;
            }
        } else {
            // both children are present
            avl* inorderSucc = inorderSuccessor(root->right);
            root->data = inorderSucc->data;
            root->right = deleteKey(root->right, inorderSucc->data);
        }
    }

    if(!root)
        return NULL;

    root->height = max(height(root->left), height(root->right)) +1;
    int balance = Balance(root);

    if(balance > 1 && Balance(root->left) >= 1){
        // right right
        return rightRotation(root);
    } 

    if(balance < -1 && Balance(root->right)<= -1){
        //left left
        return leftRotation(root);
    }

    if(balance > 1 && Balance(root->left)<= -1){
        // left-right
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    if(balance < -1 && Balance(root->right) >= 1){
        // right-left
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    return root;
}

int main(int argc, char **argv){
    avl* root = NULL;

    int ch;
    do{
        printf("[ 1 ] insertion\n[ 2 ] display\n[ 3 ] deletion\n[ 0 ] EXIT\n> ");
        scanf("%d",&ch);
        int k=0;
        switch(ch){
            case 1:{
                printf("Enter the key to be inserted: ");
                scanf("%d",&k);
                root = insertKey(root, k);
                break;
            } 
            case 2:{
                printf("Inorder: [ ");
                inorderTraversal(root);
                printf("]\n");
                break;
            }
            case 3:{
                printf("Enter the key to be deleted: ");
                scanf("%d",&k);
                root = deleteKey(root, k);
                break;
            }
        }
    }while(ch);


    remove(argv[0]);
    return EXIT_SUCCESS;
}