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
  INFO_(obj)
  DEBUG_(obj)
  VERBOSE_(obj)
  bool res = (obj.find(1) != -1);
  res = res && (obj.find(0) != -1);
  res = res && (obj.find(2) != -1);
  res = res && (obj.find(3) == -1);
  obj.sort();
  INFO_(obj)
  res = res && (obj.getConst(0) == 0);
  res = res && (obj.getConst(4) == 2);
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  DimensionOneVector<size_t> obj;
  const VI data = {0, 1, 0, 2, 1};
  for (const auto& d : data) {
    obj.append(d);
  }/// for
  DimensionOneVector<size_t> sub(obj.getCopy(1, 3));
  INFO_(sub)
  DEBUG_(sub)
  VERBOSE_(sub)
  bool res = (sub.size() == 2);
  DimensionOneVector<size_t> test_set;
  test_set.set(obj.getCopy(2,5));
  INFO_(test_set)
  res = res && (test_set.size() == 3);
TEST_END(1)
/// test_1

PGC__MAIN_START
  TEST(0)
  TEST(1)
PGC__MAIN_END
