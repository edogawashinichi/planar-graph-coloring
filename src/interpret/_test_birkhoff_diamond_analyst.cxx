/// _test_birkhoff_diamond_analyst.cxx

#include "birkhoff_diamond_analyst.h"
#include "classification_interpreter.h"
#include "../relation/birkhoff_diamond_relation_builder.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamondAnalyst analyst;
  RelationManager manager;
  BirkhoffDiamondRelationBuilder builder;
  builder.run(&manager);
  bool res = (manager.getColorResult()->size() == 732);
  res = res && (manager.getRelationResult()->size() == 18180);
  res = res && (manager.getMapper()->size() == 18180);
  res = res && (manager.getDigraphResult()->getVertexColor()->size() == 732);
  ClassificationInterpreter vertex_interpreter;
  analyst.reasonByVertex(manager, &vertex_interpreter);
  ClassificationInterpreter color_interpreter;
  analyst.reasonByColor(manager, &color_interpreter);
  ClassificationInterpreter vertex_color_interpreter;
  analyst.reasonByVertexColor(manager, &vertex_color_interpreter);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
