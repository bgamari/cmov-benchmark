#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include "fib.h"

void run(int n, int iters) {
  int64_t *a = new int64_t[n];
  int64_t *b = new int64_t[n];
  int64_t *dest = new int64_t[n];

  for (int i=0; i < n; i++) {
    a[i] = rand();
    b[i] = rand();
  }

  auto start = std::chrono::high_resolution_clock::now();
  for (int i=0; i < iters; i++) {
    fib(n, a, b, dest);
  }
  auto end = std::chrono::high_resolution_clock::now();
  assert(dest[0] == std::min(a[0], b[0]));
  std::chrono::duration<double> diff = end - start;
  std::cout << (diff.count() / iters) << "\n";
}

int main(int argc, char** argv) {
  int size = std::stoi(argv[1]);
  int iters = std::stoi(argv[1]);
  for (int i=0; i < 10; i++){
    run(size, iters);
  }
  return 0;
}
