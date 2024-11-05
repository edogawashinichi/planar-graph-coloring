/// test_graph.cxx

#include "graph.h"
#include "../basic/notation.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0)) 
  const size_t n = 4;
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {2, 3}
  };
  Graph graph(n, edges);
  graph.show();
  bool res = true;
  const std::vector<std::vector<size_t>> neighbors = {
    {1}, {0, 2}, {1, 3}, {2}
  };
  for (size_t i = 0; i < n; ++i) {
    std::vector<size_t> neis = graph.getNeighbors(i);
    std::sort(neis.begin(), neis.end());
    if (neis != neighbors[i]) {
      std::cout << "getNeighbors(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      std::cout << "getNeighbors(" << i << ") passed!\n";
    }
  }/// for
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

int main(int argc, char* argv[]) {
  test_0();
  return 0;
}
