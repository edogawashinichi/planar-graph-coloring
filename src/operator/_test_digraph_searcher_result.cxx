/// _test_digraph_searcher_result.cxx

#include "digraph_searcher_result.h"
#include "../basic/notation.h"
#include <algorithm>

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0)) 
  DigraphSearcherResult result;
  result.appendWeakComponent(0);
  result.appendWeakComponent(1);
  result.extendWeakComponent(2);
  bool res = (result.weakComponentSize() == 2);
  result.appendWeakComponent(3);
  result.extendWeakComponent(4);
  result.extendWeakComponent(5);
  result.show();
  res = res && (result.weakComponentSize() == 3);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
