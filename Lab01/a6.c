/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+
WAP to display the array elements in reverse order.*/
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t=*a;
    *a = *b;
    *b=t;
}

int main(int argc, char const *argv[])
{
    int n=0;
    printf("enter the number of ele.. ");
    scanf("%d",&n);

    int* arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",arr+i);

    int l=0, r=n-1;
    while(l<r){
        swap((arr+l), (arr+r));
        l++;
        r--;
    }
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
    remove(argv[0]);
    return 0;
}
