/// color_inducer.cxx

#include "color_inducer.h"
#include "../basic/notation.h"
#include "../operator/graph_searcher.h"
#include "../operator/graph_searcher_result.h"

namespace PlanarGraphColoring {

void ColorInducer::run(const Ring& ring, const ColorRepresentation& coloring, const II& vertex_pair, const II& color_pair, KempeChain* chain) {
  /// assuming: there exists a kempe chain of vertex_pair with color_pair
  ///           but the kempe chain may connect vertex_pair through the boundary rather than only the exterior
  /// chain: return all vertices of the kempe chain that are only on the boundary of the ring in form of components
  ///        if the kempe chain connects vertex_pair only through the exterior, then chain size would be 2
  ///        otherwise the kempe chain can connect vertex_pair through the boundary, then chain size would be 1
  VERBOSE_START(ColorInducer::run ring coloring vertex_pair color_pair chain)
  VERBOSE_OBJ(coloring)
  VERBOSE_PAIR(vertex_pair)
  VERBOSE_PAIR(color_pair)
  const size_t c = color_pair.first;
  const size_t d = color_pair.second;
  Graph color_induced;
  this->run(ring, coloring, {c, d}, &color_induced);
  color_induced.setSize(ring.boundarySize());
  VERBOSE << "color induced:\n";
  VERBOSE_OBJ(color_induced)
  GraphSearcher searcher;
  GraphSearcherResult result;
  searcher.bibfs(color_induced, vertex_pair, &result);
  chain->set(result.getComponents().getConst());
  chain->sort(ring.boundarySize());
  VERBOSE_END(ColorInducer::run ring coloring vertex_pair color_pair chain)
}/// ColorInducer::run

void ColorInducer::run(const Graph& lhs, const ColorRepresentation& coloring, const std::vector<size_t>& colors, Graph* rhs) {
  VERBOSE_START(ColorInducer::run lhs coloring colors rhs)
  const std::vector<size_t> vertices(coloring.getVertices(colors));
  VertexInducer::run(lhs, vertices, rhs);
  VERBOSE_END(ColorInducer::run lhs coloring colors rhs)
}/// ColorInducer::run

}/// namespace PlanarGraphColoring
