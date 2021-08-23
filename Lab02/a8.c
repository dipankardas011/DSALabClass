/*Write a menu driven program to

    *  Add 2 Matrices
    * Check condition and multiply 2 Matrices
    * Rotate a matrix 90 degree
    * Rotate a matrix 180 degree*/

#include <stdio.h>
#include <stdlib.h>

void print(int**a, int m, int n){
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}

void swap(int* a, int* b){
    int t=*a;
    *a = *b;
    *b = t;
}

int main(int argc, char const *argv[])
{
    int m, n;
    printf("size of matrix 1.. ");
    scanf("%d %d", &m, &n);

    int **a = (int **)malloc(m * sizeof(int *));

    for (int i = 0; i < m; i++)
        a[i] = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    print(a,m,n);
    int r, c;
    printf("size of matrix 2.. ");
    scanf("%d %d", &r, &c);

    int **b = (int **)malloc(r * sizeof(int *));

    for (int i = 0; i < r; i++)
        b[i] = (int *)malloc(c * sizeof(int));

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &b[i][j]);

    print(b,r,c);

    printf("\n========================\nthe addition of 2 matrix\n");
    if (m == r && n == c)
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                printf("%d ", (a[i][j] + b[i][j]));
            printf("\n");
        }
    }
    else
    {
        printf("^~~~ INVALID dimensions\n");
    }

    printf("\n========================\nthe multiplication of 2 matrix\n");
    if (n == r)
    {
        int res[m][c];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < c; j++)
            {
                res[i][j] = 0;
                for (int x = 0; x < r; x++)
                {
                    res[i][j] += a[i][x] * b[x][j];
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < c; j++)
                printf("%d ", res[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("^~~~ INVALID dimensions\n");
    }

    printf("\n========================\nrotate 90degree\n");
    int **cm=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        cm[i]=(int*)malloc(m*sizeof(int));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cm[i][j] = a[j][i];
    }
    int top=0, bottom=n-1;

    while(top<bottom){
        for(int i=0;i<m;i++)
        {
            swap(&cm[top][i], &cm[bottom][i]);
        }
        top++;
        bottom--;
    }
    print(cm,n,m);


    printf("\n===================\nrotate 180degree\n");
    int **cm1=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++)
        cm1[i]=(int*)malloc(n*sizeof(int));

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)    
            cm1[i][j]=a[i][j];
    
    top=0, bottom=n-1;

    while(top<bottom){
        for(int i=0;i<n;i++)
        {
            swap(&cm1[top][i], &cm1[bottom][i]);
        }
        top++;
        bottom--;
    }

    for(int i=0;i<m;i++)
    {
        int l=0, r=n-1;
        while(l<r){
            swap(&cm1[i][l], &cm1[i][r]);
            l++;
            r--;
        }
    }
    
    print(cm1,m,n);



    free(a);
    free(b);
    free(cm1);
    free(cm);
    remove(argv[0]);
    return 0;
}
