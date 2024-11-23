/// routing_interpreter.h

#pragma once

#include "interpreter.h"
#include "../relation/relation_manager.h"
#include "../operator/digraph_searcher_result.h"

namespace PlanarGraphColoring {

class RoutingInterpreter : public Interpreter {
public:
  virtual void show() const override;
  void set(const RelationManager& manager, DigraphSearcherResult& result, const size_t start, const size_t end);
protected:
  ColorResult colors_;
  RelationResult transformations_;
};/// class RoutingInterpreter

}/// namespace PlanarGraphColoring
