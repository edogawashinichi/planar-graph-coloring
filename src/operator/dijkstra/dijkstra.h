/// dijkstra.h

#pragma once

#include "../../basic/digraph.h"
#include "../directed_path.h"
#include "dijkstra_node.h"
#include <list>

namespace PlanarGraphColoring {

class Dijkstra {
public:
  bool run(const size_t start, const size_t end, const Digraph& digraph, DirectedPath* path);
protected:
  void retrieve(const std::list<DijkstraNode>& list, DirectedPath* path);
};/// class Dijkstra  

}/// namespace PlanarGraphColoring
