/// searcher_result.h

#pragma once

#include <ostream>

namespace PlanarGraphColoring {

class SearcherResult {
public:
  virtual void show(std::ostream& cout) const = 0;
};/// class SearcherResult

}/// namespace PlanarGraphColoring
