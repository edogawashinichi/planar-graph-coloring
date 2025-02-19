/// coloring_orbit_result.h

/// index: of RingColoringResult
/// representative: of RingColoringResult
/// group_index: of ColoringGroup<VertexSymmetryGroup>
/// inverse_group_index: of ColoringGroup<VertexSymmetryGroup>
/// representative --group_index--> index
/// index --inverse_group_index--> representative

#pragma once

#include "../../basic/structure/dimension_one_vector.h"
#include "../../basic/hash.h"

/* judge not equal, return less than */
#define JNEQ_RET_LT(mem_) \
if (mem_ != rhs.mem_) return mem_ < rhs.mem_;
/* judge not equal, return false */
#define JNEQ_RET_F(lhs, rhs, mem_) \
if (lhs.mem_ != rhs.mem_) return false;

namespace PlanarGraphColoring {

class ColoringInfo {
public:
  inline ColoringInfo() {
    index_ = UNDEF_INDEX;
    representative_ = UNDEF_INDEX;
    group_index_ = UNDEF_INDEX;
    inverse_group_index_ = UNDEF_INDEX;
  }/// constructor default
  inline ColoringInfo(const size_t w, const size_t x, const size_t y, const size_t z) {
    index_ = w;
    representative_ = x;
    group_index_ = y;
    inverse_group_index_ = z;
  }/// constructor
  inline ColoringInfo(const VI& quadruple) {
    /* assuming: quadruple size == 4 */
    index_ = quadruple[0];
    representative_ = quadruple[1];
    group_index_ = quadruple[2];
    inverse_group_index_ = quadruple[3];
  }/// constructor
  inline VI getVector() const {
    return {index_, representative_, group_index_, inverse_group_index_};
  }/// getVector
  inline size_t index() const {
    return index_;
  }/// index
  inline size_t representative() const {
    return representative_;
  }/// representative
  inline size_t groupIndex() const {
    return group_index_;
  }/// groupIndex
  inline size_t inverseGroupIndex() const {
    return inverse_group_index_;
  }/// inverseGroupIndex
  inline void show(std::ostream& cout) const {
    TEST_INFO
    cout << "index=" << index_;
    cout << "  representative=" << representative_;
    cout << "  group_index=" << group_index_;
    cout << "  inverse_group_index=" << inverse_group_index_ << "\n";
  }/// show
  inline friend std::ostream& operator<<(std::ostream& cout, const ColoringInfo& obj) {
    obj.show(cout);
    return cout;
  }/// friend operator<<
  inline bool operator<(const ColoringInfo& rhs) {
    JNEQ_RET_LT(index_)
    JNEQ_RET_LT(representative_)
    JNEQ_RET_LT(group_index_)
    JNEQ_RET_LT(inverse_group_index_)
    return true;
  }/// operator<
  inline friend bool operator==(const ColoringInfo& lhs, const ColoringInfo& rhs) {
    JNEQ_RET_F(lhs, rhs, index_)
    /*JNEQ_RET_F(lhs, rhs, representative_)
    JNEQ_RET_F(lhs, rhs, group_index_)
    JNEQ_RET_F(lhs, rhs, inverse_group_index_)*/
    return true;
  }/// friend operator==
protected:
  size_t index_;
  size_t representative_;
  size_t group_index_;
  size_t inverse_group_index_;
};/// class ColoringInfo
class ColoringInfoHasher : public vi_hash {
public:
  inline size_t operator()(const ColoringInfo& obj) const {
    return vi_hash::operator()({obj.getVector()[0]});
  }/// operator()
};/// class ColoringInfoHasher
class ColoringInfoEqual {
public:
  inline bool operator()(const ColoringInfo& lhs, const ColoringInfo& rhs) const {
    return lhs == rhs;
  }/// operator()
};/// class ColoringInfoEqual

class ColoringOrbit : public DimensionOneVector<ColoringInfo> {
public:
  DERIVE_CLASS_5_FUNCTIONS(ColoringOrbit, DimensionOneVector<ColoringInfo>)
  inline ColoringOrbit(const ColoringInfo& front) {
    this->get().emplace_back(front);
  }/// constructor
  inline virtual void show(std::ostream& cout) const override {
    TEST_INFO
    cout << "size=" << this->size() << "\n";
    for (size_t i = 0; i < this->size(); ++i) {
      DEBUG << i << "th:  ";
      if (PGC__VERBOSE_MODE) this->getConst(i).show(cout);
    }
  }/// show
  inline VI getIndexVector() const {
    VI res(this->getConst().size());
    for (size_t i = 0; i < this->size(); ++i) {
      res[i] = this->getConst(i).index();
    }
    return res;
  }/// getIndexVector
  inline void removeDuplicate(ColoringOrbit* rhs) const {
    std::unordered_set<ColoringInfo, ColoringInfoHasher, ColoringInfoEqual> set(this->getConst().begin(), this->getConst().end());
    for (const ColoringInfo& ele : set) {
      rhs->append(ele);
    }
    rhs->sort();
  }/// removeDuplicate
};/// class ColoringOrbit

/* utilize member function of ColoringOrbit rather than using DimensionTwoVector<ColoringInfo> */
class ColoringOrbitResult : public DimensionOneVector<ColoringOrbit> {
public:
  DERIVE_CLASS_5_FUNCTIONS(ColoringOrbitResult, DimensionOneVector<ColoringOrbit>)
  inline void append(const ColoringInfo& back_front) {
    this->get().emplace_back(ColoringOrbit(back_front));
  }/// append 
  inline void extend(const ColoringInfo& back_back) {
    /* assuming: this not empty */
    this->get().back().append(back_back);
  }/// extend
  inline VI getOriginalSizeVector() const {
    VI res;
    for (const auto& orbit : this->getConst()) {
      res.emplace_back(orbit.size());
    }
    return res;
  }/// getOriginalSizeVector
  inline VI getReducedSizeVector() const {
    VI res;
    for (const auto& orbit : this->getConst()) {
      ColoringOrbit reduced;
      orbit.removeDuplicate(&reduced);
      res.emplace_back(reduced.size());
    }
    return res;
  }/// getReducedSizeVector
  inline virtual void show(std::ostream& cout) const override {
    TEST_INFO
    for (size_t i = 0; i < this->size(); ++i) {
      cout << i << "th orbit:\n";
      cout << "original:\n";
      this->getConst(i).show(cout);
      ColoringOrbit reduced;
      this->getConst(i).removeDuplicate(&reduced);
      cout << "reduced:\n";
      reduced.show(cout);
    }
  }/// show
};/// class ColoringOrbitResult

}/// namespace PlanarGraphColoring
