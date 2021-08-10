/*Write a program to replace every element in the dynamic array with the next greatest element present in the same array.


2 5 4 64 234

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++)
        scanf("%d",(a+i));
    // here sorting is not option as the
    // 1. we need the order
    // 2. N^2 complexity
    // 3. hash table has its limitation as if the n is small and the elements are big it will have scattered so n^2 might be better
    // assuming that the array is
    int *res=NULL;
    res=(int*)malloc(n*sizeof(int));
    res[n-1]=9999;
    for(i=0;i<n-1;i++) // will not check for the last element
    {
        int min=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(j!=i && a[j] < min && a[i] < a[j]){
                min=a[j];
            }
        }
        res[i]=min;
    }
    printf("ele\tNMax\n");
    for(i=0;i<n;i++)
        printf("%d\t%d\n",a[i], res[i]);

    free(a);
    free(res);

    remove(argv[0]);
    return 0;
}
