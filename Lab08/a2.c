/*wap to create Binary tree ans store as per the user input (NOTE filling as left to right)*/
#include <stdio.h>
#include <stdlib.h>

typedef struct kk
{
    int data;
    struct kk *left;
    struct kk *right;
    // as the degree is 2
} Btree;

Btree *createNodes(int d)
{
    Btree *t = (Btree *)malloc(sizeof(Btree));
    t->data = d;
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


void display() {
    if(isEmpty()){
        printf("[]\n");
    } else {
        int iter = front;
        printf("[");
        do {
            printf("%d",queue[iter]->data);
            iter++;
        }while (iter<=rear && printf(", "));
        printf("]\n");
    }
}

Btree *insertLeaves(Btree *root, int key) {

    if (!root) {
        return createNodes(key);
    }

    push(root);
    // printf("Front: %d | Rear: %d\n",front, rear);
    // display();
    while (!isEmpty()) {
        Btree *parent = peek();
        pop();

        if (parent->left!=NULL) {
            push(parent->left);
        } else {
            parent->left = createNodes(key);
            return root;
        }

        if (parent->right!=NULL) {
            push(parent->right);
        } else {
            parent->right = createNodes(key);
            return root;
        }
    }
    return root;
}


/**
 * expectation
 *      1
 *    /  \
 *   2   3
 *  /\   /\
 * 4 5  6 7
 *  === 4 2 5 1 6 3 7
 */

void inorderTrav(Btree *root) {
    if(root) {
        printf("%d ",root->data);
        inorderTrav(root->left);
        inorderTrav(root->right);
    }
}

void deleteTree(Btree* root){
    if(root){
        deleteTree(root->left);
        deleteTree(root->right);
        free(root);
    }
}

int main(int argc, char **argv)
{
    Btree *root = NULL;
    root = insertLeaves(root, 1);
    root = insertLeaves(root, 2);
    root = insertLeaves(root, 3);
    root = insertLeaves(root, 4);
    root = insertLeaves(root, 5);
    root = insertLeaves(root, 6);
    root = insertLeaves(root, 7);

    inorderTrav(root);
    printf("\n");

    deleteTree(root);
    remove(argv[0]);
    return EXIT_SUCCESS;
}