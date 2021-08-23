/*Wap to implement a Sparse matrix triplet representation using an array.*/
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

    printf("+-----+-----+-----+\n");
    printf("| row | col | val |\n");
    printf("+-----+-----+-----+\n");

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if(a[i][j]!=inv)
                printf("|%5d|%5d|%5d|\n",i,j,a[i][j]);
    printf("+-----+-----+-----+\n");

    free(a);
    remove(argv[0]);
    return 0;
}
