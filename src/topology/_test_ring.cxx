/// test_ring.cxx

#include "ring.h"
#include "../basic/notation.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  const size_t k = 4; /// boundary size
  const size_t n = 5; /// total
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 1}, {4, 3}
  };
  Ring ring(k, n, edges);
  ring.show();
  bool res = true;
  const std::vector<std::vector<size_t>> neighbors = {
    {1, 3}, {0, 2, 4}, {1, 3}, {0, 2, 4}, {1, 3}
  };
  for (size_t i = 0; i < n; ++i) {
    std::vector<size_t> neis = ring.getNeighbors(i);
    std::sort(neis.begin(), neis.end());
    if (neis != neighbors[i]) {
      std::cout << "neis:\n";
      PGC__SHOW_VEC(neis)
      std::cout << "neighbors[i]:\n";
      PGC__SHOW_VEC(neighbors[i])
      std::cout << "getNeighbors(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      std::cout << "getNeighbors(" << i << ") passed!\n";
    }
  }/// for
  if (res) {
    PGC__SHOW_ENDL(PGC__TEST_PASS_INFO(0))
  } else {
    PGC__SHOW_ENDL(PGC__TEST_FAIL_INFO(0))
  }
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

int main(int argc, char* argv[]) {
  test_0();
  return 0;
}
