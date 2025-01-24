/// birkhoff_diamond_coloring_result.h

#pragma once

#include "coloring_result.h"
#include <memory>

namespace PlanarGraphColoring {

class BirkhoffDiamondColoringResult {
public:
  inline BirkhoffDiamondColoringResult() {
    boundary_colorings_ = std::make_unique<ColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>>();
    interior_colorings_ = std::make_unique<ColoringResult<BIRKHOFF_DIAMOND_INTERIOR_SIZE>>();
  }/// constructor default
  inline ColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>* getBoundaryColorings() {
    return boundary_colorings_.get();
  }/// getBoundaryColorings
  inline ColoringResult<BIRKHOFF_DIAMOND_INTERIOR_SIZE>* getInteriorColorings() {
    return interior_colorings_.get();
  }/// getInteriorColorings
  inline Coloring<BIRKHOFF_DIAMOND_SIZE> get(const size_t index) const {
    /// assuming: boundary colorings size == interior colorings size
    /// assuming: index valid
    return Coloring<BIRKHOFF_DIAMOND_SIZE>(boundary_colorings_->getConst(index).getData(), interior_colorings_->getConst(index).getData());
  }/// get
  inline void show() const {
    /// assuming: boundary colorings size == interior colorings size
    TEST_INFO
    for (size_t i = 0; i < boundary_colorings_->size(); ++i) {
      std::cout << i << "th: ";
      const Coloring<BIRKHOFF_DIAMOND_SIZE> coloring(this->get(i));
      coloring.show();
    }
  }/// show
protected:
  std::unique_ptr<ColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>> boundary_colorings_;
  std::unique_ptr<ColoringResult<BIRKHOFF_DIAMOND_INTERIOR_SIZE>> interior_colorings_;
};/// class BirkhoffDiamondColoringResult

}/// namespace PlanarGraphColoring
