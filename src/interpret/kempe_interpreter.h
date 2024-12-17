/// kempe_interpreter.h

#pragma once

#include "interpreter.h"
#include "../color/kempe/color_triple.h"

namespace PlanarGraphColoring {

class KempeInterpreter : public Interpreter {
public:
  virtual void show() const override;
protected:
  ColorTriple color_triple_;
};/// class KempeInterpreter

}/// namespace PlanarGraphColoring
