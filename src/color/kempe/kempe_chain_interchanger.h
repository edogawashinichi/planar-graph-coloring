/// kempeChainInterchanger.h

#pragma once

#include "../color_representative.h"
#include "../color_result.h"
#include "../topology/planar_graph.h"

namespace PlanarGraphColoring {

class KempeChainInterchanger {
public:
  virtual bool run(const PlanarGraph& graph, const ColorRepresentative& lhs, ColorReuslt* rhs) = 0;
protected:
};/// class KempeChainInterchanger

}/// namespace PlanarGraphColoring
