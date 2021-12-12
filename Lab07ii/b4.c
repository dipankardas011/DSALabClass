/*WAP to sort an array of n integers in an ascending order using radix sort.*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void radixSort(int* arr, int len)
{
    int count[10]={0};
    int *temp = (int *)malloc(sizeof(int) * len);
    int max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }

    int noOfDigits = (int)log10(max) + 1;
    for (int i = 0; i < noOfDigits; i++) {

        for (int i = 0; i < 10; i++){
            count[i] = 0;
        }

        for (int j = 0; j < len;j++){
            count[(arr[j] / (int)pow(10, i)) % 10]++;
        }

        // cumulative count
        for (int j = 1; j < 10;j++){
            count[j] += count[j - 1];
        }

        for (int j = len - 1; j >= 0; j--){
            temp[count[(arr[j] / (int)pow(10, i)) % 10] - 1] = arr[j];
            count[(arr[j] / (int)pow(10, i)) % 10]--;
        }

        for (int i = 0; i < len;i++)
            arr[i] = temp[i];
    }

    free(temp);
}

void display(int *a, int n) {
    printf("[ ");
    for (int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("]\n");
}


int main(int argc, char **argv) {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int len = sizeof(arr) / sizeof(int);
    display(arr,len);
    radixSort(arr, len);
    display(arr,len);

    remove(argv[0]);
    return EXIT_SUCCESS;
}