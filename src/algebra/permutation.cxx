/// permutation.cxx

#include "permutation.h"

namespace PlanarGraphColoring {

Permutation::Permutation(const Permutation& rhs) {
  if (this != &rhs) {
    f_ = rhs.f_;
  }
}/// constructor deepcopy

Permutation::Permutation(Permutation&& rhs) {
  if (this != &rhs) {
    std::swap(f_, rhs.f_);
  }
}/// constructor movecopy

Permutation& Permutation::operator=(const Permutation& rhs) {
  if (this != &rhs) {
    f_ = rhs.f_;
  }
  return *this;
}/// assignment deepcopy

Permutation& Permutation::operator=(Permutation&& rhs) {
  if (this != &rhs) {
    std::swap(f_, rhs.f_);
  }
  return *this;
}/// assignment movecopy

}/// namespace PlanarGraphColoring
