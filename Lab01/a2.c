/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+

WAP to reverse the contents of a dynamic array of n elements.
*/
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int t=*a;
    *a = *b;
    *b=t;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",(a+i));

    int l=0;
    int r=n-1;
    while(l<r){
        swap((a+l), (a+r));
        l++;
        r--;
    }

    for(int j=0;j<n;j++)
        printf("%d ",a[j]);
    
    printf("\n");

    free(a);
    remove(argv[0]);
    return 0;
}
