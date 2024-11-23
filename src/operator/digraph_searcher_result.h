/// digraph_searcher_result.h

#pragma once

#include "searcher_result.h"
#include "weak_component.h"
#include "directed_path_result.h"

namespace PlanarGraphColoring {

class DigraphSearcherResult : public SearcherResult {
public:
  virtual void show() const override;
  void appendWeakComponent(const size_t vertex);
  void extendWeakComponent(const size_t vertex);
  void appendDirectedPath(const DirectedPath& path);
  size_t weakComponentSize() const;
  size_t weakComponentSize(const size_t index) const;
  size_t getWeakComponent(const size_t i, const size_t j) const;
  DirectedPathResult* getDirectedPathResult();
protected:
  WeakComponent weak_component_;
  DirectedPathResult directed_path_result_;
};/// class SearcherResult

}/// namespace PlanarGraphColoring
