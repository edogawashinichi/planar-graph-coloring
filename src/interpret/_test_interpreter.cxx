/// _test_interpreter.cxx

#include "interpreter.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  const std::vector<std::vector<size_t>> data = {
    {0, 1, 0, 1, 0, 1},
    {0, 1, 2, 3, 0, 1},
    {0, 1, 2, 3, 1, 2},
    {1, 2, 3, 0, 1, 2},
    {2, 3, 0, 1, 0, 1}
  };
  ColorResult table;
  for (const auto& vec : data) {
    DEBUG << "before table append\n";
    table.append(vec);
    DEBUG << "after table append\n";
  }
  INFO << "table.show:\n";
  table.show();
  Interpreter interpreter;
  const std::vector<size_t> heads = {0, 2, 4};
  for (const auto vertex : heads) {
    DEBUG << "before interpreter append\n";
    if (PGC__DEBUG_MODE) PGC__SHOW_VAR(vertex)
    interpreter.append(table, vertex);
    DEBUG << "after interpreter append\n";
  }
  INFO << "interpreter.show:\n";
  interpreter.show();
  interpreter.extend(table, 1);
  interpreter.extend(table, 3);
  INFO << "interpreter.show:\n";
  interpreter.show();
  bool res = (interpreter.size() == 3);
  INFO << "interpreter.show(2):\n";
  interpreter.show(2);
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

PGC__MAIN_START
  test_0();
PGC__MAIN_END
