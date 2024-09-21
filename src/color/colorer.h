/// colorer.h

#pragma once

#include "../topology/graph.h"
#include "color_result.h"

namespace PlanarGraphColoring {

constexpr int COLORS = 4;
constexpr int UNDEF_COLOR = -1;

class Colorer {
public:
  virtual void run(const Graph& input, ColorResult* output) = 0;
  virtual void colorBoundary(const Graph& input, ColorResult* output) = 0;
  virtual bool colorInterior(const Graph& input, ColorResult* output) = 0;
};/// class Colorer

}/// namespace PlanarGraphColoring
