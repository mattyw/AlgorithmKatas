#include <stdio.h>
print_array(int* arr, int size) {
  int i;
  for(i = 0; i < size; i++) {
    printf("%d,", arr[i]);
  }
  printf("\n");
}

void swap(int* x, int* y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
