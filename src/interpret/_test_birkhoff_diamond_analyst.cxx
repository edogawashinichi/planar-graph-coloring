/// _test_birkhoff_diamond_analyst.cxx

#include "birkhoff_diamond_analyst.h"
#include "classification_interpreter.h"
#include "routing_interpreter.h"
#include "../color/birkhoff_diamond_color_judger.h"
#include "../relation/birkhoff_diamond_relation_builder.h"
#include "../basic/notation.h"
#include "../basic/random.h"

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
  /*
  ClassificationInterpreter vertex_interpreter;
  analyst.reasonByVertex(manager, &vertex_interpreter);
  ClassificationInterpreter color_interpreter;
  analyst.reasonByColor(manager, &color_interpreter);
  */
  ClassificationInterpreter vertex_color_interpreter;
  analyst.reasonByVertexColor(manager, &vertex_color_interpreter);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

void test_1() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
  RelationManager manager;
  BirkhoffDiamondRelationBuilder builder;
  builder.run(&manager);
  BirkhoffDiamondColorJudger judger;
  BirkhoffDiamondAnalyst analyst;
  ClassificationInterpreter classification_interpreter;
  analyst.reasonByVertexColor(manager, &classification_interpreter);
  for (size_t i = 0; i < classification_interpreter.size(); ++i) {
    INFO_VAR(i)
    auto representative = classification_interpreter.getConst(i).getConst(0);
    if (judger.isValid(*representative)) {
      INFO << "valid class need no kempe!\n";
      continue;
    }
    INFO << "invalid class need kempe!\n";
    //INFO_OBJ(classification_interpreter.getConst(i))
    const VI pair(randomChoose(classification_interpreter.getConst(i).size(), 2));
    INFO_VEC(pair)
    RoutingInterpreter routing_interpreter;
    analyst.reasonByVertexColor(manager, classification_interpreter, i, pair.front(), pair.back(), &routing_interpreter);
    routing_interpreter.show();
  }/// for i
  bool res = true;
  PGC__TEST_RESULT_INFO(res, 1)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(1))
}/// test_1

PGC__MAIN_START
  //test_0();
  test_1();
PGC__MAIN_END
