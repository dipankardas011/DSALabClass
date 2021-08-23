/*Wap to convert a general Sparse matrix to a diagonal matrix.*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int m, n;
    printf("size of matrix.. ");
    scanf("%d %d", &m, &n);
    printf("Enter the invalid number: ");
    int inv;
    scanf("%d",&inv);
    int **a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        a[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    int c=0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if(a[i][j]!=inv){
                c++;
            }

    int **res = (int **)malloc(c * sizeof(int *));
    for (int i = 0; i < c; i++)
        res[i] = (int *)malloc(c * sizeof(int));

    int row=0, col=0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            
            if(a[i][j]!=inv)
            {
                res[row][col]=a[i][j];
                row++;
                col++;
            }
        }
    
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c;j++){
            if(i==j)
                printf("%d ",res[i][j]);
            else
                printf("* ");
        }
        printf("\n");
    }

    free(a);
    remove(argv[0]);
    return 0;
}
