/*WAP to find out the second smallest and second largest element stored in a dynamic array*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
	if(n<2){
		printf("Cannot find the second min of max\n");
		return 0;
	}
    int *a;

    a=(int* )malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    

    int min=INT_MAX, secMin=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i] < min){
			secMin=min;
			min=a[i];
		}

		// if its between the min and secMin
		else if(a[i]>min && a[i]<secMin){
			secMin=a[i];
		}
	}
	int max=INT_MIN, secMax=INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(a[i] > max){
			secMax=max;
			max=a[i];
		}

		// if its between the max and secMax
		else if(a[i]>secMax && a[i]<max){
			secMax=a[i];
		}
	}
    
    printf("The smallest= %d\nThe Largest= %d\n",min, max);
    printf("The second smallest= %d\nThe second Largest= %d\n",secMin, secMax);
    free(a);
    remove(argv[0]);
    return 0;
}
