/*Given a dynamic array, WAP to print the next greater element (NGE) for every element. The next greater element for an element x is the first greater element on the right side of x in array. Elements for which no greater element exist, consider next greater element as -1. E.g. For the input array [2, 5, 3, 9, 7], the next greater elements for each elements are as follows.

    Element |	NGE
    --|--
    2 |	5
    5 |	9
    3 |	9
    9 |	-1
    7 |	-1*/

#include <stdio.h>
#include <stdlib.h>
#define nge 2

int main(int argc, char const *argv[])
{
    // create 2 d array
    int n;
    scanf("%d", &n);
    int **arr;
    arr = (int **)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(nge* sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        arr[i][0] = k;
        arr[i][1] = -1;
    }

    int r = n - 2; //strarting from the second last

    while (r >= 0)
    {
        if (arr[r + 1][0] > arr[r][0]){
            arr[r][1] = arr[r + 1][0];
        }
        else{
            arr[r][1] = arr[r + 1][1];
        }
        r--;
    }

    printf("Element  |  NGE\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d  |  %d\n", arr[i][0], arr[i][1]);
    }

    free(arr);
    remove(argv[0]);
    return 0;
}
