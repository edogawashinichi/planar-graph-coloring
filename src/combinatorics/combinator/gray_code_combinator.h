/// gray_code_combinator.h

#pragma once

#include "combinator.h"
#include "../../basic/global.h"
#include <bitset>

namespace PlanarGraphColoring {

class GrayCodeCombinator : public Combinator {
public:
  virtual VVI run(const size_t n, const size_t k) override;
protected:
  void getGrayCode(const LL& i, std::bitset<COMBINATION_MAX_N>* a);
};/// class GrayCodeCombinator

}/// namespace PlanarGraphColoring
