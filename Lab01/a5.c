/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+

Given an unsorted dynamic array of size n, WAP to find and display the number of elements between two elements a and b (both inclusive). E.g. Input : arr = [1, 2, 2, 7, 5, 4], a=2 and b=5, Output : 4 and the numbers are: 2, 2, 5, 4.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int* arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",(arr+i));

    int a,b;
    printf("Enter the a, b\n");
    scanf("%d %d",&a, &b);
    // it is sure the elements are there
    int l=0;
    int r=n-1;
    while(l<n){
        if(arr[l]==a){
            break;
        }
        l++;
    }
    while(r>=0){
        if(arr[r]==b){
            break;
        }
        r--;
    }
    printf("\t#%d\n",(r-l+1));
    free(arr);
    remove(argv[0]);
    return 0;
}
