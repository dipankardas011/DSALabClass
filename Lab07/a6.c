/*Given a sorted array of length n, WAP to find the number in array that appears more than or equal to n/2 times. It can be assumed that such element always exists. 
    Input:  2 3 3 4 Output: 3 
    Input:  3 4 5 5 5 Output: 5*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define MOD 47


typedef struct node{
    int value;// count of it
    int key;// element
    struct node *next;
} LL;


typedef struct tt{
    LL **hash;
    int size;
} HashMap;

LL* Insertion(LL* L, int value, int* maxCount){
    LL *tt = (LL *)malloc(sizeof(LL));
    assert(tt);
    tt->key = value;
    tt->value = 1;
    tt->next = NULL;

    if(!L){
        L = tt;
        return L;
    }

    LL *iter = L;
    while (iter->next && iter->key!=value)
        iter = iter->next;

    if(iter->key == value){
        (iter->value)++;
        free(tt);
        *maxCount = iter->value;
    }
    else{
        iter->next = tt;
        *maxCount = 1;
    }

    return L;
}

int pushKey(HashMap** hp, int key){
    int maxCount = 0;
    (*hp)->hash[key % MOD] = Insertion((*hp)->hash[key % MOD], key, &maxCount);
    return maxCount;
}

void display(HashMap* hp){
    printf("[ KEY ] : [ VALUE & FREQ ]\n");
    for (int i = 0; i < hp->size; i++){
        printf("%3d\t: ", i);
        LL *iter = hp->hash[i];
        do{
            if(!iter){
                break;
            }
            printf("{%d - %d}", iter->key, iter->value);
            iter = iter->next;
        } while (iter && printf(" -> "));
        printf("\n");
    }
}

int majorityElement(int* nums, int length) {
    HashMap *hp = NULL;
    hp = (HashMap *)malloc(sizeof(HashMap));
    hp->size = MOD;
    hp->hash = (LL **)malloc(sizeof(LL *) * MOD);

    for (int i = 0; i < MOD; i++)
        hp->hash[i] = NULL;

    int target = length >> 1;
    int resCount = -1;
    int resElement = -999;
    // initialized the hashmap
    for (int i = 0; i < length; i++) {
        int count = pushKey(&hp, nums[i]);
        if (count > resCount)
        {
            resElement = nums[i];
            resCount = count;
        }
    }
    // display(hp);

    return (resCount >= target) ? resElement : -1;
}

int main(int argc, char **argv) {
    int arr[] = {3, 4, 5, 5, 5, 52};
    int len = sizeof(arr) / sizeof(int);
    printf("Element Repeated Most: %d\n", majorityElement(arr, len));
    remove(argv[0]);
    return EXIT_SUCCESS;
}