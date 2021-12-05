/*
 Suppose ROOT A points to a binary tree T1. Write the pseudo code which
makes a copy T2 of the tree T1 using ROOT B as pointer
 Write a function that traverses a threaded binary tree in postorder. What are
the time and space requirement of your method?
 Write a function that traverses a threaded binary tree in preorder. What are
the time and space requirement of your method?
*/

#include <iostream>
using namespace std;

namespace Q1{
    typedef struct n1{
        int data;
        struct n1* left, *right;
    }tree;

    tree* createNode(int k){
        tree* t = new tree;
        t->data = k;
        t->left = t->right = nullptr;
        return t;
    }

    void inorderTraversal(tree* r){
        if(r){
            inorderTraversal(r->left);
            printf("%d ",r->data);
            inorderTraversal(r->right);
        }
    }

    tree* copyTree(tree* orig, tree* dest){
        if(!orig){
            return NULL;
        }

        tree* t = createNode(orig->data);
        t->left = copyTree(orig->left, t->left);
        t->right = copyTree(orig->right, t->right);

        return t;
    }

    void exec(){
        tree* T1 = nullptr;
        T1 = createNode(1);
        T1->left = createNode(2);
        T1->right = createNode(5);
        T1->right->left = createNode(8);
        T1->left->left = createNode(9);
        /**
         *    1
         *   / \
         *  2   5
         * /   /
         *9   8
         */
        inorderTraversal(T1);

        printf("\nCopied: [ ");
        tree* T2 = nullptr;
        T2 = copyTree(T1, T2);
        inorderTraversal(T2);
        printf("]\n");
    }
}

namespace Q2_Q3{
    /*
    

A threaded tree node typically has a flag that tells you whether the right and left pointers in the node are references to children, or threads to the inorder/preorder successor. That's the only way you can tell if the node is a leaf.

The nice thing about a threaded tree is that inorder or reverse inorder traversals can be done quickly without recursion. But a threaded tree doesn't help you with postorder or preorder traversals. If you want to do one of those, you have to use the recursive algorithm, taking the threads into account. For example:

preorder(node)
    print node
    if (node.left is not a thread link)
        preorder(node.left)
    if (node.right is not a thread link)
        preorder(node.right)

postorder(node)
    if (node.left is not a thread link)
        preorder(node.left)
    if (node.right is not a thread link)
        preorder(node.right)
    print node


    */
}

int main(int argc, char** argv) {
    Q1::exec();
    remove(argv[0]);
    return EXIT_SUCCESS;
}