#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void isort(int a[], int size) {
  int unsorted, sorted, value;
  for(unsorted = 1; unsorted < size; unsorted++) {
    value = a[unsorted];
    for (sorted = unsorted - 1; sorted >= 0; sorted--) {
      if (a[sorted] <= value) {
	break;
      }
      a[sorted + 1] = a[sorted];
    }
    a[sorted + 1] = value;
  }
}

test_empty_list() {
  int list_to_sort[0] = {};
  int expected[0] = {};

  isort(list_to_sort, 0);

  assert(memcmp(list_to_sort, expected, sizeof(int)*0) == 0);
}

test_unsorted_list_size_one() {
  int list_to_sort[1] = {1};
  int expected[1] = {1};

  isort(list_to_sort, 1);

  print_array(list_to_sort, 1);

  assert(memcmp(list_to_sort, expected, sizeof(int)*1) == 0);
}

test_unsorted_list_size_two() {
  int list_to_sort[2] = {2, 1};
  int expected[2] = {1, 2};

  isort(list_to_sort, 2);

  print_array(list_to_sort, 2);

  assert(memcmp(list_to_sort, expected, sizeof(int)*2) == 0);
}

test_unsorted_list_size_ten() {
  int list_to_sort[10] = {6, 10, 3, 9, 5, 8, 2, 4, 1, 7};
  int expected[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  isort(list_to_sort, 10);

  print_array(list_to_sort, 10);

  assert(memcmp(list_to_sort, expected, sizeof(int)*10) == 0);
}


print_array(int* arr, int size) {
  int i;
  for(i = 0; i < size; i++) {
    printf("%d,", arr[i]);
  }
  printf("\n");
}
  


int main() {
  test_empty_list();
  test_unsorted_list_size_one();
  test_unsorted_list_size_two();
  test_unsorted_list_size_ten();
}
