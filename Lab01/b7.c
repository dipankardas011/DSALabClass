/*WAP to replace every dynamic array element by multiplication of previous and next of an n element.*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    // we are changing one element at a time independent of direction of movement
    int *b=(int*)malloc(n*sizeof(int));

    for(int i=1; i<n-1;i++)
        b[i] = a[i-1]*a[i+1];

    //first element
    b[0] = a[1]*1;
    b[n-1] = a[n-2]*1;

    printf("ele\tnew_ele\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\n",a[i],b[i]);
    
    free(a);
    remove(argv[0]);
    return 0;
}
