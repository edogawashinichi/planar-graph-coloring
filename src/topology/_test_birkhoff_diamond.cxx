/// _test_birkhoff_diamond.cxx

#include "birkhoff_diamond.h"
#include "../basic/notation.h"

using namespace PlanarGraphColoring;

void test_0() {
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
  BirkhoffDiamond bd;
  bd.show();
  const std::unordered_map<size_t, std::vector<size_t>> boundary_backward_neighbors = {
    {1, {0}},
    {2, {1}},
    {3, {2}},
    {4, {3}},
    {5, {0, 4}}
  };
  const std::unordered_map<size_t, std::vector<size_t>> interior_backward_neighbors = {
    {6, {0, 1, 5}},
    {7, {1, 2, 6}},
    {8, {2, 3, 4, 7}},
    {9, {4, 5, 6, 7, 8}}
  };
  bool res = true;
  for (size_t vertex = 0; vertex < 10; ++vertex) {
  //for (const auto& kv : boundary_backward_neighbors) {
    //const size_t vertex = kv.first;
    if (!boundary_backward_neighbors.count(vertex)) {
      if (bd.getBBN(vertex) != std::vector<size_t>()) {
        std::cout << "vertex " << vertex << " getBoundaryBackwardNeighbors failed!\n";
        res = false;
        break;
      } else {
        std::cout << "vertex " << vertex << " getBoundaryBackwardNeighbors passed!\n";
      }
      continue;
    }
    if (boundary_backward_neighbors.at(vertex) != bd.getBBN(vertex)) {
      std::cout << "vertex " << vertex << " getBoundaryBackwardNeighbors failed!\n";
      res = false;
      break;
    } else {
      std::cout << "vertex " << vertex << " getBoundaryBackwardNeighbors passed!\n";
    }
  }
  for (size_t vertex = 0; vertex < 10; ++vertex) {
  //for (const auto& kv : interior_backward_neighbors) {
    //const size_t vertex = kv.first;
    if (!interior_backward_neighbors.count(vertex)) {
      if (bd.getIBN(vertex) != std::vector<size_t>()) {
        std::cout << "vertex " << vertex << " getInteriorBackwardNeighbors failed!\n";
        res = false;
        break;
      } else {
        std::cout << "vertex " << vertex << " getInteriorBackwardNeighbors passed!\n";
      }
      continue;
    }
    if (interior_backward_neighbors.at(vertex) != bd.getIBN(vertex)) {
      std::cout << "vertex " << vertex << " getInteriorBackwardNeighbors failed!\n";
      res = false;
      break;
    } else {
      std::cout << "vertex " << vertex << " getInteriorBackwardNeighbors passed!\n";
    }
  }
  std::vector<std::vector<size_t>> mappers = {
    {0, 5, 4, 3, 2, 1}, /* vertical reflection */
    {3, 2, 1, 0, 5, 4}, /* horizontal reflection */
    {3, 4, 5, 0, 1, 2}, /* (counter)clockwise 180 degrees rotation */
  };
  for (size_t i = 0; i < mappers.size(); ++i) {
    if (mappers[i] != bd.getVS(i)) {
      std::cout << i << "th getVertexSymmetry failed!\n";
      res = false;
      break;
    } else {
      std::cout << i << "th getVertexSymmetry passed!\n";
    }
  }
  PGC__TEST_RESULT_INFO(res, 0)
  PGC__SHOW_ENDL(PGC__TEST_SEPAR(0))
}/// test_0

int main(int argc, char* argv[]) {
  test_0();
  return 0;
}
