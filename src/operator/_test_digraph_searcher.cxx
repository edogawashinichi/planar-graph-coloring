/// _test_digraph_searcher.cxx

#include "digraph_searcher.h"
#include "../basic/notation.h"

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
  digraph.show();
  DigraphSearcherResult result;
  searcher.dfs(digraph, &result);
  DEBUG << "RESULT:\n";
  result.show();
  bool res = (result.weakComponentSize() == 4);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
