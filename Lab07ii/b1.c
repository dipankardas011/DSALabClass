/*WAP sort the n names in an alphabetical order.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_MAX_LEN 30

void display(char arr[][STR_MAX_LEN], int len){
    int i=0;
    printf("[");
    do{
        printf("'%s'", arr[i]);
        i++;
    } while (i < len && printf(", "));
    printf("]\n");
}

void alphabeticalSort(char arr[][STR_MAX_LEN], int len){
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if(strcmp(arr[j], arr[j+1]) > 0){
                // +1 in cpying allows to copy the NULL to dest from src
                char t[STR_MAX_LEN]={'\0'};
                strncpy(t, arr[j], strlen(arr[j])+1);
                strncpy(arr[j], arr[j + 1], strlen(arr[j + 1])+1);
                strncpy(arr[j + 1], t, strlen(t)+1);
            }
        }
    }
}

int main(int argc, char **argv) {
    int N;
    printf("Enter the number of user name inputs: ");
    scanf("%d", &N);
    // char arr[][STR_MAX_LEN] = {"da", "cd", "gde", "def"};
    // int len = sizeof(arr) / sizeof(char[STR_MAX_LEN]);
    char arr[N][STR_MAX_LEN];
    printf("Enter the names\n");
    for (int i = 0; i < N; i++)
    {
        fflush(stdin);
        scanf("%s", arr[i]);
    }

    display(arr, N);

    alphabeticalSort(arr, N);
    display(arr, N);

    remove(argv[0]);
    return EXIT_SUCCESS;
}