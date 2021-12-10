/*WAP illustrating chain hashing (Separate chaining with linked list).*/
#include <stdio.h>
#include <stdlib.h>

#define MOD 11
struct nodes
{
    int data;
    struct nodes *next;
};

typedef struct HM
{
    struct nodes **cells;
    size_t size;
    // using mod method
} HashMap;

struct nodes* Insertion(struct nodes* LL, int value){
    struct nodes *tt = (struct nodes *)malloc(sizeof(struct nodes));
    tt->data = value;
    tt->next = NULL;

    if(!LL){
        LL = tt;
        return LL;
    }

    struct nodes *iter = LL;
    while (iter->next)
        iter = iter->next;

    iter->next = tt;
    return LL;
}

HashMap *insertKey(HashMap *hp, int value) 
{
    if (!hp) {
        // create the node
        hp = (HashMap *)malloc(sizeof(HashMap));
        hp->size = MOD;
        hp->cells = (struct nodes **)malloc(sizeof(struct nodes*) * MOD);
        for (size_t i = 0; i < hp->size; i++) {
            hp->cells[i] = NULL;
        }
    }

    hp->cells[value % (hp->size)] = Insertion(hp->cells[value % (hp->size)], value);
    return hp;
}

void display(HashMap* hp){
    printf("[ KEY ] : [ VALUE ]\n");
    for (size_t i = 0; i < hp->size; i++){
        printf("%3ld\t: ", i);
        struct nodes *iter = hp->cells[i];
        do{
            if(!iter){
                break;
            }
            printf("%d", iter->data);
            iter = iter->next;
        } while (iter && printf(" -> "));
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    HashMap *hashMap = NULL;
    int ch;
    do{
        printf("[ 1 ] to insert\n");
        printf("[ 2 ] to display\n");
        printf("[ 0 ] to EXIT\n> ");
        scanf("%d", &ch);
        int value;
        switch(ch){
            case 1:{
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                hashMap = insertKey(hashMap, value);
                break;
            }
            case 2:{
                printf("Contents of HashMap\n");
                display(hashMap);
                break;
            }
        }
    } while (ch);
    remove(argv[0]);
    return EXIT_SUCCESS;
}