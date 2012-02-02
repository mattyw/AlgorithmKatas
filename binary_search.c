#include <assert.h>
#include <stdio.h>

int binary_search(int a[], int length, int term) {
  int low = 0;
  int high = length - 1;
  while (low <= high) {
    int ix = (low + high)/2;
    if (term == a[ix]) {
      return 1;
    }
    else if (term < a[ix]) {
      high = ix - 1;
    }
    else {
      low = ix + 1;
    }
  }
  return 0;    
}

void test_empty_list() {
  int list[0] = {};
  int term = 5;

  assert(binary_search(list, 0, term) == 0);
}

void test_not_in_list() {
  int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int term = 11;

  assert(binary_search(list, 10, term) == 0);
}

void test_in_list() {
  int list[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int term = 5;

  assert(binary_search(list, 10, term) == 1);
}




int main() {
  test_empty_list();
  test_not_in_list();
  test_in_list();
}
