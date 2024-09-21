/// _test_color_transformer.cxx

#include "color_transformer.h"
#include "../basic/notation.h"
#include "naive_color_representation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  ColorTransformer ct;
  const std::vector<int> input = {0, 1, 0, 2, 0, 3};
  const NaiveColorRepresentation lhs(input);
  PGC__SHOW_ENDL("show lhs:")
  lhs.show();
  const std::vector<int> vertex_symmetry = {1, 2, 3, 4, 5, 0};
  NaiveColorRepresentation rhs;
  ct.transformByVertexSymmetry(vertex_symmetry, lhs, &rhs);
  PGC__SHOW_ENDL("show rhs:")
  rhs.show();
  const std::vector<int> output = {3, 0, 1, 0, 2, 0};
  const NaiveColorRepresentation exp(output);
  PGC__SHOW_ENDL("show exp:")
  exp.show();
  bool res = rhs.equal(exp);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  ColorTransformer ct;
  const std::vector<int> input = {0, 1, 0, 2, 0, 3};
  const NaiveColorRepresentation lhs(input);
  PGC__SHOW_ENDL("show lhs:")
  lhs.show();
  const std::vector<int> color_symmetry = {1, 3, 0, 2};
  NaiveColorRepresentation rhs;
  ct.transformByColorSymmetry(color_symmetry, lhs, &rhs);
  PGC__SHOW_ENDL("show rhs:")
  rhs.show();
  const std::vector<int> output = {1, 3, 1, 0, 1, 2};
  const NaiveColorRepresentation exp(output);
  PGC__SHOW_ENDL("show exp:")
  exp.show();
  bool res = rhs.equal(exp);
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

int main(int argc, char* argv[]) {
  test_0();
  test_1();
  return 0;
}
