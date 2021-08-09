#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int m,n;
    scanf("%dx%d",&m,&n);

    int** arr;
    arr = (int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++){
        arr[i] = (int*)malloc(n*sizeof(int));
    }
    int ee=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=ee;
            ee++;
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    free(arr);
    remove(argv[0]);
}