#include "fib.h"

extern "C"
int64_t fib(int n, const int64_t *x, int64_t *y, int64_t *dest) {
  for (int i=0; i < n; i++) {
    int64_t a = x[i];
    int64_t b = y[i];
    dest[i] = a < b ? a : b;
  }
}

