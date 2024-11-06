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
      DEBUG << "neis:\n";
      PGC__SHOW_VEC(neis)
      DEBUG << "neighbors[i]:\n";
      PGC__SHOW_VEC(neighbors[i])
      DEBUG << "getNeighbors(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      DEBUG << "getNeighbors(" << i << ") passed!\n";
    }
  }/// for
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
