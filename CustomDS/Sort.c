#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

// first merge sort
void display(int *a, int n) {
    printf("[ ");
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("]\n");
}

void mergeIt(int *arr, int start, int mid, int end) {
    int *temp = (int*)malloc(sizeof(int)*(end-start));

    int i=start;
    int j=mid;
    int k=0;

    while (i<mid && j<end) {
        if (arr[i] > arr[j]) {
            temp[k++] = arr[j++];
        } else {
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



/// quick sort///

void quickSort(int *arr, int S, int E) {
    if (S > E) {
        return ;
    }
    int Si = S;
    int Ei = E;
    int mid = S + (E - S) / 2;

    int pivot = arr[mid];
    while (Si <= Ei) {
        while (arr[Si] < pivot)
            Si++;

        while (arr[Ei] > pivot)
            Ei--;

        if (Si <= Ei) {
            swap(arr, Si, Ei);
            Si++;
            Ei--;
        }
    }

    quickSort(arr, S, Ei);
    quickSort(arr, Si, E);
}

size_t countDigits(int N){
    if(N > 0){
        return 1 + countDigits(N / 10);
    }
}

void radixSort(int *arr, int size){

    int count[10] = {0};
    int *storage = (int *)malloc(sizeof(int) * size);

    // find the max with its max digits
    int max = -1;
    for (int i = 0;i<size;i++){
        if(arr[i] > max)
            max = arr[i];
    }
    size_t numberOfDigits = countDigits(max);
    for (size_t digitsPlace = 0; digitsPlace < numberOfDigits; digitsPlace++) {
        for (int i = 0; i < size;i++){
            count[(arr[i] / (int)pow(10, digitsPlace)) % 10]++;
        }

        // summing the freq
        for (int i = 1; i < 10;i++)
            count[i] += count[i-1];
        
        // placing it in the appropiate place
        for (int i = size - 1; i >= 0;i--){
            storage[
                count[
                    (arr[i] / (int)pow(10, digitsPlace)) 
                    % 10
                ] - 1
            ] = arr[i];

            count[(arr[i] / (int)pow(10, digitsPlace)) % 10]--;
        }

        for (int i = 0; i < size; i++)
            arr[i] = storage[i];

        // emptying the count arr
        for (int i = 0; i < 10; i++)
            count[i] = 0;
    }

    free(storage);
    return;
}


int main(int argc, char **argv) {
    int arr[] = {1,4,5,2,6};
    int size;
    size = sizeof(arr) / sizeof(int);
    mergeSort(arr, 0, size);

    display(arr, size);

    int arr1[] = {5,4,3,2,1};
    size = sizeof(arr1) / sizeof(int);
    quickSort(arr1, 0, size - 1);

    display(arr1, size);

    int arr2[] = {170, 45, 75, 90, 802, 24, 2, 66};
    size = sizeof(arr2) / sizeof(int);
    radixSort(arr2, size);
    display(arr2, size);

    remove(argv[0]);
    return EXIT_SUCCESS;
}