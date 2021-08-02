/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+
WAP to find out the largest even integer stored in the array of n integers. n is the user input.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int n=0;
    printf("enter the number of ele.. ");
    scanf("%d",&n);


    int max=INT_MIN;
    int* arr = (int*)malloc(n*sizeof(int));


    for(int i=0;i<n;i++){
        scanf("%d",arr+i);
        if(!(arr[i]&1) && max<arr[i])
            max=arr[i];
    }
    printf("the largest even number= %d\n",max);
    free(arr);
    remove(argv[0]);
    return 0;
}
