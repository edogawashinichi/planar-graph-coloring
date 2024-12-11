/// global.h

#pragma once

#include <stack>

namespace PlanarGraphColoring {
  /* const */
  extern const size_t COLORS;
  extern const size_t UNDEF_COLOR;
  extern const size_t UNDEF_VERTEX;

  /* random */
  extern unsigned int PGC__HISTORY_SEED;

  /* show in terminal */
  extern bool PGC__VERBOSE_MODE;
  extern bool PGC__DEBUG_MODE;
  extern bool PGC__INFO_MODE;
  extern int PGC__PERIODIC_COLOR;
  extern std::stack<int> PGC__COLOR_STACK;
}/// namespace PlanarGraphColoring
