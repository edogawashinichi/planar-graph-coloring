/// _test_digraph_searcher.cxx

#include "digraph_searcher.h"
#include "../basic/notation.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  DigraphSearcher searcher;
  const size_t n = 8;
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {0, 2}, {3, 4}, {5, 6}
  };
  Digraph digraph(n, edges);
  DEBUG_OBJ(digraph)
  DigraphSearcherResult result;
  searcher.dfs(digraph, &result);
  INFO_OBJ(result)
  bool res = (result.weakComponentSize() == 4);
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  DigraphSearcher searcher;
  const size_t n = 7;
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {0, 2}, {3, 4}, {5, 6}
  };
  Digraph digraph(n, edges);
  DEBUG_OBJ(digraph)
  DigraphSearcherResult result;
  searcher.dijkstra(digraph, &result);
  INFO_OBJ(*(result.getDirectedPathResult()))
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
      PGC__SHOW_VEC_WITH_ARROW(std::cout, exp[i])
    }
  }
  bool res = (result.getDirectedPathResult()->getPathsInfo() == exp);
TEST_END(1)
/// test_1

PGC__MAIN_START
  test_0();
  test_1();
PGC__MAIN_END
