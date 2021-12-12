/*WAP to input two arrays X and Y of positive integers, find number of pairs such that x^y > y^x where x is an element from X and y is an element from Y.
Examples:
    * Input: X = {2, 1, 6}, Y = {1, 5}, Output: 3, There are total 3 pairs where pow(x, y) is greater than pow(y, x) and pairs are (2, 1), (2, 5) and (6, 1)
    * Input: X = {10, 19, 18}, Y = {11, 15, 9}; Output: 2, There are total 2 pairs where pow(x, y) is greater than pow(y, x) and pairs are (10, 11) and (10, 15)*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// brute force
int findPairs(int* x,int lenX, int* y,int lenY){
    int count=0;

    for (int i = 0; i < lenX; i++)
    {
        for (int j = 0; j < lenY; j++)
        {
            if((int)pow(x[i],y[j]) > (int)pow(y[j], x[i])){
                count++;
                printf("( %d, %d )\n", x[i], y[j]);
            }
        }
    }

    return count;
}

int main(int argc, char **argv) {
    int x[] = {2, 1, 6};
    int y[] = {1, 5};
    int lenX = sizeof(x) / sizeof(int);
    int lenY = sizeof(y) / sizeof(int);

    int count = findPairs(x, lenX, y, lenY);
    printf("No of pairs: %d\n", count);

    remove(argv[0]);
    return EXIT_SUCCESS;
}