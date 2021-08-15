/*WAP to find the largest number and counts the occurrence of the largest number in a dynamic array of n integers using a single loop.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    int max=INT_MIN;
    int count=0;
    int Maxele=0;
    int maxcount=0;
    for(int i=0;i<n;i++)
    {
        if(a[i] > max){
            max=a[i];
            Maxele=max;
            maxcount=1;
        }else if(Maxele==a[i]){
            maxcount++;
        }
    }
    printf("the max: %d and freq: %d\n",Maxele,maxcount);
    free(a);
    remove(argv[0]);
    return 0;
}
