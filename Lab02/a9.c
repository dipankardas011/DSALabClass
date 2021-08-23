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
    scanf("%d", &inv);
    int **a = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        a[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);


    int **res = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        res[i] = (int *)malloc(n * sizeof(int));

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            res[i][j]=inv;

    int row = 0, col = 0;
    int flag=0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != inv)
            {
                if ((row == m || col == n) && !flag)
                {
                    flag=1;
                    row = 0;
                    col = 1;
                    //shift to right
                    res[row][col] = a[i][j];
                }
                else if((row == m || col == n) && flag){
                    flag=2;
                    row = 1;
                    col = 0;
                    //shift to left
                    res[row][col] = a[i][j];
                }
                else
                    res[row][col] = a[i][j];

                row++;
                col++;
            }
        }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (res[i][j]!=inv)
                printf("%d ", res[i][j]);
            else
                printf("* ");
        }
        printf("\n");
    }

    free(a);
    remove(argv[0]);
    return 0;
}
