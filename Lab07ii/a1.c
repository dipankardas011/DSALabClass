/*WAP to sort an array of n dates in an ascending order using Bubble sort. Date structure is {day, month, year }*/
#include <stdio.h>
#include <stdlib.h>

typedef struct data{
    int day, month, year;
} Date;

void display(Date* arr ,int len){
    printf("[\n");
    for (int i = 0; i < len; i++)
    {
        printf("\t{ %d-%d-%d }\n", arr[i].day, arr[i].month, arr[i].year);
    }
    printf("]\n");
}

int cmp(Date a, Date b){
    return (a.day + a.month + a.year > b.day + b.month + b.year);
}

void swap(Date* a, Date* b){
    Date t = {a->day, a->month, a->year};

    a->day = b->day;
    a->month = b->month;
    a->year = b->year;

    b->day = t.day;
    b->month = t.month;
    b->year = t.year;
}

void bubbleSort(Date* arr, int len){
    for (int i = 0; i < len;i++)
        for (int j = 0; j < len-i-1; j++)
            if(cmp(arr[j],arr[j+1]))
                swap(arr + j, arr + j + 1);
        
}

int main(int argc, char **argv) {
    Date arr[] = {{1, 12, 2001}, {3, 5, 1990}, {31, 3, 2021}};
    int size = sizeof(arr) / sizeof(Date);

    display(arr, size);

    bubbleSort(arr, size);

    display(arr, size);

    remove(argv[0]);
    return EXIT_SUCCESS;
}