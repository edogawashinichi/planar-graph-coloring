/// _test_ring_classification_interpreter.cxx

#include "ring_classification_interpreter.h"

using namespace PlanarGraphColoring;

TEST_START(0)
  BirkhoffDiamondClassificationInterpreter interpreter;
  interpreter.show(std::cout, 123);
  bool res = true;
TEST_END(0)

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
