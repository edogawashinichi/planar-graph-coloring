/// _test_birkhoff_diamond.cxx

#include "birkhoff_diamond.h"
#include "../basic/notation.h"
#include "../basic/math.h"

using namespace PlanarGraphColoring;

/// test_0
TEST_START(0)
  BirkhoffDiamond bd;
  INFO_OBJ(bd)
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
        DEBUG << "vertex " << vertex << " getBoundaryBackwardNeighbors failed!\n";
        res = false;
        break;
      } else {
        DEBUG << "vertex " << vertex << " getBoundaryBackwardNeighbors passed!\n";
      }
      continue;
    }
    if (boundary_backward_neighbors.at(vertex) != bd.getBBN(vertex)) {
      DEBUG << "vertex " << vertex << " getBoundaryBackwardNeighbors failed!\n";
      res = false;
      break;
    } else {
      DEBUG << "vertex " << vertex << " getBoundaryBackwardNeighbors passed!\n";
    }
  }
  for (size_t vertex = 0; vertex < 10; ++vertex) {
  //for (const auto& kv : interior_backward_neighbors) {
    //const size_t vertex = kv.first;
    if (!interior_backward_neighbors.count(vertex)) {
      if (bd.getIBN(vertex) != std::vector<size_t>()) {
        DEBUG << "vertex " << vertex << " getInteriorBackwardNeighbors failed!\n";
        res = false;
        break;
      } else {
        DEBUG << "vertex " << vertex << " getInteriorBackwardNeighbors passed!\n";
      }
      continue;
    }
    if (interior_backward_neighbors.at(vertex) != bd.getIBN(vertex)) {
      DEBUG << "vertex " << vertex << " getInteriorBackwardNeighbors failed!\n";
      res = false;
      break;
    } else {
      DEBUG << "vertex " << vertex << " getInteriorBackwardNeighbors passed!\n";
    }
  }
  std::vector<std::vector<size_t>> mappers = {
    {0, 5, 4, 3, 2, 1}, /* vertical reflection */
    {3, 2, 1, 0, 5, 4}, /* horizontal reflection */
    {3, 4, 5, 0, 1, 2}, /* (counter)clockwise 180 degrees rotation */
  };
  for (size_t i = 0; i < mappers.size(); ++i) {
    if (mappers[i] != bd.getVS(i)) {
      DEBUG << i << "th getVertexSymmetry failed!\n";
      res = false;
      break;
    } else {
      DEBUG << i << "th getVertexSymmetry passed!\n";
    }
  }
  std::vector<std::pair<size_t, size_t>> cuts = bd.getBoundarySeparatedVertexPairs(1, 3);
  dict_sort<size_t>(cuts);
  const std::vector<std::pair<size_t, size_t>> exp_cuts = {{2, 0}, {2, 4}, {2, 5}};
  INFO_VII(cuts)
  INFO_VII(exp_cuts)
  if (cuts != exp_cuts) {
    INFO << "cuts != exp_cuts\n";
  }
  res = res && (cuts == exp_cuts);
  const auto& pairs = bd.getBoundarySeparatedVertexPairs(0, 4);
  DEBUG_VAR(pairs.size())
  res = res && (pairs.size() == 3);
  PGC__DEBUG_VII(std::cout, pairs)
  const auto& qairs = bd.getBoundarySeparatedVertexPairs(1, 4);
  DEBUG_VAR(qairs.size())
  res = res && (qairs.size() == 4);
  PGC__DEBUG_VII(std::cout, qairs)
TEST_END(0)
/// test_0

/// test_1
TEST_START(1)
  BirkhoffDiamond diamond;
  DEBUG_OBJ(diamond);
  auto ring = diamond.shrinkToRing();
  INFO_OBJ(ring)
  bool res = (ring.size() == 6);
TEST_END(1)
/// test_1

PGC__MAIN_START
  test_0();
  test_1();
PGC__MAIN_END
