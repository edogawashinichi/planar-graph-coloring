/// test_dimension_one_vector.cxx

#include "dimension_one_vector.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  DimensionOneVector<size_t> obj;
  const VI data = {0, 1, 0, 2, 1};
  for (const auto& d : data) {
    obj.append(d);
  }/// for
  INFO_OBJ(obj)
  bool res = (obj.find(1) != -1);
  res = res && (obj.find(0) != -1);
  res = res && (obj.find(2) != -1);
  res = res && (obj.find(3) == -1);
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
