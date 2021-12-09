/*WAP to read an array of integers and search for an element using linear search.*/
#include <stdio.h>
#include <stdlib.h>

int isPresent(int*arr, int n, int key){
  for (int i = 0; i < n; i++)
  {
    if(arr[i] == key)
      return 1;
  }
  return 0;
}

int main(int argc, char **argv) {

  int arr[] = {3, 6, 7, 1, 4};
  int size = sizeof(arr) / sizeof(int);
  printf("enter the key to search: ");
  int key;
  scanf("%d", &key);
  isPresent(arr, size, key) ? printf("Present\n") : printf("Not Present\n");
  remove(argv[0]);
  return EXIT_SUCCESS;
}