/*WAP illustrating the usage of “Hash Functions” namely Folding, Mid-square, Division, Subtraction, Digit extraction and Rotation Hashing methods.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define EMP -999
typedef struct type{
    int* arr;
    int size;
}HashMap;


int hash1(int key){
    key *= key;
    int noOfDigits = (int)log10(key) + 1;
    int mid;
    
    if (noOfDigits %2==0)
        // even
        mid = (key / (int)pow(10, (noOfDigits / 2) - 1)) % 100;

    else
        mid = (key / (int)pow(10, noOfDigits / 2)) % 10;


    const int MOD = 11;
    return mid % MOD;
}

int hash2(int key){
    int sum = 0;
    const int MOD = 11;
    int N = key;
    while(N>0){
        sum += N % 100;
        N /= 100;
    }
    return sum % MOD;
}


int hash3(int key){
    const int MOD = 11;
    // last 3 digits are considerd
    // like the roll number of students
    /**
     * 20051554
     * 2005155.
     * 20051...
     */
    return (key % 1000) % MOD;
}

int hash4(int key){
    /**
     * 600101
     * 600102
     * 600103
     * 👇
     * 160010
     * 260010
     * 360010
     */
    const int MOD = 11;
    int noOfDigits = (int)log10(key) + 1;

    int okey = key / 10;
    printf("Digit: %d\n",(key%10)*(int)pow(10,noOfDigits-1) + okey);
    return ((key % 10) * (int)pow(10, noOfDigits-1) + okey) % MOD;
}

void MidSquare(){

    const int MOD = 11;
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
                    // 123567
                    // 10^len/2 - 1
                    // 35

                    // 1234567
                    // 4

                    printf("Enter the value to insert: ");
                    scanf("%d", &key);

                    int hashKey = hash1(key);

                    hp->arr[hashKey] = key;
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

void divisionMethod(){

    const int MOD = 10;
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

                    int hashKey = key % hp->size;

                    hp->arr[hashKey] = key;
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

void subtractionMethod(){
// ascii characters in a string
    const int MOD = 26;
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
        char key;
        switch(ch){
            case 1:{
                {
                    fflush(stdin);
                    printf("Enter the value to insert: ");
                    scanf(" %c", &key);
                    key = tolower(key);

                    int hashKey = key - 'a';

                    hp->arr[hashKey] = key;
                }
                break;
            }
            case 2:{
                {
                    // display
                    printf("[KEY] : [VALUE]\n");
                    for (int i = 0; i < hp->size; i++)
                        printf("[%3d] : %c\n", i, hp->arr[i]);
                }
                break;
            }
        }
    } while (ch);

    free(hp->arr);
    free(hp);
}

void rotateMethod(){
    const int MOD = 11;
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

                    int hashKey = hash4(key);

                    hp->arr[hashKey] = key;
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

void digitExtraction(){
    const int MOD = 11;
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

                    int hashKey = hash3(key);

                    hp->arr[hashKey] = key;
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

void foldingMethod(){
    const int MOD = 11;
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
                    // 436-555-4601
                    int hashKey = hash2(key);

                    hp->arr[hashKey] = key;
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

int main(int argc, char **argv) {
    int ch;
    printf("Enter \n1 to midSquare\n2 division\n3 subtraction\n4 digit extraction\n5 folding method\n6 rotation method\n> ");
    scanf("%d", &ch);
    switch(ch){
        case 1:
            MidSquare();
            break;

        case 2:
            divisionMethod();
            break;

        case 3:
            subtractionMethod();
            break;

        case 4:
            digitExtraction();
            break;

        case 5:
            foldingMethod();
            break;

        case 6:
            rotateMethod();
            break;

        default:
            fprintf(stderr, "^~~~ INVALID choice\n");
    }
    remove(argv[0]);
    return EXIT_SUCCESS;
}