/// graph_searcher_result.cxx

#include "graph_searcher_result.h"

namespace PlanarGraphColoring {

void GraphSearcherResult::show() const {
  TEST_INFO
  std::cout << "components:\n";
  components_.show();
}/// GraphSearcherResult::show

void GraphSearcherResult::appendComponent(const std::unordered_set<size_t>& component) {
  std::vector<size_t> temp(component.begin(), component.end());
  components_.append(temp);
}/// GraphSearcherResult::addComponent

const Components& GraphSearcherResult::getComponents() const {
  return components_;
}/// GraphSearcherResult::getComponent

}/// namespace PlanarGraphColoring
