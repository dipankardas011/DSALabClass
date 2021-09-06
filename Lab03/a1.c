/*WAP to create a linked list that represents a polynomial expression with double variables (e.g.: 
4x^2y^3-3xy+x-5y+7) and display the polynomial by using user defined functions for creation and display.*/
#include <stdio.h>
#include <stdlib.h>

struct Poly{
    int coeff;
    int powX, powY;

    struct Poly *next;
};

struct Poly* insert(struct Poly* head){
    
    struct Poly *temp = (struct Poly*)malloc(sizeof(struct Poly));
    printf("Enter the data, coeff of X and Y: ");
    scanf("%d %d %d",&temp->coeff, &temp->powX, &temp->powY);
    temp->next = 0;
    if(!head){
        head = temp;
        return head;
    }
    struct Poly* t=head;
    while(t->next)  t=t->next;

    t->next = temp;
    
    return head;
}

void display(struct Poly* head){
    while(head){
        if(head->coeff>0){
            printf("+%d",head->coeff);
            if(head->powX)
                printf("X^%d",head->powX);
            if(head->powY)
                printf("Y^%d",head->powY);
        }else{
            printf("%d",head->coeff);
            if(head->powX)
                printf("X^%d",head->powX);
            if(head->powY)
                printf("Y^%d",head->powY);
        }
        printf(" ");
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    struct Poly *poly = 0;
    int ch;
    do{
        poly = insert(poly);
        printf("Enter 0 To STOP input: ");
        scanf("%d",&ch);
    }while(ch);

    display(poly);
    remove(argv[0]);
    return 0;
}
