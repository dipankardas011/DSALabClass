/*Wap to find out if a Matrix is Sparse or not. ( Ask the user for a valid and invalid category of elements and calculate accordingly.)*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int m, n;
    printf("size.. ");
    scanf("%d %d",&m, &n);
    printf("Enter the invalid number: ");

    printf("enter 1 to even numbers 2 for odd numbers 3 for number\n");
    int ch;
    scanf("%d",&ch);
    int invCount=0, valCount=0;
    switch(ch){
        case 1:
        // int invCount=0, valCount=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int k;
                scanf("%d",&k);
                if(k%2==0)
                    invCount++;
                else
                    valCount++;
            }

        if(invCount > valCount)
            printf("Valid sparse matrix\n");
        else
            printf("Invalid sparse matrix\n");

        break;
        case 2:
        // int invCount=0, valCount=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int k;
                scanf("%d",&k);
                if(k&1)
                    invCount++;
                else
                    valCount++;
            }

        if(invCount > valCount)
            printf("Valid sparse matrix\n");
        else
            printf("Invalid sparse matrix\n");

        break;
        case 3:
        printf("enter the invalid: ");
        int inv;
        scanf("%d",&inv);
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                int k;
                scanf("%d",&k);
                if(k==inv)
                    invCount++;
                else
                    valCount++;
            }

        if(invCount > valCount)
            printf("Valid sparse matrix\n");
        else
            printf("Invalid sparse matrix\n");

        break;
    }
    // no. of invalid is more than the no of valid
    // free(mat);
    remove(argv[0]);
    return 0;
}
