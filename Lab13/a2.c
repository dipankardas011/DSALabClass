/*merge sort in array*/

#include <stdio.h>
#include <stdlib.h>

void mergeArr(int *arr, int size, int start, int end, int mid){
    int *temp = (int *)malloc(sizeof(int) * (end - start));
    int i = start;
    int j = mid;
    int iterTemp = 0;
    while(i<mid && j<end){
        if(arr[i] < arr[j]){//ascending
            temp[iterTemp++] = arr[i++];
        } else {
            temp[iterTemp++] = arr[j++];
        }
    }

    while(i<mid){
        temp[iterTemp++] = arr[i++];
    }

    while(j<end){
        temp[iterTemp++] = arr[j++];
    }

    // copying
    for (i = 0; i<(end - start); i++){
        arr[i + start] = temp[i];
    }

    free(temp);
}


void mergeSort(int* arr, int size, int start, int end){
    if(end - start == 1){
        // one element is left
        return;
    }
    int midIdx = (start + end )/ 2;
    mergeSort(arr, size, start, midIdx);
    // [a, b)
    mergeSort(arr, size, midIdx, end);
    mergeArr(arr, size, start, end, midIdx);
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

    mergeSort(arr, N, 0, N);

    display(arr, N);
    free(arr);
    remove(argv[0]);
    return EXIT_SUCCESS;
}