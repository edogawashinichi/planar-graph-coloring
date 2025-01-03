/// kempe_interpreter.cxx

#include "kempe_interpreter.h"

namespace PlanarGraphColoring {

void KempeInterpreter::setClass(const size_t i, const size_t j, const size_t k) {
  class_ = i;
  separating_class_ = j;
  separated_class_ = k;
}/// KempeInterpreter::setClass

void KempeInterpreter::show() const {
  TEST_INFO
  INFO_VAR(class_)
  INFO_VAR(separating_class_)
  INFO_VAR(separated_class_)
  INFO_OBJ(coloring_)
  INFO_OBJ(kempe_chain_result_)
  INFO_OBJ(separating_route_)
  INFO_OBJ(separated_route_)
}/// KempeInterpreter::show

}/// namespace PlanarGraphColoring
