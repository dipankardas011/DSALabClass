/*WAP to arrange the elements of a dynamic array such that all even numbers are followed by all odd numbers*/
#include <stdio.h>
#include <stdlib.h>


const int comp(const void* a, const void* b){
    return (*(int*)a & 1)? 1: 0;
}

void swap(void *a, void *b){
    int t = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = t;
}

void bubbleSort(int *a, int n, int l, int r){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=(n-i-2);j++)
            if(comp(a+j, a+j+1))
                swap(a+j, a+j+1);
    }
    return;
}


int main(int argc, char const *argv[])
{
    int n=0;
    printf("enter the number of ele.. ");
    scanf("%d",&n);

    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",(arr+i));

    bubbleSort(arr,n,0,n-1);

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    remove(argv[0]);
    return 0;
}