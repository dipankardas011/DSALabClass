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
// using efficient algo. {GeeksForGeeks}
int* binarySearch(int *Y, int len, int search){
    int mid;
    int s = 0;
    int e = len - 1;
    while(s<=e){
        mid = s + (e - s) / 2;
        if(Y[mid] == search){
            return (Y + mid);
        }
        if(Y[mid] > search)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return s + Y;
}

int count(int x, int Y[], int n, int NoOfY[])
{
    // If x is 0, then there cannot be any value in Y such
    // that x^Y[i] > Y[i]^x
    if (x == 0)
        return 0;
 
    // If x is 1, then the number of pais is equal to number
    // of zeroes in Y[]
    if (x == 1)
        return NoOfY[0];
 
    int* idx = binarySearch(Y, n, x);
    int ans = (Y + n) - idx;
 
    ans += (NoOfY[0] + NoOfY[1]);
 
    // Decrease number of pairs for x=2 and (y=4 or y=3)
    if (x == 2)
        ans -= (NoOfY[3] + NoOfY[4]);
 
    // Increase number of pairs for x=3 and y=2
    if (x == 3)
        ans += NoOfY[2];
 
    return ans;
}
 
// Function to return count of pairs (x, y) such that
// x belongs to X[], y belongs to Y[] and x^y > y^x
int countPairs(int X[], int Y[], int m, int n)
{
    // To store counts of 0, 1, 2, 3 and 4 in array Y
    int NoOfY[5] = { 0 };
    for (int i = 0; i < n; i++)
        if (Y[i] < 5)
            NoOfY[Y[i]]++;
 
    // Sort Y[] so that we can do binary search in it
    // sort(Y, Y + n);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n - i - 1;j++)
            if(Y[j] > Y[j+1]){
                int t = Y[j];
                Y[j] = Y[j + 1];
                Y[j + 1] = t;
            }
    }

    int total_pairs = 0; // Initialize result
 
    // Take every element of X and count pairs with it
    for (int i = 0; i < m; i++)
        total_pairs += count(X[i], Y, n, NoOfY);
 
    return total_pairs;
}

int main(int argc, char **argv) {
    int x[] = {2, 1, 6};
    int y[] = {1, 5};
    int lenX = sizeof(x) / sizeof(int);
    int lenY = sizeof(y) / sizeof(int);

    // int count = findPairs(x, lenX, y, lenY);
    int count = countPairs(x, y, lenX, lenY);
    printf("No of pairs: %d\n", count);

    remove(argv[0]);
    return EXIT_SUCCESS;
}