/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+

WAP to search an element in a dynamic array of n numbers.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",(a+i));

    int search;
    printf("Enter the element to be searched.. ");
    scanf("%d",&search);
    int flag=0;
    for(int i=0;i<n;i++)
        if(search == a[i]){
            printf("Found! in position= %d\n",i+1);
            flag=1;
            break;
        }
    if(!flag)
        printf("Not present\n");

    free(a);
    remove(argv[0]);
    return 0;
}
