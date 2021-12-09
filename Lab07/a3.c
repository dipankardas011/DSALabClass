/*Given an array container and integer hunt. WAP to find whether hunt is present in container or not. If present, then triple the value of hunt and search again. Repeat these steps until hunt is not found. Finally return the value of hunt. 
    Input: container = {1, 2, 3} and hunt = 1 then Output: 9
    Explanation: Start with hunt = 1. Since it is present in array, it becomes 3. Now 3 is present in array and hence hunt becomes 9. Since 9 is a not present, program return 9.*/
#include <stdio.h>
#include <stdlib.h>

// assuming it is sorted

int isPresent(int* arr, int size, int start, int end, int hunt){
  if(end < start){
    return hunt;
  }

  int mid = start + (end - start) / 2;

  if(arr[mid] == hunt)
    return isPresent(arr, size, 0, size -1, hunt*3);

  if(arr[mid] > hunt)
    return isPresent(arr, size, start, mid - 1, hunt);
  
  return isPresent(arr, size,mid + 1, end, hunt);
}


int main(int argc, char **argv) {
  int arr[] = {1, 2, 3};
  int size = sizeof(arr) / sizeof(int);
  printf("enter the key to search: ");
  int key;
  scanf("%d", &key);
  int hh = isPresent(arr, size, 0, size - 1, key);
  printf("Hunt: %d\n", hh);
  remove(argv[0]);
  return EXIT_SUCCESS;
}