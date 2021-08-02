/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+

WAP to create an array that can store max. 50 integers and display the contents of the array

WAP to find out the sum of the numbers stored in an array of integers.

WAP to find largest element stored in an array.

WAP to display the array elements in ascending order.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_LENGTH 50

const int comp(const void* a, const void* b){
    return (*(int32_t*)a > *(int32_t*)b)? 1:0;
}

int main(int argc, char const *argv[])
{
    int32_t arr[MAX_LENGTH];
    printf("Enter 10 elements..\n");
    for(int i=0;i<10;i++)
        scanf("%d",(arr+i));
    
    int32_t sum=0;
    int32_t max=INT_MIN;

    /* ascending order */
    qsort(arr, 10, sizeof(int32_t), comp);

    /* finding the sum, max ele, printing final arr */
    for(int i=0;i<10;i++){
        printf("%d ",*(arr+i));
        sum+=arr[i];
        if(max<arr[i])
            max=arr[i];
    }


    printf("\n");
    printf("Sum of elements= %d\nThe max element= %d\n",sum, max);

    remove(argv[0]);
    return 0;
}
