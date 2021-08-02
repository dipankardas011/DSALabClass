/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+
WAP to arrange the numbers stored in the array so that it will display first all odd numbers, then even numbers.*/
#include <stdio.h>
#include <stdlib.h>


const int comp(const void* a, const void* b){
    return (*(int32_t*)a & 1)? 0: 1;
}

int main(int argc, char const *argv[])
{
    int n=0;
    printf("enter the number of ele.. ");
    scanf("%d",&n);

    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",(arr+i));

    qsort(arr, n, sizeof(int), comp);

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");

    remove(argv[0]);
    return 0;
}
