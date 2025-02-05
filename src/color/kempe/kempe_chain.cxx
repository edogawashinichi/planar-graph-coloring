/// kempe_chain.cxx

#include "kempe_chain.h"
#include "../../basic/math.h"

namespace PlanarGraphColoring {

const VII KempeChain::getSeparatedVertexPairs(const size_t ring_size) const {
  /// assuming: this size=2
  /// assuming: this cycle_sorted
  VERBOSE_START(KempeChain::getSeparatedVertexPairs)
  VII res;
  /// WARNING: argument ring_size rather than getMaxValue
  for (size_t i = (this->getConst(0).back() + 1) % ring_size; i != this->getConst(1).front(); i = (i + 1) % ring_size) {
    for (size_t j = (this->getConst(1).back() + 1) % ring_size; j != this->getConst(0).front(); j = (j + 1) % ring_size) {
      res.emplace_back(std::pair<size_t, size_t>({i, j}));
    }/// for j
  }/// for i
  VERBOSE_END(KempeChain::getSeparatedVertexPairs)
  return res;
}/// KempeChain::getSeparatedVertexPair

void KempeChain::show(std::ostream& cout) const {
  TEST_INFO
  cout << "KempeChain:\n";
  PGC__SHOW_VVI_WITH_INDEX(cout, this->getConst())
}/// KempeChain::show

void KempeChain::sort(const size_t ring_size) {
  cycle_sort(this->get(), ring_size);
}/// sort

size_t KempeChain::getMaxValue() const {
  size_t res = 0;
  for (const auto& vec : DimensionTwoVector<size_t>::getConst()) {
    res = std::max(res, *max_element(vec.begin(), vec.end()));
  }/// for
  return res;
}/// KempeChain::getMaxValue

}/// namespace PlanarGraphColoring
