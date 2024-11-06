/// colorer.h

#pragma once

#include "../basic/graph.h"
#include "color_result.h"

namespace PlanarGraphColoring {

class Colorer {
public:
  virtual void run(const Graph& input, ColorResult* output) = 0;
  virtual void colorBoundary(const Graph& input, ColorResult* output) = 0;
  virtual bool colorInterior(const Graph& input, ColorResult* output) = 0;
};/// class Colorer

}/// namespace PlanarGraphColoring
