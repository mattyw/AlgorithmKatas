#include <stdio.h>
print_array(int* arr, int size) {
  int i;
  for(i = 0; i < size; i++) {
    printf("%d,", arr[i]);
  }
  printf("\n");
}
