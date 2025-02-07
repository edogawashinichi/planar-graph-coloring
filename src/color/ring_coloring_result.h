/// ring_coloring_result.h

#pragma once

#include "coloring_result.h"
#include "acc_coloring_result.h"

namespace PlanarGraphColoring {

class RingColoring {
public:
  inline RingColoring() {
    this->clear();
  }/// constructor default
  inline RingColoring(const size_t m, const size_t n) {
    this->resize(m, n);
  }/// constructor
  inline RingColoring(const VI& boundary, const VI& interior) {
    boundary_coloring_ = std::move(Coloring(boundary));
    interior_coloring_ = std::move(Coloring(interior));
  }/// constructor
  inline void clear() {
    boundary_coloring_.get().clear();
    interior_coloring_.get().clear();
  }/// clear
  inline void resize(const size_t m, const size_t n) {
    boundary_coloring_.get().resize(m, Color(UNDEF_COLOR));
    interior_coloring_.get().resize(n, Color(UNDEF_COLOR));
  }/// resize
  inline Coloring copyColoring() const {
    /// TODO: C++20 view
    return Coloring(boundary_coloring_, interior_coloring_);
  }/// copyColoring
  inline VI copyData() const {
    return this->copyColoring().getData();
  }/// copyData
  inline const Color& getConst(const size_t index) const {
    /// assuming: index valid
    if (index < boundary_coloring_.size()) {
      return boundary_coloring_.getConst(index);
    } else {
      return interior_coloring_.getConst(index - boundary_coloring_.size());
    }
  }/// getConst
  inline Color& get(const size_t index) {
    /// assuming: index valid
    return index < boundary_coloring_.size() ? boundary_coloring_.get(index) : interior_coloring_.get(index - boundary_coloring_.size());
  }/// get
  inline const Color& constBoundaryColoring(const size_t index) const {
    /// assuming: index valid
    return boundary_coloring_.getConst(index);
  }/// constBoundaryColoring
  inline const Color& constInteriorColoring(const size_t index) const {
    /// assuming: index valid
    return interior_coloring_.getConst(index);
  }/// constInteriorColoring
  inline const Coloring& constBoundaryColoring() const {
    return boundary_coloring_;
  }/// constBoundaryColoring
  inline const Coloring& constInteriorColoring() const {
    return interior_coloring_;
  }/// constInteriorColoring
  inline Coloring& getBoundaryColoring() {
    return boundary_coloring_;
  }/// getBoundaryColoring
  inline Coloring& getInteriorColoring() {
    return interior_coloring_;
  }/// getInteriorColoring
  inline void set(const size_t index, const size_t color) {
    /// assuming: index valid
    if (index < boundary_coloring_.size()) {
      boundary_coloring_.get(index) = std::move(Color(color));
    } else {
      interior_coloring_.get(index - boundary_coloring_.size()) = std::move(Color(color));
    }
  }/// set
  inline size_t size() const {
    return boundary_coloring_.size() + interior_coloring_.size();
  }/// size
  inline size_t boundarySize() const {
    return boundary_coloring_.size();
  }/// boundarySize
  inline size_t interiorSize() const {
    return interior_coloring_.size();
  }/// interiorSize
  inline void show(std::ostream& cout) const {
    TEST_INFO
    this->copyColoring().show(cout);
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const RingColoring& obj) {
    obj.show(cout);
    return cout;
  }/// friend operator<<
protected:
  Coloring boundary_coloring_;
  Coloring interior_coloring_;
};/// class RingColoring

class RingColoringResult : public DimensionOneVector<RingColoring> {
public:
  DERIVE_CLASS_4_FUNCTIONS(RingColoringResult, DimensionOneVector<RingColoring>)
  inline RingColoringResult() {
    this->get().clear();
  }/// constructor default
  inline RingColoringResult(const VVI& boundary, const VVI& interior) {
    /// assuming: boundary size == interior size
    this->get().resize(boundary.size());
    for (size_t i = 0; i < this->size(); ++i) {
      this->get(i) = std::move(RingColoring(boundary[i], interior[i]));
    }
  }/// constructor
  inline const Coloring& constBoundaryColoring(const size_t index) const {
    /// assuming: index valid
    return this->getConst(index).constBoundaryColoring();
  }/// constBoundaryColoring
  inline ColoringResult copyBoundaryColoringResult() const {
    /// TODO: C++20 view
    ColoringResult colorings;
    for (size_t i = 0; i < this->size(); ++i) {
      colorings.append(this->getConst(i).constBoundaryColoring());
    }
    return colorings;
  }/// copyBoundaryColoringResult
  inline void findBoundaryColoring(const ColoringResult& boundary_colorings, SI* indices) const {
    AccColoringResult acc(this->copyBoundaryColoringResult());
    for (size_t i = 0; i < boundary_colorings.size(); ++i) {
      const int index = acc.find(boundary_colorings.getConst(i));
      indices->insert(index);
    }
  }/// findBoundaryColoring
  inline void show(std::ostream& cout, const size_t n) const {
    TEST_INFO
    for (size_t i = 0; i < this->size() && i < n; ++i) {
      const Coloring& coloring = this->getConst(i).copyColoring();
      SHOW_INDEX_WITH_COLOR(cout, i, coloring.valid())
      coloring.show(cout);
    }
  }/// show
  inline virtual void show(std::ostream& cout) const override {
    this->show(cout, this->size());
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const RingColoringResult& obj) {
    obj.show(cout);
    return cout;
  }/// friend operator<<
};/// class RingColoringResult

}/// namespace PlanarGraphColoring
