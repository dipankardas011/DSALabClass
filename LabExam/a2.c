/*WAP to add two polynomials using linked lists.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct nn{
    int data;
    int power;
    struct nn *next;
} poly;

poly* createNode(poly* head, int d, int pow){
    poly *temp = (poly *)malloc(sizeof(poly));
    temp->data = d;
    temp->power = pow;
    temp->next = NULL;

    if(!head){
        head = temp;
    } else {
        poly *iter = head;
        while(iter->next)
            iter = iter->next;
        iter->next = temp;
    }
    return head;
}

void displayPoly(poly* head){
    printf("Poly: ");
    if(!head){
        printf("Empty!\n");
        return;
    }

    while(head){
        if(head->data > 0){
            printf("+%dx^%d ", head->data, head->power);
        } else {
            printf("%dx^%d ", head->data, head->power);
        }
        head = head->next;
    }
    printf("\n\n");
}

void addition(poly* poly1, poly* poly2){
    poly *addPoly = NULL;
    while(poly1 && poly2){

        if(poly1->power < poly2->power){
            addPoly = createNode(addPoly, poly1->data, poly1->power);
            poly1 = poly1->next;

        } else if(poly1->power > poly2->power){
            addPoly = createNode(addPoly, poly2->data, poly2->power);
            poly2 = poly2->next;

        } else{
            addPoly = createNode(addPoly, (poly1->data + poly2->data), poly1->power);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while(poly1){
        addPoly = createNode(addPoly, poly1->data, poly1->power);
        poly1 = poly1->next;
    }

    while(poly2){
        addPoly = createNode(addPoly, poly2->data, poly2->power);
        poly2 = poly2->next;
    }

    displayPoly(addPoly);
}

int main(int argc, char **argv)
{
    poly *poly1 = NULL;
    poly *poly2 = NULL;

    int ch;
    do{
        printf("Enter the polynomial 1 according the ascending order power example\n");
        int power, dat;
        printf("Enter the data, power: ");
        scanf("%d %d", &dat, &power);
        poly1 = createNode(poly1, dat, power);
        printf("++++++ Enter 0 to exit ");
        scanf("%d", &ch);
    } while (ch);
    printf("\n");
    do
    {
        printf("Enter the polynomial 2 according the ascending order power\n");
        int power, dat;
        printf("Enter the data, power: ");
        scanf("%d %d", &dat, &power);
        poly2 = createNode(poly2, dat, power);
        printf("++++++ Enter 0 to exit");
        scanf("%d", &ch);
    } while (ch);

    displayPoly(poly1);
    displayPoly(poly2);

    addition(poly1, poly2);

    remove(argv[0]);
    return EXIT_SUCCESS;
}