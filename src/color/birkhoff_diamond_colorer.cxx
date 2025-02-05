/// birkhoff_diamond_colorer.cxx

#include "birkhoff_diamond_colorer.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/math.h"
#include "../basic/notation.h" 

/// TODO: class BirkhoffDiamondColorerColoring : public BirkhoffDiamondColoring
///       dealing with unused_colors / boundary interior index

namespace PlanarGraphColoring {

void BirkhoffDiamondColorer::run(const Graph& birkhoff_diamond, ConfigurationColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE, BIRKHOFF_DIAMOND_INTERIOR_SIZE>* birkhoff_diamond_coloring_result) {
  this->colorBoundary(birkhoff_diamond, birkhoff_diamond_coloring_result->getBoundaryColorings());
  this->colorInterior(birkhoff_diamond, *(birkhoff_diamond_coloring_result->getBoundaryColorings()), birkhoff_diamond_coloring_result->getInteriorColorings());
}/// BirkhoffDiamondColorer::run

void BirkhoffDiamondColorer::colorInterior(const Graph& graph, const ColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>& birkhoff_diamond_boundary_colorings, ColoringResult<BIRKHOFF_DIAMOND_INTERIOR_SIZE>* birkhoff_diamond_interior_colorings) {
  DEBUG_START(BirkhoffDiamondColorer::colorInterior)
  auto birkhoff_diamond = dynamic_cast<const BirkhoffDiamond&>(graph);
  const size_t n = birkhoff_diamond_boundary_colorings.size();
  birkhoff_diamond_interior_colorings->resize(n);
  for (size_t i = 0; i < n; ++i)
    this->colorInterior(birkhoff_diamond, birkhoff_diamond_boundary_colorings.getConst(i), &(birkhoff_diamond_interior_colorings->get(i)));
  }
  DEBUG_END(BirkhoffDiamondColorer::colorInterior)
}/// BirkhoffDiamondColorer::colorInterior

bool BirkhoffDiamondColorer::colorInterior(const BirkhoffDiamond& birkhoff_diamond, const Coloring<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>& birkhoff_diamond_boundary_coloring, Coloring<BIRKHOFF_DIAMOND_INTERIOR_SIZE>* birkhoff_diamond_interior_coloring) {
  Coloring coloring;
  splice<Color>(birkhoff_diamond_boundary_coloring.getConst(), birkhoff_diamond_interior_coloring->getConst(), &(coloring.get()));
  const bool res = this->colorInteriorDFS(birkhoff_diamond, birkhoff_diamond.boundarySize(), birkhoff_diamond.size(), &coloring);
  birkhoff_diamond_interior_coloring->set(coloring.getCopy(birkhoff_diamond.boundarySize(), birkhoff_diamond.size()));
  return res;
}/// BirkhoffDiamondColorer::colorInterior

bool BirkhoffDiamondColorer::colorInteriorDFS(const BirkhoffDiamond& birkhoff_diamond, const size_t start_index, const size_t end_index, Coloring<BIRKHOFF_DIAMOND_INTERIOR_SIZE>* coloring) {
  if (start_index == end_index) return true;
  VI unused_colors;
  this->getUnusedColors(birkhoff_diamond, coloring, start_index, &unused_colors);
  for (size_t unused_color : unused_colors) {
    coloring->get(start_index) = std::move(Color(unused_color));
    const bool res = this->colorInteriorDFS(birkhoff_diamond, start_index + 1, end_index, coloring);
    if (res) return true;
    coloring->get(start_index) = std::move(Color(UNDEF_COLOR));
  }/// for unused_colors
  return false;
}/// BirkhoffDiamondColorer::colorDFS

void BirkhoffDiamondColorer::getUnusedColors(const BirkhoffDiamond& birkhoff_diamond, const Coloring& coloring, const size_t vertex, Coloring* unused_colors) {
  const VI& neighbors = birkhoff_diamond.getNeighbors(vertex);
  VI used_colors;
  map<size_t>(neighbors, coloring, &used_colors);
  const VI all_colors(id<size_t>(COLORS.size()))
  diff<size_t>(all_colors, used_colors, unused_colors);
}/// BirkhoffDiamondColorer::getUnusedColors

void BirkhoffDiamondColorer::colorBoundary(const Graph& graph, ColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>* colorings) {
  DEBUG_START(BirkhoffDiamondColorer::colorBoundary)
  auto birkhoff_diamond = dynamic_cast<const BirkhoffDiamond&>(graph);
  Coloring<BIRKHOFF_DIAMOND_BOUNDARY_SIZE> coloring;
  this->colorBoundaryDFS(birkhoff_diamond, 0, birkhoff_diamond.boundarySize(), &coloring, &colorings);
  DEBUG_END(BirkhoffDiamondColorer::colorBoundary)
}/// BirkhoffDiamondColorer::colorBoundary

void BirkhoffDiamondColorer::colorBoundaryDFS(const BirkhoffDiamond& birkhoff_diamond, const size_t start_index, const size_t end_index, Coloring<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>* coloring , ColoringResult<BIRKHOFF_DIAMOND_BOUNDARY_SIZE>* colorings) {
  DEBUG_START(BirkhoffDiamondColorer::colorBoundaryDFS)
  if (start_index == end_index) {
    colorings->append(*coloring);
    return;
  }
  VI unused_colors;
  this->getUnusedColors(birkhoff_diamond, coloring->getData(), start_index, &unused_colors);
  for (const size_t unused_color : unused_colors) {
    coloring->get(start_index) = std::move(Color(unused_color));
    colorBoundaryDFS(birkhoff_diamond, start_index + 1, end_index, coloring, colorings);
    coloring->get(start_index) = std::move(Color(UNDEF_COLOR));
  }/// for unused_colors
  DEBUG_END(BirkhoffDiamondColorer::colorBoundaryDFS)
}/// BirkhoffDiamondColorer::colorBoundaryDFS

}/// namespace PlanarGraphColoring
