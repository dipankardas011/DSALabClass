/*WAP to find out the kth smallest and kth largest element stored in a dynamic array of n integers, where k< n.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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
/*send the array as the call by value not by reference */
int kthSmallest(int a[], int n, int k)
{
    int i=k;
    int min;
    while(i){
        min=a[0];
        int pos=0;
        for(int j=0;j<n;j++){
            if(a[j]<min)
                min = a[j],
                pos=j;
        }
        a[pos]=INT_MAX;
        i--;
    }
    return min;
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
    printf("kth smallest: %d\n",kthSmallest(a,n,k));
    free(a);
    remove(argv[0]);
    return 0;
}
