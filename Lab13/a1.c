/*quick sort in array*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int* arr, int size, int start, int end){
    if (start > end) {
        return ;
    }
    int left = start;
    int right = end;
    int pivot = (start + end) / 2;

    while(left <= right){
        while(arr[left] < arr[pivot])
            left++;

        while(arr[right] > arr[pivot])
            right--;

        if(left <= right){
            // we are reordering it as [right] < [pivot] < [left]
            // to [right] > [pivot] > [left] and continue further
            swap(arr + left, arr + right);
            left++;
            right--;
        }
    }

    quickSort(arr, size, start, right);
    quickSort(arr, size, left, end);
}

void display(int* arr, int len){
    printf("[ ");
    int iter = 0;
    do
    {
        printf("%d", arr[iter]);
        iter++;
    } while (iter < len && printf(", "));
    printf("]\n");
}

int main(int argc, char **argv) {
    int *arr = NULL;
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);
    arr = (int *)malloc(sizeof(int) * N);
    printf("Enter the elements: ");
    for (int i = 0; i < N; i++)
        scanf("%d", arr + i);

    display(arr, N);

    quickSort(arr, N, 0, N - 1);

    display(arr, N);
    free(arr);
    remove(argv[0]);
    return EXIT_SUCCESS;
}