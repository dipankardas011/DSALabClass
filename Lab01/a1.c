/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+

WAP to find out the smallest and largest element stored in an array of n integers.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",(a+i));

    int max=INT_MIN;
    int min=a[0];
    for(int j=0;j<n;j++)
    {
        if(max<a[j])
            max=a[j];
        if(min>a[j])
            min=a[j];
        printf("%d ",a[j]);
    }
    printf("\nThe min ele= %d | max ele= %d\n",min,max);

    free(a);
    remove(argv[0]);
    return 0;
}
