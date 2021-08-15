/*You are given an array of 0s and 1s in random order. Segregate 0s on left side and 1s on right side of the array. Traverse array only once.*/
#include <stdio.h>
#include <stdlib.h>
// #include <limits.h>

void sort(int* a,int n)
{
    for(int i=1;i<n;i++)
    {
        int t=a[i];
        int j=i-1;
        while(j>=0 && a[j] > t)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
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