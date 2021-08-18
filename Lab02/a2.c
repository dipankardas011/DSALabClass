/*WAP to add two distances (in km-meter) by passing structure to a function.*/
#include <stdio.h>
#include <stdlib.h>

struct distance{
    float d;
};

float addDistance(struct distance* d1, struct distance* d2)
{
    return d1->d+d2->d;
}

int main(int argc, char const *argv[])
{
    struct distance d1,d2;
    printf("enter distance1: ");
    scanf("%f",&d1.d);

    printf("enter distance2: ");
    scanf("%f",&d2.d);

    printf("Summation of 2 distances = %.2f Km\n",addDistance(&d1, &d2));
    remove(argv[0]);
    return 0;
}
