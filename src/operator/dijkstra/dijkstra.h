/// dijkstra.h

#pragma once

#include "../../basic/digraph.h"
#include "../directed_path_result.h"
#include "../directed_path.h"
#include "dijkstra_node.h"
#include <list>

namespace PlanarGraphColoring {

class Dijkstra {
public:
  void run(const size_t start, const Digraph& digraph, DirectedPathResult* paths);
  bool run(const size_t start, const size_t end, const Digraph& digraph, DirectedPath* path);
protected:
  void retrieve(const DijkstraNode* end_ptr, DirectedPath* path);
  void retrieve(const std::list<DijkstraNode>& list, DirectedPathResult* paths);
};/// class Dijkstra  

}/// namespace PlanarGraphColoring
