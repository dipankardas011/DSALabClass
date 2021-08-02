/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+
WAP to swap the pair of elements starting from beginning.*/
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 6

void swap(int* a, int* b){
    int t=*a;
    *a = *b;
    *b = t;
}

int main(int argc, char const *argv[])
{
    int arr[6]={1,2,3,4,5,6};
    for(int i=1;i<LENGTH; i+=2)
    {
        int t=arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = t;
    }

    for(int i=0;i<LENGTH; i++)
        printf("%d ",arr[i]);
    printf("\n");
    remove(argv[0]);
    return 0;
}
