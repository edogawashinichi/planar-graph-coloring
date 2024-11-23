/// _test_digraph_searcher.cxx

#include "digraph_searcher.h"
#include "../basic/notation.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0)) 
  DigraphSearcher searcher;
  const size_t n = 8;
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {0, 2}, {3, 4}, {5, 6}
  };
  Digraph digraph(n, edges);
  DEBUG << "DIGRAPH:\n";
  if (PGC__DEBUG_MODE) digraph.show();
  DigraphSearcherResult result;
  searcher.dfs(digraph, &result);
  INFO << "RESULT:\n";
  result.show();
  bool res = (result.weakComponentSize() == 4);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1)) 
  DigraphSearcher searcher;
  const size_t n = 7;
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {0, 2}, {3, 4}, {5, 6}
  };
  Digraph digraph(n, edges);
  DEBUG << "DIGRAPH:\n";
  if (PGC__DEBUG_MODE) digraph.show();
  DigraphSearcherResult result;
  searcher.dijkstra(digraph, &result);
  INFO << "result:\n";
  result.getDirectedPathResult()->show();
  std::vector<std::vector<size_t>> exp = {
    {0},
    {0, 1},
    {0, 2},
    {1},
    {1, 2},
    {2},
    {3},
    {3, 4},
    {4},
    {5},
    {5, 6},
    {6}
  };
  dict_sort(exp);
  INFO << "expectation:\n";
  if (PGC__DEBUG_MODE || PGC__INFO_MODE) {
    for (size_t i = 0; i < exp.size(); ++i) {
      std::cout << i << "th: ";
      PGC__SHOW_VEC_WITH_ARROW(exp[i])
    }
  }
  bool res = (result.getDirectedPathResult()->getPathsInfo() == exp);
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

PGC__MAIN_START
  test_0();
  test_1();
PGC__MAIN_END
