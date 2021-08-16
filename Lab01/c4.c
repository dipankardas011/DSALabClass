/*You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. Traverse array only once.*/
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

        if (!arr[i]) {
 
            j++;
            swap(arr+i, arr+j);
        }
    }
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    sort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

    free(a);
    remove(argv[0]);
    return EXIT_SUCCESS;
}