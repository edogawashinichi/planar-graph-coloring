/// routing_interpreter.cxx

#include "routing_interpreter.h"

namespace PlanarGraphColoring {

void RoutingInterpreter::show() const {
  TEST_INFO
  INFO_START(RoutingInterpreter::show)
  for (size_t i = 0; i < colors_.size() - 1; ++i) {
    INFO << i << "th color: ";
    colors_.get(i).show();
    INFO << i << "th transformation: ";
    transformations_.get(i).show();
  }
  const size_t last_index = colors_.size();
  INFO << last_index << "th color: ";
  colors_.get(last_index).show();
  INFO_END(RoutingInterpreter::show)
}/// RoutingInterpreter::show

void RoutingInterpreter::set(const RelationManager& manager, DigraphSearcherResult& result) {
  
}/// RoutingInterpreter::set

}/// namespace PlanarGraphColoring
