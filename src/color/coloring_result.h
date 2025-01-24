/// coloring.h

#pragma once

#include "../basic/structure/dimension_one_vector.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

class Color {
public:
  inline Color() : c_(UNDEF_COLOR) {}/// constructor default
  inline Color(const char c) : c_(c) {}/// constructor
  inline Color(const size_t i) {
    this->set(i);
  }/// constructor
  inline char get() const {
    return c_;
  }/// get
  inline size_t getIndex() const {
    const int index = find_index_in_vector<char>(c_, COLORS);
    size_t res = (-1 == index) ? COLORS.size() : static_cast<size_t>(index);
    return res;
  }/// getIndex
  inline void set(const char c) {
    c_ = c;
  }/// set
  inline void set(const size_t i) {
    if (i < COLORS.size()) c_ = COLORS[i];
    else c_ = UNDEF_COLOR;
  }/// set
  inline void show() const {
    TEST_INFO
    SHOW_CHAR_WITH_COLOR(c_)
  }/// show
protected:
  char c_;
};/// class Color

template<size_t N>
class Coloring : public DimensionOneVector<Color> {
public:
  /* WARNING: DERIVE_CLASS_4_FUNCTIONS(Coloring, DimensionOneVector<Color>) also ok */
  DERIVE_CLASS_4_FUNCTIONS(Coloring<N>, DimensionOneVector<Color>)
  inline Coloring<N>() : DimensionOneVector<Color>(N) { 
    /// WARNING: execution order depends on the compiler
    ///          if it has something inside
  }/// constructor default
  inline Coloring<N>(const VI& data) {
    /// assuming: data.size == N
    this->get().resize(N, Color());
    for (size_t i = 0; i < N; ++i) {
      this->get(i) = std::move(Color(data[i]));
    }
  }/// constructor
  inline VI getData() const {
    VI res(this->size(), 0);
    for (size_t i = 0; i < this->size(); ++i) {
      res[i] = this->getConst(i).getIndex();
    }
    return res;
  }/// getConst
  inline Coloring<N>(const VI& c, const VI& d) {
    /// assuming: N == c size + d size
    this->get().resize(N, Color());
    for (size_t i = 0; i < c.size(); ++i) {
      this->get(i) = std::move(Color(c[i]));
    }
    for (size_t i = c.size(); i < c.size() + d.size(); ++i) {
      this->get(i) = std::move(Color(d[i - c.size()]));
    }
  }/// constructor
  inline virtual void show() const {
    TEST_INFO
    SHOW_COLORING_WITH_INDEX(this->getConst())
  }/// show
};/// class Coloring

template<size_t N>
class ColoringResult : public DimensionOneVector<Coloring<N>> {
public:
  DERIVE_CLASS_4_FUNCTIONS(ColoringResult<N>, DimensionOneVector<Coloring<N>>)
  inline ColoringResult<N>() : DimensionOneVector<Coloring<N>>() {
  }/// constructor default
  inline ColoringResult<N>(const VVI& data) {
    /// assuming: data.front().size == N
    this->set(data);
  }/// constructor
  inline void set(const VVI& data) {
    /// assuming: data.front().size == N
    this->get().resize(data.size(), Coloring<N>());
    for (size_t i = 0; i < data.size(); ++i) {
      this->get(i) = std::move(Coloring<N>(data[i]));
    }
  }/// set
  inline virtual void show() const {
    TEST_INFO
    for (size_t i = 0; i < this->size(); ++i) {
      std::cout << i << "th: ";
      this->getConst(i).show();
    }
  }/// show
};/// class ColoringResult

}/// namespace PlanarGraphColoring
