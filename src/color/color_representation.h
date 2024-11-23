/// color_representation.h

/// this is the basic class of color representation
/// Four Colors Representations Only

#pragma once

#include "../basic/global.h"
#include <vector>

namespace PlanarGraphColoring {

class ColorRepresentation {
public:
  virtual size_t size() const = 0;
  virtual bool empty() const = 0;
  virtual size_t get(const size_t index) const = 0;
  virtual std::vector<size_t> getVector() const = 0;
  virtual void set(const size_t index, const size_t color) = 0;
  virtual void reset(const size_t index) = 0;
  virtual void show() const = 0;
  virtual bool valid() const = 0;
  inline virtual bool equal(const ColorRepresentation& rhs) const {
    return this->getVector() == rhs.getVector();
  }

  virtual ~ColorRepresentation() = default;
};/// class ColorRepresentation

}/// namespace PlanarGraphColoring
