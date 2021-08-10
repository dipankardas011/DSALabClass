/*Let A be nXn square dynamic matrix. WAP by using appropriate user defined functions for the following:
    * Find the number of nonzero elements in A
    * Find the sum of the elements above the leading diagonal.
    * Display the elements below the minor diagonal.
    * Find the product of the diagonal elements.*/
#include <stdio.h>
#include <stdlib.h>

int noOfNonZero(int **arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] != 0)
                count++;

    return count;
}

/*leading diagonal is the left diagonal*/
int sumOfUpperDiagonal(int **arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i < j)
                sum += arr[i][j];

    return sum;
}

/*minor diagonal is the right diagonal*/
void printMinorDiag(int **arr, int n)
{
    printf("The elements below minor diagonal\n");
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i + j > n - 1)
                printf("%2d ", arr[i][j]);
        printf("\n");
    }
}

long int productDiag(int **arr, int n)
{
    long int prod = 1;

    if (n%2!=0)
    {
        for (int i = 0; i < n; i++)
        {
            prod *= arr[i][i];
            if (i != n/2)
            {
                prod *= arr[i][n - 1 - i];
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            prod *= arr[i][n- 1-i];
            prod *= arr[i][i];
        }
    }

    return prod;
}

void printMatrix(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%2d ", arr[i][j]);
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int **arr;
    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", (*(arr + i) + j));

    printMatrix(arr, n);

    printf("The number of Non-Zero element= %d\n",
           noOfNonZero(arr, n));

    printf("The sum of elements above leadinf diag. = %d\n",
           sumOfUpperDiagonal(arr, n));

    printMinorDiag(arr, n);

    printf("The product of diagonals= %ld\n", productDiag(arr, n));

    free(arr);
    remove(argv[0]);
    return 0;
}
