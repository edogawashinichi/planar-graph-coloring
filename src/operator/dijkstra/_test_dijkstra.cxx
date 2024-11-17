/// _test_dijkstra.cxx

#include "dijkstra.h"
#include "../../basic/notation.h"

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
  std::cout << "result:\n";
  path.show();
  const std::vector<size_t> data = {0, 1, 2, 7, 8};
  const DirectedPath exp(data);
  std::cout << "expected:\n";
  exp.show();
  bool res = (path.vertices_ == data);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
