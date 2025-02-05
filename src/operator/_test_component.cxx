/// _test_component.cxx

#include "component.h"
#include "../basic/notation.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  const VVI data = {
    {0, 2, 4},
    {1, 3},
    {5, 6, 7, 8}
  };
  Components components;
  for (const auto& vec : data) {
    components.append(vec.front());
    for (size_t i = 1; i < vec.size(); ++i) {
      components.extend(vec[i]);
    }
  }
  INFO << "RESULT:\n";
  INFO_OBJ(components)
  bool res = (data == components.getConst());
TEST_END(0)
/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
