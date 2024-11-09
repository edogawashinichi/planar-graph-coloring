/// _test_digraph.cxx

#include "digraph.h"
#include "../basic/notation.h"
#include <algorithm>

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0)) 
  const size_t n = 4;
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {2, 3}
  };
  Digraph digraph(n, edges);
  digraph.show();
  bool res = true;
  const std::vector<std::vector<size_t>> predecessors = {
    {}, {0}, {1}, {2}
  };
  const std::vector<std::vector<size_t>> successors = {
    {1}, {2}, {3}, {}
  };
  for (size_t i = 0; i < n; ++i) {
    std::vector<size_t> preds = digraph.getPredecessors(i);
    std::sort(preds.begin(), preds.end());
    if (preds != predecessors[i]) {
      DEBUG << "getPredecessors(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      DEBUG << "getPredecessors(" << i << ") passed!\n";
    }
    std::vector<size_t> succs = digraph.getSuccessors(i);
    std::sort(succs.begin(), succs.end());
    if (succs != successors[i]) {
      DEBUG << "getSuccessors(" << i << ") failed!\n";
      res = false;
      break;
    } else {
      DEBUG << "getSuccessors(" << i << ") passed!\n";
    }
  }/// for
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
