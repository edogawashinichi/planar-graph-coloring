/// _test_coloring_group.cxx

#include "birkhoff_diamond_coloring_group.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamondColoringGroup G;
  INFO_OBJ(G)
  bool res = (G.size() == 4 * fact(COLORS.size()));
  for (size_t i = 0; i < G.size(); ++i) {
    const II& pair = G.transformIndex(i);
    auto vertex_permutation = G.constVertexPermutation(pair.first);
    auto color_permutation = G.constColorPermutation(pair.second);
    if (78 == i) {
      INFO_VAR(i)
      INFO_PAIR(pair)
      INFO_OBJ(vertex_permutation)
      INFO_OBJ(color_permutation)
    }/// if
  }/// for
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  BirkhoffDiamondColoringGroup G;
  INFO_OBJ(G)
  bool res = (G.size() == 4 * fact(COLORS.size()));
  for (size_t i = 0; i < G.size(); ++i) {
    const II& pair = G.transformIndex(i);
    auto vertex_permutation = G.constVertexPermutation(pair.first);
    auto color_permutation = G.constColorPermutation(pair.second);
    if (76 == i) {
      /*
        i == 76
        vertex symmetry group index: 3
        color symmetry group index: 4
        vertex permutation: (0 3)(1 2)(4 5)
        color permutation: (1 3 2)
        inverse vertex permutation: (0 3)(1 2)(4 5)
        inverse color permutation: inv(1 3 2)=(1 3 2)*(1 3 2)=(1 2 3)
        inverse vertex symmetry group index: 3
        inverse color symmetry group index: 3
        j == 24 * 3 + 3 = 75
      */
      INFO_VAR(i)
      INFO_PAIR(pair)
      INFO_OBJ(vertex_permutation)
      INFO_OBJ(color_permutation)
      const size_t j = G.inverse(i);
      INFO_VAR(j)
      res = res && (j == 75);
    }/// if
  }/// for
TEST_END(1)
/// test_1

PGC__MAIN_START
  TEST(0)
  TEST(1)
PGC__MAIN_END
