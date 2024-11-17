/// routing_interpreter.h

#pragma once

#include "interpreter.h"

namespace PlanarGraphColoring {

class RoutingInterpreter : public Interpreter {
public:
  virtual void show() const override;
  void set(const RelationManager& manager, DigraphSearcherResult& result);
protected:
  ColorResult colors_;
  RelationResult transformations_;
};/// class RoutingInterpreter

}/// namespace PlanarGraphColoring
