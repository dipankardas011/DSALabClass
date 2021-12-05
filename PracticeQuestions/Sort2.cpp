/*
1. Let A[1], A[2], . . . , A[n] be an array containing n very large positive integers.
Describe an efficient algorithm to find the minimum positive difference
between any two integers in the array. What is the complexity of your
algorithm? Explain.

2. Design an efficient algorithm to sort 5 distinct keys.

3. Let A = A[1], . . . , A[n] be an array of n distinct positive integers. An inversion
is a pair of indices i and j such that i < j but A[i] > A [j]. For example in the
array [30000, 80000, 20000, 40000, 10000], the pair i = 1 and j = 3 is an
inversion because A [1] = 30000 is greater than A[3] = 20000. On the other
hand, the pair i = 1 and j = 2 is not an inversion because A [1] = 30000 is
smaller than A [2] = 80000. In this array there are 7 inversions and 3 noninversions.
Describe an efficient algorithm that counts the number of
inversions in any array. What is the running time of your algorithm?*/
#include <iostream>
#include <ctime>
using namespace std;

namespace Q1
{
    void exec()
    {
        int arr[10];

        srand(time(0));

        for (int i = 0; i < 10; i++)
        {
            arr[i] = rand() % 10;
        }

        for (int i = 0; i < 10; i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<endl;
        int minDiff = abs(arr[1] - arr[0]);

        // Minimum number visited so far
        int maxElement = arr[0];
        for (int i = 1; i < 10; i++)
        {
            if (abs(arr[i] - maxElement) < minDiff)
                minDiff = abs(arr[i] - maxElement);

            if (arr[i] > maxElement)
                maxElement = arr[i];
        }

        std::cout<<"Mindiff: "<<minDiff<<std::endl;
    }
}

namespace Q2
{
    void exec() {
        int arr[5] = {5,1,6,9,0};
    }
}

namespace Q3
{
    void exec() {
        int arr[]={30000, 80000, 20000, 40000, 10000};
        int noninversion = 0, inversion = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = i+1; j < 5; j++)
            {
                if(arr[i] > arr[j])
                    inversion++;
                else
                    noninversion++;
            }
        }
        cout << "Inversion: " << inversion << " NonInversion: " << noninversion << endl;
    }
}

int main(int argc, char **argv)
{
    Q1::exec();
    Q2::exec();
    Q3::exec();
    remove(argv[0]);
    return EXIT_SUCCESS;
}