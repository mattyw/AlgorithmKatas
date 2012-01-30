#include <assert.h>
#include <string.h>
#include <stdlib.h>

void quicksort(int a[], int left_pos, int right_pos);
int partition(int a[], int left_pos, int right_pos);


static int compare_int(const void* x, const void* y) {
  //A useful function for comparing ints
  if (*(const int *) x > *(const int *)y) {
    return 1;
  }
  else if (*(const int *) x > *(const int *)y) {
    return -1;
  }
  else {
    return 0;
  }
}

int median_of_three_pivot(int a[], int left_pos, int right_pos) {
  /* quicksort's performance is dependant on the choice of a pivot. By using the median of three method we can 
     get almost average case run time no matter what the list
   */
  int r[3];

  r[0] = (rand() % (right_pos - left_pos + 1)) + left_pos;
  r[1] = (rand() % (right_pos - left_pos + 1)) + left_pos;
  r[2] = (rand() % (right_pos - left_pos + 1)) + left_pos;
  qsort(r, 3, sizeof(int), compare_int);
  return r[1]; //The median
}


void quicksort(int a[], int left_pos, int right_pos) {
  if (left_pos < right_pos) {
    int pi = partition(a, left_pos, right_pos);
    quicksort(a, left_pos, pi - 1);
    quicksort(a, pi + 1, right_pos);
  }
}

int partition(int a[], int left_pos, int right_pos) {
  int store, i;
  int pivot = median_of_three_pivot(a, left_pos, right_pos);
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

test_unsorted_list_size_ten() {
  int list_to_sort[10] = {6, 10, 3, 9, 5, 8, 2, 4, 1, 7};
  int expected[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  quicksort(list_to_sort, 0, 9);

  print_array(list_to_sort, 10);

  assert(memcmp(list_to_sort, expected, sizeof(int)*10) == 0);
}




int main() {
  test_empty_list();
  test_unsorted_list_size_one();
  test_unsorted_list_size_two();
  test_unsorted_list_size_ten();
}
