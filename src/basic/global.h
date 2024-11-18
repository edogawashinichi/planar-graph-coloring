/// global.h

#pragma once

#include <stack>

namespace PlanarGraphColoring {
  extern bool PGC__DEBUG_MODE;
  extern bool PGC__INFO_MODE;
  extern int PGC__PERIODIC_COLOR;
  extern std::stack<int> PGC__COLOR_STACK;
}/// namespace PlanarGraphColoring
