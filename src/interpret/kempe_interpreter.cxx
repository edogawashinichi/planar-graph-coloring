/// kempe_interpreter.cxx

#include "kempe_interpreter.h"

namespace PlanarGraphColoring {

void KempeInterpreter::show() const {
  TEST_INFO
  std::cout << "KempeInterpreter::show\n";
  color_triple_.show();
}/// KempeInterpreter::show

}/// namespace PlanarGraphColoring
