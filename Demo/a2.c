/*
+-----------------------+
| Dipankar Das 20051554 |
+-----------------------+
WAP to store max. 100 numbers into an array. Print all the elements that are three digit even
integers.*/
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 100

u_int16_t noOfDigits(int32_t n){
    int c=0;
    while(n){
        c++;
        n/=10;
    }
    return c;
}

int main(int argc, char const *argv[])
{
    int32_t arr[LENGTH]={0};
    for(u_int32_t i=0; i<10; i++){
        scanf("%d",arr+i);
    }
    for(u_int32_t i=0;i<10;i++)
    {
        if(noOfDigits(arr[i])==3 && !(arr[i]&1))
            printf("%d\n",arr[i]);
    }
    remove(argv[0]);
    return 0;
}
