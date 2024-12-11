/// graph_searcher_result.h

#pragma once

#include "searcher_result.h"
#include "component.h"
#include <unordered_set>

namespace PlanarGraphColoring {

class GraphSearcherResult : public SearcherResult {
public:
  virtual void show() const override;
  const Components& getComponents() const;
  void appendComponent(const std::unordered_set<size_t>& component);
protected:
  Components components_;
};/// class GraphSearcherResult

}/// namespace PlanarGraphColoring
