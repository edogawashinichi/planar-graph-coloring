/// kempe_chain.h

/// without context of a ring

#pragma once

#include "../../topology/ring.h"
#include "../../basic/structure/dimension_two_vector.h"
#include <utility>

namespace PlanarGraphColoring {

class KempeChain : public DimensionTwoVector<size_t> {
public:
  KempeChain();
  KempeChain(const KempeChain& rhs);/// WARNING: k K
  KempeChain(KempeChain&& rhs);
  KempeChain& operator=(const KempeChain& rhs);
  KempeChain& operator=(KempeChain&& rhs);
  virtual void show() const override;
  void sort(const size_t ring_size);
  const VII separatedVertexPairs(const size_t ring_size);
  size_t getMaxValue() const;
  inline std::vector<std::vector<size_t>>& get() {
    return DimensionTwoVector<size_t>::get();
  }
  inline const std::vector<size_t>& getConst(const size_t index) const {
    return DimensionTwoVector<size_t>::getConst(index);
  } 
  inline const std::vector<std::vector<size_t>>& getConst() const {
    return DimensionTwoVector<size_t>::getConst();
  }
};/// class KempeChain

}/// namespace PlanarGraphColoring
