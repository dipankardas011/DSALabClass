/*WAP to sort an array of n doubles in a descending order using quick sort.*/
#include <stdio.h>
#include <stdlib.h>

void swap(double* a, double* b) {
    double t = *a;
    *a = *b;
    *b = t;
}

void display(double *a, int n) {
    printf("[ ");
    for (int i=0;i<n;i++)
        printf("%lf ",a[i]);
    printf("]\n");
}

void quickSort(double *arr, int S, int E) {
    if (S > E) {
        return ;
    }
    int Si = S;
    int Ei = E;
    int mid = S + (E - S) / 2;

    double pivot = arr[mid];
    while (Si <= Ei) {
        while (arr[Si] > pivot)
            Si++;

        while (arr[Ei] < pivot)
            Ei--;

        if (Si <= Ei) {
            swap(arr+Si, arr+Ei);
            Si++;
            Ei--;
        }
    }
    quickSort(arr, S, Ei);
    quickSort(arr, Si, E);
}

int main(int argc, char **argv) {
    double arr[] = {3.67, 4.6, 1.34, 0.12, -0.3};
    int len = sizeof(arr) / sizeof(double);
    display(arr, len);
    quickSort(arr, 0, len-1);
    display(arr, len);
    remove(argv[0]);
    return EXIT_SUCCESS;
}