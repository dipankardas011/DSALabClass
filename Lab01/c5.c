/*WAP to swap all the elements in the 1st column with all the corresponding elements in the last column, and 2nd column with the second last column and 3rd with 3rd last etc. of a 2-D dynamic array.  Display the matrix*/

#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b,t) t=a, a=b , b=t

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int **a=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        a[i]=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    int lcol=0,
        rcol=n-1;

    while(lcol<rcol)
    {
        int t;
        for(int i=0;i<n;i++)
            SWAP(a[i][lcol], a[i][rcol],t);
        lcol++;
        rcol--;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    free(a);
    remove(argv[0]);
    return 0;
}
