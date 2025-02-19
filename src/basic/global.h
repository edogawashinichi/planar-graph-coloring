/// global.h

#pragma once

#include <vector>
#include <stack>

namespace PlanarGraphColoring {
  /* color */
  extern const std::vector<char> COLORS;
  extern const char UNDEF_COLOR;
  extern const size_t UNDEF_VERTEX;
  extern const size_t UNDEF_INDEX;

  /* topology */
  inline constexpr size_t BIRKHOFF_DIAMOND_BOUNDARY_SIZE = 6;
  inline constexpr size_t BIRKHOFF_DIAMOND_INTERIOR_SIZE = 4;
  inline constexpr size_t BIRKHOFF_DIAMOND_SIZE = 10;

  /* combinatorics */
  inline constexpr size_t COMBINATION_MAX_N = 34;/// compile-time global-const-variable (C++17)

  /* random */
  extern unsigned int PGC__HISTORY_SEED;

  /* terminal */
  extern bool PGC__VERBOSE_MODE;
  extern bool PGC__DEBUG_MODE;
  extern bool PGC__INFO_MODE;
  extern int PGC__PERIODIC_COLOR;
  extern std::stack<int> PGC__COLOR_STACK;
  
}/// namespace PlanarGraphColoring
