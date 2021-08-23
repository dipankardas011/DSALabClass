/*Write a menu driven program to

    *  Print the upper triangular Matrix
    * Print the lower triangular Matrix
    * Print the diagonal elements*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("size.. ");
    scanf("%d",&n);

    int **mat=(int**)malloc(n*sizeof(int*));

    for(int i=0;i<n;i++)
        mat[i]=(int*)malloc(n*sizeof(int));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }

    printf("Upper triangle\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i)
                printf("%d ",mat[i][j]);
            else
                printf("* ");
        }
        printf("\n");
    }

    printf("lower triangle\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<i)
                printf("%d ",mat[i][j]);
            else
                printf("* ");
        }
        printf("\n");
    }
    
    printf("diagonal elements\n");
    printf("left diag.: ");
    for(int i=0;i<n;i++){
        printf("%d ",mat[i][i]);
    }
    printf("\n\nright diag.: ");
    for(int i=0;i<n;i++){
        printf("%d ",mat[i][n-i-1]);
    }


    free(mat);
    remove(argv[0]);
    return 0;
}
