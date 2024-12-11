/// vertex_inducer.cxx

#include "vertex_inducer.h"
#include "../basic/math.h"
#include <unordered_set>

namespace PlanarGraphColoring {

void VertexInducer::run(const Graph& lhs, const std::vector<size_t>& vertices, Graph* rhs) {
  const VII edges(lhs.getEdges());
  const std::unordered_set<size_t> set(vertices.begin(), vertices.end());
  rhs->clear();
  size_t n = 0;
  for (const auto& edge : edges) {
    const size_t u = edge.first;
    const size_t v = edge.second;
    if (!set.count(u) || !set.count(v)) continue;
    n = max<size_t>(n, u + 1, v + 1);
    rhs->insert(u, v);
    rhs->insert(v, u);
  }/// for
  rhs->setSize(n); /// DETAIL: default way
}/// VertexInducer::run

}/// namespace PlanarGraphColoring
