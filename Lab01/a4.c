/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+

WAP to sort a dynamic array of n numbers.
*/
#include <stdio.h>
#include <stdlib.h>

// int comp(const void* a, const void* b){
//     return *((int*)a) > *((int*)b);
// }

void swap(int* a, int* b){
    int t=*a;
    *a = *b;
    *b=t;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",(a+i));

    // bubble sorting
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=(n-1-i-1);j++){
            if(a[j]>a[j+1]){
                swap((a+j), (a+j+1));
            }
        }
    }

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");

    free(a);
    remove(argv[0]);
    return 0;
}
