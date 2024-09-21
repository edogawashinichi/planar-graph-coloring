/// math.h

#pragma once

#include <vector>

namespace PlanarGraphColoring {

/* x --f--> y */
void map(const std::vector<int>& X, const std::vector<int>& f, std::vector<int>* Y);

/* C = A - B */
void diff(const std::vector<int>& A, const std::vector<int>& B, std::vector<int>* C);

/* {0, 1, ..., n-1} */
std::vector<int> id(const size_t n);

}/// namespace PlanarGraphColoring
