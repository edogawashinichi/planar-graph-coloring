/// color_triple.h

#pragma once

#include "../color_representation.h"

namespace PlanarGraphColoring {

class ColorTriple {
public:
  ColorTriple() : first_(nullptr), second_(nullptr), third_(nullptr) {}
  void show() const;
  void set(const ColorRepresentation& first, const ColorRepresentation& second, const ColorRepresentation& third);
  void free(ColorRepresentation* ptr);
  inline const ColorRepresentation* getFirstConst() const {
    return first_;
  }
  inline const ColorRepresentation* getSecondConst() const {
    return second_;
  }
  inline const ColorRepresentation* getThirdConst() const {
    return third_;
  }
  ~ColorTriple();
protected:
  void set(ColorRepresentation*& ptr, const ColorRepresentation& obj);
protected:
  ColorRepresentation* first_;
  ColorRepresentation* second_;
  ColorRepresentation* third_;
};/// class ColorTriple

}/// namespace PlanarGraphColoring
