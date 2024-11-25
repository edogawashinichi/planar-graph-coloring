/// color_representation.h

/// this is the basic class of color representation
/// Four Colors Representations Only

#pragma once

#include "../basic/global.h"
#include <vector>

namespace PlanarGraphColoring {

class ColorRepresentation {
public:
  inline std::vector<size_t> getVertices(const std::vector<size_t>& colors) const {
    std::vector<size_t> res;
    for (size_t v = 0; v < this->size(); ++v) {
      bool find = false;
      for (const auto& color : colors) {
        if (this->get(v) == color) {
          find = true;
          break;
        }/// if
      }/// for color
      if (find) {
        res.emplace_back(v);
      }/// if find
    }/// for v
    return res;
  }/// getVertices
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
