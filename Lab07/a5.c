/*WAP illustrating following collision resolution technique:
    * “Open Addressing – Linear Search”
    * “Open Addressing - Quadratic Probing” 
    * “Open Addressing - Double Hashing”.*/
#include <stdio.h>
#include <stdlib.h>

#define EMP -999
typedef struct type{
    int* arr;
    int size;
}HashMap;

void doubleHashing(){
    const int MOD = 20;
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
        scanf("%d", &ch);
        
        switch(ch){
            case 1:{
                break;
            }
            case 2:{
                break;
            }
        }
    } while (ch);

    free(hp->arr);
    free(hp);
}


void quadraticProbing(){
    const int MOD = 7;
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
        printf("[ 0 ] EXIT\n> ");
        scanf("%d", &ch);
        int key;
        switch(ch){
            case 1:{
                {
                    printf("Enter the value to insert: ");
                    scanf("%d", &key);
                    int orgHash = key % MOD;
                    int hashVal = key % MOD;
                    // perfect squares
                    int increment = 1;

                    do{
                        printf("hash: %d\n", hashVal);
                        if (hp->arr[hashVal] == EMP)
                            break;
                        hashVal = (orgHash+(increment))%MOD; // if not found empty place we move to the next
                        increment += 3;
                        printf("hash: %d\n", hashVal);
                    } while (orgHash != hashVal && hp->arr[hashVal] != EMP);

                    if (orgHash == hashVal && hp->arr[key % MOD] != EMP) {
                        printf("No Empty place LEFT😐\n");
                        break;
                    }
                    hp->arr[hashVal] = key;
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


void linearSearch(){
    const int MOD = 20;
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
        printf("[ 0 ] EXIT\n> ");
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