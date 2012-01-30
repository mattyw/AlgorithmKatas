#include <assert.h>
#include <string.h>
#include <stdlib.h>

void quicksort(int a[], int size) {
}

test_empty_list() {
  int list_to_sort[0] = {};
  int expected[0] = {};

  quicksort(list_to_sort, 0);

  assert(memcmp(list_to_sort, expected, sizeof(int)*0) == 0);
}

test_unsorted_list_size_one() {
  int list_to_sort[1] = {1};
  int expected[1] = {1};

  quicksort(list_to_sort, 1);

  print_array(list_to_sort, 1);

  assert(memcmp(list_to_sort, expected, sizeof(int)*1) == 0);
}

test_unsorted_list_size_two() {
  int list_to_sort[2] = {2, 1};
  int expected[2] = {1, 2};

  quicksort(list_to_sort, 2);

  print_array(list_to_sort, 2);

  assert(memcmp(list_to_sort, expected, sizeof(int)*2) == 0);
}



int main() {
  test_empty_list();
  test_unsorted_list_size_one();
  test_unsorted_list_size_two();
}
