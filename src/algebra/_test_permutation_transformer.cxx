/// _test_permutation_transformer.cxx

#include "permutation_transformer.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  PermutationTransformer transformer;
  const VVI& generators = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2}
  };
  const auto& transformed = transformer.run(generators);
  bool res = (transformed.size() == generators.size());
  for (size_t i = 0; i < transformed.size(); ++i) {
    INFO << i << "th: ";
    INFO_OBJ(transformed[i])
  }
TEST_END(0)
/// test_0

PGC__MAIN_START
  TEST(0)
PGC__MAIN_END
