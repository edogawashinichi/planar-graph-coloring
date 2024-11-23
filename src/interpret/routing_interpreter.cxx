/// routing_interpreter.cxx

#include "routing_interpreter.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

void RoutingInterpreter::show() const {
  TEST_INFO
  DEBUG_START(RoutingInterpreter::show)
  if (!colors_.empty()) {
    /// WARNING: partial travesal by size_t type
    for (size_t i = 0; i < colors_.size() - 1; ++i) {
      INFO << i << "th color: ";
      colors_.getConst(i)->show();
      INFO << TAB << i << "th transformation: ";
      transformations_.get(i).show();
    }
    const size_t last_index = colors_.size() - 1;
    INFO << last_index << "th color: ";
    colors_.getConst(last_index)->show();
  }/// if colors not empty
  DEBUG_END(RoutingInterpreter::show)
}/// RoutingInterpreter::show

void RoutingInterpreter::set(const RelationManager& manager, DigraphSearcherResult& result, const size_t start, const size_t end) {
  DEBUG_START(RoutingInterpreter::set)
  const DirectedPath& path = result.getDirectedPathResult()->getDirectedPath(start, end);
  if (!path.vertices_.empty()) {
    for (size_t i = 0; i < path.vertices_.size() - 1; ++i) {
      const size_t u = path.vertices_[i];
      const size_t v = path.vertices_[i + 1];
      colors_.append(manager.getColorResultConst()->getInfo(u));
      const size_t t = manager.getMapperConst()->get(u, v);
      transformations_.append(manager.getRelationResultConst()->get(t));
    }/// for
    const size_t w = path.vertices_.back();
    colors_.append(manager.getColorResultConst()->getInfo(w));
  }
  DEBUG_END(RoutingInterpreter::set)
}/// RoutingInterpreter::set

}/// namespace PlanarGraphColoring
