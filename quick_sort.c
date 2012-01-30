#include <assert.h>


void quicksort(int a[], int size) {
}

test_empty_list() {
  int list_to_sort[0] = {};
  int expected[0] = {};

  quicksort(list_to_sort, 0);

  assert(memcmp(list_to_sort, expected, sizeof(int)*0) == 0);
}


int main() {
  test_empty_list();
}
