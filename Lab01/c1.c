/*WAP to sort rows of a dynamic matrix having m rows and n columns in ascending and columns in descending order.*/
#include <stdio.h>
#include <stdlib.h>
#define SWAP(a,b,t) (t)=(a), (a)=(b) , (b)=t

void sort(int*a, int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=(n-2-i);j++)
            if(a[j] > a[j+1])
                SWAP(a[j],a[j+1],temp);
    }
}

void sortD(int*a, int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=(n-2-i);j++)
            if(a[j] < a[j+1])
                SWAP(a[j],a[j+1],temp);
    }
}

void printArr(int** a, int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            printf("%2d ",a[i][j]);
        printf("\n");
    }
    printf("==========\n");
}

int main(int argc, char const *argv[])
{
    int m,n;
    scanf("%d %d",&m,&n);
    int **a = (int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++)
        a[i] = (int*)malloc(n*sizeof(int));

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    // printArr(a,m,n);

    for(int i=0;i<m;i++)
    {
        sort(a[i], n);
    }

    // printArr(a,m,n);
    for(int i=0;i<n;i++)
    {
        int *temp=(int*)malloc(m*sizeof(int));
        for(int j=0;j<m;j++)
            temp[j] = a[j][i];

        
        sortD(temp,m);
        for(int j=0;j<m;j++)
            a[j][i] = temp[j];

        free(temp);
    }
    printArr(a,m,n);
    free(a);
    

    remove(argv[0]);
    return 0;
}
