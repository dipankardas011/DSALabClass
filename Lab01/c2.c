/*WAP to find out the kth smallest and kth largest element stored in a dynamic array of n integers, where k< n.*/
#include <stdio.h>
#include <stdlib.h>

void sort(int* a,int n)
{
    for(int i=1;i<n;i++)
    {
        int t=a[i];
        int j=i-1;
        while(j>=0 && a[j] > t)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=t;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(n));
    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    printf("Enter the k.. ");
    int k;
    scanf("%d",&k);

    sort(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nthe {%d}th smallest and {%d}th largest = %d, %d\n",k,k,a[k-1], a[n-k]);
    free(a);
    remove(argv[0]);
    return 0;
}
