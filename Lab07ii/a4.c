/*WAP to sort an array of n integers in an ascending order using merge sort.*/
#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void display(int *a, int n) {
    printf("[ ");
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("]\n");
}

void mergeIt(int *arr, int start, int mid, int end) {
    int *temp = (int *)malloc(sizeof(int) * (end - start));

    int i = start;
    int j = mid;
    int k = 0;

    while (i<mid && j<end) {
        if (arr[i] > arr[j]) {
            temp[k++] = arr[j++];
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }

    while (i<mid) {
        temp[k++] = arr[i++];
    }

    while (j<end) {
        temp[k++] = arr[j++];
    }

    // copy the elements
    
    for (int l =0 ; l<(end - start); l++)
        arr[l + start] = temp[l];
    free(temp);
}

void mergeSort(int *arr, int s, int e) {
    if (e-s == 1)
        return ;

    int mid = s + (e - s) / 2;
    
    mergeSort(arr, s, mid);
    mergeSort(arr, mid, e);
    mergeIt(arr, s, mid, e);
    
}

int main(int argc, char **argv) {
    int arr[] = {3, 5, 7, 1, 2};
    int len = sizeof(arr) / sizeof(int);
    display(arr, len);
    mergeSort(arr, 0, len);
    display(arr, len);

    remove(argv[0]);
    return EXIT_SUCCESS;
}