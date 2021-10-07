/*
Suppose there is a circle there are N petrol pumps on that circle You are given 2 sets of data
1. the amount of petrol that every petrol pump has
2. distance from that petrol pump to the next petrol pump

Calculate the first point from where a truck will be able to complete the circle (the truck will stop at each petrol pump and it has infinite capacity). expected time complexity is O(N) assume for 1 litre petrol the truck can go 1 unit of distance
*/
/**
 * @example let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4,6}, {6,5}, {7,3} and {4,5}. the first point from where truck can make a circular tour is 2nd petrol pump output should be "start = 1" (index of 2nd petrol pump)
*/
/***
 * @e
 * petrol| distance
 *   4   | 6     (we have to go 6 units but have 4⛽) ❌
 *   6   | 5     (we have to go 5 units and have 6⛽) ✅  left=petrol-dist{1}
 *   7   | 3     (we have to go 3 units and have 7+1⛽) ✅ left = {8-3}={5}
 *   4   | 5     (we have to go 5 units and have 4+5⛽) ✅ left = 9-5 = {4}
 *   4   | 6     (we have to go 6 units and have 4+4⛽) ✅  🎉
 */
#include <stdio.h>
#include <stdlib.h>
#define INV -111
/// array implementation ////
typedef struct node {
    int petrol;
    int distance;
}Car;
Car *queue = NULL;


void allocateMemory(int n) {
    queue = (Car*)malloc(sizeof(Car)*n);
}
void freeAllocatedMemory() {
    free(queue);
}


void execTask() {
    // use circular traversal
}


int main(int argc, char **argv) {
    int N;
    fprintf(stdout, "Enter the Number of petrol pumps: ");
    fscanf(stdin, "%d", &N);
    allocateMemory(N);

    /***
     * rest of the code
     */

    freeAllocatedMemory();
    return EXIT_SUCCESS;
}

