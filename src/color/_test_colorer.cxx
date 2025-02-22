/// _test_colorer.cxx

#include "colorer.h"
#include "../topology/birkhoff_diamond.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamond diamond;
  const VI boundary_coloring_data = {
    0, 1, 0, 1, 0, 2
  };
  RingColoring coloring(diamond.boundarySize(), diamond.interiorSize());
  coloring.getBoundaryColoring().set(boundary_coloring_data);
  bool res = Colorer::getInstance().colorInterior(diamond, &coloring);
  INFO_(coloring)
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  BirkhoffDiamond diamond;
  RingColoringResult colorings;
  Colorer::getInstance().run(diamond, &colorings);
  bool res = (colorings.size() == 732);
  colorings.show(std::cout, 20);
  INFO_VAR(colorings.size())
TEST_END(1)
/// test_1

PGC__MAIN_START
  test_0();
  test_1();
PGC__MAIN_END
