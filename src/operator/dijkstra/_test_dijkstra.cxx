/// _test_dijkstra.cxx

#include "dijkstra.h"
#include "../../basic/notation.h"
#include "../../basic/math.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0)) 
  const size_t n = 9;
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {1, 5}, {2, 7}
  };
  Digraph digraph(n, edges);
  DEBUG << "DIGRAPH:\n";
  digraph.show();
  DirectedPath path;
  Dijkstra dijkstra;
  dijkstra.run(0, 8, digraph, &path);
  INFO << "result:\n";
  path.show();
  const std::vector<size_t> data = {0, 1, 2, 7, 8};
  const DirectedPath exp(data);
  INFO << "expected:\n";
  exp.show();
  bool res = (path.vertices_ == data);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1)) 
  const size_t n = 9;
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {1, 5}, {2, 7}
  };
  Digraph digraph(n, edges);
  DEBUG << "DIGRAPH:\n";
  digraph.show();
  DirectedPathResult paths;
  Dijkstra dijkstra;
  dijkstra.run(0, digraph, &paths);
  std::vector<std::vector<size_t>> result(paths.getPathsInfo());
  dict_sort(result);
  INFO << "result:\n";
  if (PGC__INFO_MODE) {
    PGC__SHOW_VVI_WITH_INDEX(result)
  }
  std::vector<std::vector<size_t>> exp = {
    {0},
    {0, 1},
    {0, 1, 2},
    {0, 1, 5},
    {0, 1, 2, 3},
    {0, 1, 2, 4},
    {0, 1, 2, 7},
    {0, 1, 5, 6},
    {0, 1, 2, 7, 8}
  };
  dict_sort(exp);
  INFO << "expectation:\n";
  if (PGC__DEBUG_MODE || PGC__INFO_MODE) {
    PGC__SHOW_VVI_WITH_INDEX(exp)
  }
  bool res = (result == exp);
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

void test_2() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2)) 
  //const size_t n = 9; /*seg fault*/
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {0, 7},
    {1, 2},
    {2, 3},
    {3, 4},
    {4, 5},
    {5, 6},
    {6, 0},
    {7, 8}, {7, 9},
    {8, 2}, {8, 4},
    {9, 5}, {9, 6}
  };
  Digraph digraph(edges);
  DEBUG << "DIGRAPH:\n";
  if (PGC__DEBUG_MODE) digraph.show();
  DirectedPathResult paths;
  Dijkstra dijkstra;
  dijkstra.run(0, digraph, &paths);
  INFO << "result:\n";
  if (PGC__DEBUG_MODE || PGC__INFO_MODE) {
    paths.show();
  }
  std::vector<std::vector<size_t>> exp = {
    {0},
    {0, 1},
    {0, 7},
    {0, 1, 2},
    {0, 7, 8},
    {0, 7, 9},
    {0, 1, 2, 3},
    {0, 7, 8, 4},
    {0, 7, 9, 5},
    {0, 7, 9, 6}
  };
  dict_sort(exp);
  INFO << "expectation:\n";
  if (PGC__DEBUG_MODE || PGC__INFO_MODE) {
    for (size_t i = 0; i < exp.size(); ++i) {
      std::cout << i << "th:  ";
      PGC__SHOW_VEC_WITH_ARROW(exp[i])
    }
  }
  bool res = (paths.getPathsInfo() == exp);
  PGC__TEST_RESULT_INFO(res, 2)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
}/// test_2

PGC__MAIN_START
  test_0();
  test_1();
  test_2();
PGC__MAIN_END
