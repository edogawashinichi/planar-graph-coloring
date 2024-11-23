/// global.cxx

#include "global.h"

namespace PlanarGraphColoring {
  const size_t COLORS = 4;
  const size_t UNDEF_COLOR = 9;

  bool PGC__DEBUG_MODE = false;
  bool PGC__INFO_MODE = false;
  int PGC__PERIODIC_COLOR = 0;
  std::stack<int> PGC__COLOR_STACK;
}/// namespace PlanarGraphColoring
