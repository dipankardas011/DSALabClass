/*WAP illustrating following collision resolution technique:
    * “Open Addressing – Linear Search”
    * “Open Addressing - Quadratic Probing” 
    * “Open Addressing - Double Hashing”.*/
#include <stdio.h>
#include <stdlib.h>

#define MOD 20
#define EMP -999
typedef struct type{
    int* arr;
    int size;
}HashMap;

void doubleHashing(){
    HashMap *hp = NULL;
    int ch;
    do{
        printf("Enter choices\n");
        printf("[ 1 ] insert\n");
        printf("[ 2 ] display\n");
        printf("[ 3 ] search\n> ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
        }
    } while (ch);

    free(hp->arr);
    free(hp);
}


void quadraticProbing(){
    HashMap *hp = NULL;
    int ch;
    do{
        printf("Enter choices\n");
        printf("[ 1 ] insert\n");
        printf("[ 2 ] display\n");
        printf("[ 3 ] search\n> ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:{
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                break;
            }
        }
    } while (ch);
    free(hp->arr);
    free(hp);
}


void linearSearch(){
    HashMap *hp = NULL;
    int ch;
    hp = (HashMap *)malloc(sizeof(HashMap));
    hp->size = MOD;
    hp->arr = (int *)malloc(sizeof(int) * hp->size);
    for (int i = 0; i < MOD; i++)
        hp->arr[i] = EMP;

    do{
        printf("Enter choices\n");
        printf("[ 1 ] insert\n");
        printf("[ 2 ] display\n");
        printf("[ 0 ] EXIT\n");
        scanf("%d", &ch);
        int key;
        switch(ch){
            case 1:{
                {
                    printf("Enter the value to insert: ");
                    scanf("%d", &key);
                    int org = key;
                    
                    do{
                        if(hp->arr[key % MOD] == EMP)
                            break;
                        key++; // if not found empty place we move to the next
                        if((key%MOD)==MOD)
                            key = 0;// cycle to form
                    } while (org != key && hp->arr[key % MOD] != EMP);
                    if (org == key && hp->arr[key % MOD] != EMP)
                    {
                        printf("No Empty place LEFT😐\n");
                        break;
                    }
                    hp->arr[key % MOD] = org;
                }
                break;
            }
            case 2:{
                {
                    // display
                    printf("[KEY] : [VALUE]\n");
                    for (int i = 0; i < hp->size; i++)
                        printf("[%3d] : %d\n", i, hp->arr[i]);
                }
                break;
            }

        }
    } while (ch);
    free(hp->arr);
    free(hp);
}

int main(int argc, char **argv)
{
    int choice;
    printf("Enter[]\n1 for linear\n2 Quadratic\n3 DoubleHashing\n> ");
    scanf("%d", &choice);

    if (choice == 1)
        linearSearch();
    else if (choice == 2)
        quadraticProbing();
    else if (choice == 3)
        doubleHashing();
    remove(argv[0]);
    return EXIT_SUCCESS;
}