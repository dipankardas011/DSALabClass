// creating a minHeap {ascending order}

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void display(int *a, int n) {
    printf("[ ");
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("]\n");
}


void heapify(int*arr, int parentIdx, int size){
    // minHeap
    int left = 2*parentIdx + 1;
    int right = 2 * parentIdx + 2;
    int minIdx = parentIdx;

    if(left < size && arr[left] < arr[minIdx])
        minIdx = left;

    if(right < size && arr[right] < arr[minIdx])
        minIdx = right;

    if(minIdx != parentIdx){
        // changed
        swap((arr + parentIdx), (arr + minIdx));
        heapify(arr, minIdx, size);
    }
}

void heapSort(int* arr, int size){

    // maximum start is 2*parentIdx + 2
    // so 2i +2 < size as array
    // so 2i < size -2
    // so i < (size -2)/2
    for (int i = (size-2)/2; i >= 0; i--)
        heapify(arr, i, size);

    int Size = size;
    int pos = 0;
    int *storage = (int *)malloc(sizeof(int) * size);
    while(Size > 1)
    {
        // printf("%d ", arr[0]);
        storage[pos++] = arr[0];
        swap(arr + 0, arr + Size - 1);
        Size--;
        heapify(arr, 0, Size);
    }
    storage[pos++] = arr[0];
    // printf("%d", arr[0]);
    for (int i = 0; i < pos; i++)
    {
        arr[i] = storage[i];
    }

    free(storage);

}

int main(int argc, char **argv) {
    int arr[] = {12,-2, 100, 121 ,11, 13, 5, 6, 7, 8, 0};
    int size = sizeof(arr) / sizeof(int);
    heapSort(arr, size);
    display(arr, size);

    remove(argv[0]);
    return EXIT_SUCCESS;
}