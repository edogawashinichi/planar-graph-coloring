/// _test_acc_coloring_result.cxx

#include "acc_coloring_result.h"
#include "../topology/birkhoff_diamond.h"
#include "ring_coloring_result.h"
#include "colorer.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamond diamond;
  RingColoringResult colorings;
  Colorer colorer;
  colorer.run(diamond, &colorings);
  bool res = (colorings.size() == 732);
  colorings.show(std::cout, 20);
  AccColoringResult acc(colorings.copyBoundaryColoringResult());
  for (size_t i = 0; i < colorings.size(); ++i) {
    const int index = acc.find(colorings.constBoundaryColoring(i));
    DEBUG_2VAR(i, index)
    if (-1 == index) {
      res = false;
      break;
    }
    res = res && (index == static_cast<int>(i));
  }/// for
TEST_END(0)
/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
