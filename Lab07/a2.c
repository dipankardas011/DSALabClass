/*WAP to read an array of integers and search for an element using binary search.*/
#include <stdio.h>
#include <stdlib.h>

int isPresent(int* arr, int start, int end, int skey){
  if(end < start){
    return 0;
  }

  int mid = start + (end - start) / 2;

  if(arr[mid] == skey)
    return 1;

  if(arr[mid] > skey)
    return isPresent(arr, start, mid - 1, skey);
  
  return isPresent(arr, mid + 1, end, skey);
}

int main(int argc, char **argv) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 10};
  int size = sizeof(arr) / sizeof(int);
  printf("enter the key to search: ");
  int key;
  scanf("%d", &key);
  isPresent(arr, 0, size-1, key) ? printf("Present\n") : printf("Not Present\n");
  remove(argv[0]);
  return EXIT_SUCCESS;
}