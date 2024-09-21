/// _test_birkhoff_diamond_color_judger.cxx

#include "birkhoff_diamond_color_judger.h"
#include "naive_color_representation.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamondColorJudger bdcj;
  const std::vector<int> l0 = {0, 1, 2, 3, 0, 1};
  const std::vector<int> r0 = {3, 2, 1, 0, 1, 0};
  const NaiveColorRepresentation lhs0(l0);
  const NaiveColorRepresentation rhs0(r0);
  bool res = (true == bdcj.isIsomorphismByVertexSymmetry(lhs0, rhs0));
  const std::vector<int> l1 = {0, 1, 2, 3, 0, 1};
  const std::vector<int> r1 = {3, 2, 1, 0, 0, 1};
  const NaiveColorRepresentation lhs1(l1);
  const NaiveColorRepresentation rhs1(r1);
  res = res && (false == bdcj.isIsomorphismByVertexSymmetry(lhs1, rhs1));
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  BirkhoffDiamondColorJudger bdcj;
  const std::vector<int> l0 = {0, 1, 2, 3, 0, 1};
  const std::vector<int> r0 = {3, 2, 0, 1, 3, 2};
  const NaiveColorRepresentation lhs0(l0);
  const NaiveColorRepresentation rhs0(r0);
  bool res = (true == bdcj.isIsomorphismByColorSymmetry(lhs0, rhs0));
  const std::vector<int> l1 = {0, 1, 2, 3, 0, 1};
  const std::vector<int> r1 = {3, 2, 1, 0, 0, 1};
  const NaiveColorRepresentation lhs1(l1);
  const NaiveColorRepresentation rhs1(r1);
  res = res && (false == bdcj.isIsomorphismByColorSymmetry(lhs1, rhs1));
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

int main(int argc, char* argv[]) {
  test_0();
  test_1();
  return 0;
}
