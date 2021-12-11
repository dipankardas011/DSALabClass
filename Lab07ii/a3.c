/*WAP to sort an array of n integers in a descending order using insertion sort.*/
#include <stdio.h>
#include <stdlib.h>

void display(int* arr ,int len){
    printf("[ ");
    int i = 0;
    do {
        printf("%d", arr[i]);
        i++;
    } while (i < len && printf(", "));
    printf("]\n");
}

void insertionSort(int* arr, int len){
    for (int i = 1; i < len; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j>=0 && arr[j] < temp){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main(int argc, char **argv) {
    int arr[] = {3, 5, 1, 7, 4};
    int len = sizeof(arr) / sizeof(int);
    display(arr, len);
    insertionSort(arr, len);
    display(arr, len);
    remove(argv[0]);
    return EXIT_SUCCESS;
}