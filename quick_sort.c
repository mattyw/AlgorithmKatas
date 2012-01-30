#include <assert.h>
#include <string.h>
#include <stdlib.h>

void quicksort(int a[], int left_pos, int right_pos);
int partition(int a[], int left_pos, int right_pos);

void quicksort(int a[], int left_pos, int right_pos) {
  if (left_pos < right_pos) {
    int pi = partition(a, left_pos, right_pos);
    quicksort(a, left_pos, pi - 1);
    quicksort(a, pi + 1, right_pos);
  }
}

int partition(int a[], int left_pos, int right_pos) {
  int store, i;
  int pivot = (right_pos + left_pos) / 2;
  swap(&a[pivot], &a[right_pos]);
  store = left_pos;
  for (i = left_pos; i < right_pos; i++) {
    if (a[i] <= a[right_pos]) {
      swap(&a[i], &a[store]);
      store++;
    }
  }
  swap(&a[store], &a[right_pos]);
  return store;
}

test_empty_list() {
  int list_to_sort[0] = {};
  int expected[0] = {};

  quicksort(list_to_sort, 0, 0);

  assert(memcmp(list_to_sort, expected, sizeof(int)*0) == 0);
}

test_unsorted_list_size_one() {
  int list_to_sort[1] = {1};
  int expected[1] = {1};

  quicksort(list_to_sort, 0, 0);

  print_array(list_to_sort, 1);

  assert(memcmp(list_to_sort, expected, sizeof(int)*1) == 0);
}

test_unsorted_list_size_two() {
  int list_to_sort[2] = {2, 1};
  int expected[2] = {1, 2};

  quicksort(list_to_sort, 0, 1);

  print_array(list_to_sort, 2);

  assert(memcmp(list_to_sort, expected, sizeof(int)*2) == 0);
}



int main() {
  test_empty_list();
  test_unsorted_list_size_one();
  test_unsorted_list_size_two();
}
