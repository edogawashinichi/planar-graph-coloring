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
  VII EXP_INVERSE = {
    {0, 0},
    {1, 1},
    {28, 27},
    {26, 26},
    {2, 2},
    {3, 4},
    {29, 29},
    {24, 24},
    {4, 3},
    {5, 5},
    {27, 28},
    {25, 25},
    {6, 6},
    {7, 7},
    {34, 37},
    {32, 36},
    {35, 43},
    {8, 12},
    {9, 18},
    {30, 30},
    {33, 42},
    {10, 13},
    {11, 19},
    {31, 31},
    {40, 40},
    {12, 8},
    {13, 10},
    {38, 38},
    {41, 46},
    {14, 14},
    {15, 20},
    {36, 32},
    {39, 44},
    {37, 34},
    {16, 16},
    {17, 22},
    {46, 41},
    {44, 39},
    {18, 9},
    {19, 11},
    {47, 47},
    {42, 33},
    {20, 15},
    {21, 21},
    {45, 45},
    {43, 35},
    {22, 17},
    {23, 23},
    {80, 84},
    {70, 65},
    {82, 85},
    {64, 64},
    {86, 86},
    {68, 63},
    {58, 61},
    {88, 88},
    {62, 62},
    {92, 87},
    {56, 60},
    {94, 89},
    {74, 74},
    {71, 71},
    {76, 75},
    {65, 70},
    {84, 80},
    {66, 57},
    {52, 51},
    {89, 94},
    {60, 56},
    {90, 81},
    {50, 50},
    {95, 95},
    {72, 72},
    {69, 69},
    {77, 77},
    {59, 67},
    {78, 78},
    {67, 59},
    {53, 53},
    {83, 91},
    {54, 54},
    {91, 83},
    {48, 48},
    {93, 93},
    {73, 73},
    {63, 68},
    {75, 76},
    {57, 66},
    {79, 79},
    {61, 58},
    {51, 52},
    {81, 90},
    {55, 55},
    {85, 82},
    {49, 49},
    {87, 92}
  };
  dict_sort<size_t>(EXP_INVERSE);
  DEBUG_VII(EXP_INVERSE)
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
    const size_t j = G.inverse(i);
    res = res && (j == EXP_INVERSE[i].second);
    if (!res) {
      INFO_VAR(i)
      INFO_VAR(j)
      INFO_VAR(EXP_INVERSE[i].second)
      break;
    }
  }/// for
  INFO_VII(EXP_INVERSE)
  const bool sym = symmetry<size_t>(EXP_INVERSE);
  INFO_VAR(sym)
  res = res && sym;
TEST_END(1)
/// test_1

PGC__MAIN_START
  TEST(0)
  TEST(1)
PGC__MAIN_END
