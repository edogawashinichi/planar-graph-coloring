/// global.h

#pragma once

#include <stack>

namespace PlanarGraphColoring {
  /* color */
  extern const size_t COLORS;
  extern const size_t UNDEF_COLOR;
  extern const size_t UNDEF_VERTEX;

  /* topoloty */
  extern const size_t BIRKHOFF_DIAMOND_BOUNDARY_SIZE;
  extern const size_t BIRKHOFF_DIAMOND_INTERIOR_SIZE;
  extern const size_t BIRKHOFF_DIAMOND_SIZE;

  /* combinatorics */
  inline constexpr size_t COMBINATION_MAX_N = 34;/// C++17 support inline constexpr for compiling time global const variables

  /* random */
  extern unsigned int PGC__HISTORY_SEED;

  /* show in terminal */
  extern bool PGC__VERBOSE_MODE;
  extern bool PGC__DEBUG_MODE;
  extern bool PGC__INFO_MODE;
  extern int PGC__PERIODIC_COLOR;
  extern std::stack<int> PGC__COLOR_STACK;
}/// namespace PlanarGraphColoring
