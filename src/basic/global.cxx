/// global.cxx

#include "global.h"

namespace PlanarGraphColoring {
  const size_t COLORS = 4;
  const size_t UNDEF_COLOR = 9;
  const size_t UNDEF_VERTEX = 10000;

  const size_t BIRKHOFF_DIAMOND_BOUNDARY_SIZE = 6;
  const size_t BIRKHOFF_DIAMOND_INTERIOR_SIZE = 4;
  const size_t BIRKHOFF_DIAMOND_SIZE = 10;

  ///constexpr size_t COMBINATION_MAX_N = 34;

  unsigned int PGC__HISTORY_SEED = 0;

  bool PGC__VERBOSE_MODE = false;
  bool PGC__DEBUG_MODE = false;
  bool PGC__INFO_MODE = false;
  int PGC__PERIODIC_COLOR = 0;
  std::stack<int> PGC__COLOR_STACK;
}/// namespace PlanarGraphColoring
