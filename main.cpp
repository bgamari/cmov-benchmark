#include <cstdint>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include "fib.h"

void run() {
  int n = 4000;
  int64_t *a = new int64_t[n];
  int64_t *b = new int64_t[n];
  int64_t *dest = new int64_t[n];

  for (int i=0; i < n; i++) {
    a[i] = rand();
    b[i] = rand();
  }

  auto start = std::chrono::high_resolution_clock::now();
  for (int i=0; i < 1000000; i++) {
    fib(n, a, b, dest);
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end - start;
  std::cout << diff.count() << "\n";
}

int main() {
  for (int i=0; i < 10; i++){
    run();
  }
  return 0;
}
