/// _test_dijkstra.cxx

#include "dijkstra.h"
#include "../../basic/notation.h"
#include "../../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  const size_t n = 9;
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {1, 5}, {2, 7}
  };
  Digraph digraph(n, edges);
  DEBUG_OBJ(digraph)
  DirectedPath path;
  Dijkstra dijkstra;
  dijkstra.run(0, 8, digraph, &path);
  INFO_OBJ(path)
  const std::vector<size_t> data = {0, 1, 2, 7, 8};
  const DirectedPath exp(data);
  INFO_OBJ(exp)
  bool res = (path.vertices_ == data);
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  const size_t n = 9;
  const std::vector<std::vector<size_t>> edges = {
    {0, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {1, 5}, {2, 7}
  };
  Digraph digraph(n, edges);
  DEBUG_OBJ(digraph)
  DirectedPathResult paths;
  Dijkstra dijkstra;
  dijkstra.run(0, digraph, &paths);
  std::vector<std::vector<size_t>> result(paths.getPathsInfo());
  dict_sort(result);
  INFO << "result:\n";
  if (PGC__INFO_MODE) {
    PGC__SHOW_VVI_WITH_INDEX(std::cout, result)
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
    PGC__SHOW_VVI_WITH_INDEX(std::cout, exp)
  }
  bool res = (result == exp);
TEST_END(1)
/// test_1

/// test_2
TEST_START(2)
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
  DEBUG_OBJ(digraph)
  DirectedPathResult paths;
  Dijkstra dijkstra;
  dijkstra.run(0, digraph, &paths);
  INFO << "result:\n";
  INFO_OBJ(paths)
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
      PGC__SHOW_VEC_WITH_ARROW(std::cout, exp[i])
    }
  }
  bool res = (paths.getPathsInfo() == exp);
TEST_END(2)
/// test_2

PGC__MAIN_START
  test_0();
  test_1();
  test_2();
PGC__MAIN_END
