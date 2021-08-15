/*WAP to arrange the elements of a dynamic array such that all even numbers are followed by all odd numbers using a single loop.*/
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int*b)
{
    int t=*a; *a=*b; *b=t;
}

void sort(int *arr, int n)
{
    int j = -1;

    for (int i = 0; i < n; i++) {

        if (arr[i] % 2 == 0) {
 
            j++;
            swap(arr+i, arr+j);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    int l=0,
        r=n-1;

    sort(a,n);

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    free(a);
    remove(argv[0]);
    return 0;
}
