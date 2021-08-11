/*
Given an unsorted dynamic array arr and two numbers x and y, find the minimum distance between x and y in arr. The array might also contain duplicates. You may assume that both x and y are different and present in arr.
Input: arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6
Output: Minimum distance between 3 and 6 is 4.
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int *a;

    a=(int* )malloc(n*sizeof(int));
    int x,y;
    for(int i=0;i<n;i++)
        scanf("%d",a+i);

    printf("Enter x and y.. ");
    scanf("%d %d",&x,&y);

    int minDist = INT_MAX;
    //asumming that x comes before y
    for(int i=0;i<n;i++)
    {
        if(a[i]==x){
            //find the distance from this till find the y
            int j,count=1;
            for(j=i+1;j<n;j++)
            {
                if(a[j]==y)
                    break;
                count++;
            }
            if(j!=n && minDist > count)
                minDist=count;

            // printf("#x->y %d\n",count);
        }
        else if(a[i]==y){
            //find the distance from this till find the y
            int j, count=1;
            for(j=i+1;j<n;j++)
            {
                if(a[j]==x)
                    break;
                count++;
            }
            if(j!=n && minDist > count)
                minDist=count;

            // printf("#y->x %d\n",count);
        }
        
    }
    printf("the distance between %d <-> %d = %d\n",x,y,minDist);
    free(a);
    remove(argv[0]);
    return 0;
}
