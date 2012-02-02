#include <assert.h>

int binary_search(int a[], int term) {
  int low = 0;
  int high = sizeof(a)/sizeof(int);
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

  assert(binary_search(list, term) == 0);
}



int main() {
  test_empty_list();
}
