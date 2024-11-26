/// edge_inducer.cxx

#include "edge_inducer.h"
#include "../basic/math.h"

namespace PlanarGraphColoring {

void EdgeInducer::run(const Graph& lhs, const VII& edges, Graph* rhs) {
  rhs->clear();
  size_t n = 0;
  for (const auto& edge : edges) {
    const size_t u = edge.first;
    const size_t v = edge.second;
    if (lhs.contain(u, v)) {
      rhs->insert(u, v);
      rhs->insert(v, u);
      n = max<size_t>(n, u + 1, v + 1);
    }
  }/// for
  rhs->setSize(n);
}/// EdgeInducer::run

}/// namespace PlanarGraphColoring
