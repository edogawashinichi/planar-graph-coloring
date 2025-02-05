/// coloring.h

#pragma once

#include "../basic/structure/dimension_one_vector.h"
#include "../basic/notation.h"

namespace PlanarGraphColoring {

class Color {
public:
  CLASS_4_FUNCTIONS(Color, c_)
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
    return (-1 == index) ? COLORS.size() : static_cast<size_t>(index);
  }/// getIndex
  inline void set(const char c) {
    c_ = c;
  }/// set
  inline void set(const size_t i) {
    if (i < COLORS.size()) c_ = COLORS[i];
    else c_ = UNDEF_COLOR;
  }/// set
  inline void show(std::ostream& cout) const {
    TEST_INFO
    SHOW_CHAR_WITH_COLOR(cout, c_)
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const Color& color) {
    color.show(cout);
    return cout;
  }/// friend operator<<
  inline friend bool operator==(const Color& lhs, const Color& rhs) {
    return lhs.c_ == rhs.c_;
  }/// friend operator==
protected:
  char c_;
};/// class Color

class Coloring : public DimensionOneVector<Color> {
public:
  DERIVE_CLASS_5_FUNCTIONS(Coloring, DimensionOneVector<Color>)
  inline Coloring(const Coloring& c, const Coloring& d) {
    splice<Color>(c.getConst(), d.getConst(), &(this->get()));
  }/// constructor
  inline Coloring(const VI& c, const VI& d) {
    VI e;
    splice<size_t>(c, d, &e);
    this->set(e);
  }/// constructor
  inline Coloring(const VI& data) {
    this->set(data);
  }/// constructor
  inline Coloring(const std::vector<Color>& data) {
    this->set(data);
  }/// constructor
  inline void set(const VI& data) {
    this->get().resize(data.size(), Color());
    for (size_t i = 0; i < data.size(); ++i) {
      this->get(i) = std::move(Color(data[i]));
    }
  }/// set
  inline void set(const std::vector<Color>& data) {
    this->get().resize(data.size(), Color());
    for (size_t i = 0; i < data.size(); ++i) {
      this->get(i) = std::move(Color(data[i]));
    }
  }/// set
  inline Coloring getCopy(const size_t start, const size_t end) const {
    std::vector<Color> coloring(DimensionOneVector<Color>::getCopy(start, end));
    return Coloring(coloring);
  }/// getCopy
  inline VI getData() const {
    VI res(this->size(), COLORS.size());
    for (size_t i = 0; i < this->size(); ++i) {
      res[i] = this->getConst(i).getIndex();
    }
    return res;
  }/// getData
  inline bool valid() const {
    return this->find(Color('X')) == -1;
  }/// vaild
  inline virtual void show(std::ostream& cout) const {
    TEST_INFO
    SHOW_COLORING_WITH_INDEX(cout, this->getConst(), this->valid())
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const Coloring& obj) {
    obj.show(cout);
    return cout;
  }/// friend operator<<
};/// class Coloring

class ColoringResult : public DimensionOneVector<Coloring> {
public:
  DERIVE_CLASS_5_FUNCTIONS(ColoringResult, DimensionOneVector<Coloring>)
  inline ColoringResult(const VVI& data) {
    this->set(data);
  }/// constructor
  inline void set(const VVI& data) {
    this->get().resize(data.size(), Coloring());
    for (size_t i = 0; i < data.size(); ++i) {
      this->get(i) = std::move(Coloring(data[i]));
    }
  }/// set
  inline virtual void show(std::ostream& cout) const {
    TEST_INFO
    for (size_t i = 0; i < this->size(); ++i) {
      SHOW_INDEX_WITH_COLOR(cout, i, this->getConst(i).valid())
      this->getConst(i).show(cout);
    }
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const ColoringResult& obj) {
    obj.show(cout);
    return cout;
  }/// friend operator<<
};/// class ColoringResult

}/// namespace PlanarGraphColoring
