/// random.h

#pragma once

#include "notation.h"

namespace PlanarGraphColoring {

bool bet(const float probability);

/* random choose k distinct elements with equivalent probability from {0, 1, ..., n-1}*/
VI randomChoose(const size_t n, const size_t k);

}/// namespace PlanarGraphColoring
