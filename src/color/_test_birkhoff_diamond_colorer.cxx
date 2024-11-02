/// _test_birkhoff_diamond_colorer.cxx

#include "birkhoff_diamond_colorer.h"
#include "naive_color_representation.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  BirkhoffDiamond bd;
  const std::vector<size_t> colors = {0,1,0,1,0,2,UNDEF_COLOR,UNDEF_COLOR,UNDEF_COLOR,UNDEF_COLOR};
  NaiveColorRepresentation ncr(colors);
  ColorRepresentation* cr = &ncr;
  BirkhoffDiamondColorer bdc;
  bool res = bdc.colorInterior(bd, cr);
  cr->show();
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

void test_2() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
  BirkhoffDiamond bd;
  const std::vector<size_t> colors = {0,1,0,1,0,3,UNDEF_COLOR,UNDEF_COLOR,UNDEF_COLOR,UNDEF_COLOR};
  NaiveColorRepresentation ncr(colors);
  ColorRepresentation* cr = &ncr;
  BirkhoffDiamondColorer bdc;
  bool res = bdc.colorInterior(bd, cr);
  cr->show();
  PGC__TEST_RESULT_INFO(res, 2)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(2))
}/// test_2

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamond bd;
  ColorResult cr;
  BirkhoffDiamondColorer bdc;
  bdc.run(bd, &cr);
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

int main(int argc, char* argv[]) {
  test_0();
  //test_1();
  //test_2();
  return 0;
}
