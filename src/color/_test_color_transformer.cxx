/// _test_color_transformer.cxx

#include "color_transformer.h"
#include "../basic/notation.h"
#include "naive_color_representation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  ColorTransformer ct;
  const std::vector<size_t> input = {0, 1, 0, 2, 0, 3};
  const NaiveColorRepresentation lhs(input);
  PGC__SHOW_ENDL("show lhs:")
  lhs.show();
  const std::vector<size_t> vertex_symmetry = {1, 2, 3, 4, 5, 0};
  NaiveColorRepresentation rhs;
  ct.transformByVertexSymmetry(vertex_symmetry, lhs, &rhs);
  PGC__SHOW_ENDL("show rhs:")
  rhs.show();
  const std::vector<size_t> output = {3, 0, 1, 0, 2, 0};
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
  const std::vector<size_t> input = {0, 1, 0, 2, 0, 3};
  const NaiveColorRepresentation lhs(input);
  PGC__SHOW_ENDL("show lhs:")
  lhs.show();
  const std::vector<size_t> color_symmetry = {1, 3, 0, 2};
  NaiveColorRepresentation rhs;
  ct.transformByColorSymmetry(color_symmetry, lhs, &rhs);
  PGC__SHOW_ENDL("show rhs:")
  rhs.show();
  const std::vector<size_t> output = {1, 3, 1, 0, 1, 2};
  const NaiveColorRepresentation exp(output);
  PGC__SHOW_ENDL("show exp:")
  exp.show();
  bool res = rhs.equal(exp);
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

void test_2() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
  ColorTransformer ct;
  const std::vector<size_t> input = {0, 1, 0, 2, 0, 3};
  const NaiveColorRepresentation lhs(input);
  PGC__SHOW_ENDL("show lhs:")
  lhs.show();
  const std::vector<size_t> color_symmetry = {1, 3, 0, 2};
  const std::vector<size_t> exp_inverse = {2, 0, 3, 1};
  std::vector<size_t> inverse;
  ct.inverseColorSymmetry(color_symmetry, &inverse);
  PGC__SHOW_ENDL("inverse:")
  PGC__SHOW_VEC_WITH_INDEX(inverse)
  PGC__SHOW_ENDL("exp_inverse:")
  PGC__SHOW_VEC_WITH_INDEX(exp_inverse)
  bool res = (exp_inverse == inverse);
  NaiveColorRepresentation rhs;
  ct.transformByColorSymmetry(color_symmetry, lhs, &rhs);
  PGC__SHOW_ENDL("show rhs:")
  rhs.show();
  const std::vector<size_t> output = {1, 3, 1, 0, 1, 2};
  const NaiveColorRepresentation exp(output);
  PGC__SHOW_ENDL("show exp:")
  exp.show();
  res = res && rhs.equal(exp);
  NaiveColorRepresentation compound_input;
  ct.transformByColorSymmetry(inverse, exp, &compound_input);
  PGC__SHOW_ENDL("show compound_input:")
  compound_input.show();
  PGC__SHOW_ENDL("lhs show:")
  lhs.show();
  res = res && lhs.equal(compound_input);
  PGC__TEST_RESULT_INFO(res, 2)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
}/// test_2

int main(int argc, char* argv[]) {
  test_0();
  test_1();
  test_2();
  return 0;
}
