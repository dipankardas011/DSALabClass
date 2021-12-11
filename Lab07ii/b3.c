/*WAP to find the maximum difference between any two elements.*/
#include <stdio.h>
#include <stdlib.h>

struct returnType{
    int i, j;
};

struct returnType findMaxDiff(int* arr, int size){
    int min = arr[0];
    for (int i = 1; i < size;i++)
        if(min > arr[i])
            min = arr[i];


    int max = arr[0];
    for (int i = 1; i < size;i++)
        if(max < arr[i])
            max = arr[i];

    return (struct returnType){min, max};
}

int main(int argc, char **argv) {
    int arr[] = {3, 5, 19, 90, 2, 1};
    int len = sizeof(arr) / sizeof(int);
    struct returnType ret = findMaxDiff(arr, len);
    printf("Max difference elements are: {%d, %d}\n", ret.i, ret.j);
    remove(argv[0]);
    return EXIT_SUCCESS;
}