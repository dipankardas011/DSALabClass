/*WAP to sort an array of n floats in an ascending order using selection sort.*/
#include <stdio.h>
#include <stdlib.h>

void display(float* arr ,int len){
    printf("[ ");
    int i = 0;
    do {
        printf("%f", arr[i]);
        i++;
    } while (i < len && printf(", "));
    printf("]\n");
}

void swap(float* a, float* b){
    float t = *a;
    *a = *b;
    *b = t;
}

void selectionSort(float* arr, int len){
    // find the min element
    for (int i = 0; i < len-1; i++)
    {
        int min = i;
        for (int j = i+1; j < len; j++)
        {
            if(arr[min] > arr[j])
                min = j;
        }
        swap(arr + i, arr + min);
    }
}

int main(int argc, char **argv) {
    float arr[] = {2.3, 1.4, 6.7, 10.3, 9.2};
    int len = sizeof(arr) / sizeof(float);
    display(arr, len);
    selectionSort(arr, len);
    display(arr, len);
    remove(argv[0]);
    return EXIT_SUCCESS;
}