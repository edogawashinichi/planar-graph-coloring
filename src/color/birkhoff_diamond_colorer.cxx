/// birkhoff_diamond_colorer.cxx

#include "birkhoff_diamond_colorer.h"
#include "../topology/birkhoff_diamond.h"
#include "../basic/math.h"
#include "../basic/notation.h" 

namespace PlanarGraphColoring {

void BirkhoffDiamondColorer::run(const Graph& birkhoff_diamond, ColorResult* output) {
  colorBoundary(birkhoff_diamond, output);
  colorInterior(birkhoff_diamond, output);
}/// BirkhoffDiamondColorer::run

bool BirkhoffDiamondColorer::colorInterior(const Graph& birkhoff_diamond, ColorResult* output) {
  if (PGC__DEBUG_MODE) {
    PGC__SHOW_ENDL("start colorInterior")
  }
  const BirkhoffDiamond& derived = dynamic_cast<const BirkhoffDiamond&>(birkhoff_diamond);
  bool res = false;
  for (size_t i = 0; i < output->size(); ++i) {
    ColorRepresentation* color = output->get(i);
    bool tmp = colorInterior(derived, color);
    res = res || tmp;
    /// WARNING: logic operation shortcut
    //res = res || colorInterior(derived, color);
  }
  if (PGC__DEBUG_MODE) {
    output->show(20);
    PGC__SHOW_ENDL("end colorInterior")
  }
  return res;
}/// BirkhoffDiamondColorer::colorInterior

bool BirkhoffDiamondColorer::colorInterior(const BirkhoffDiamond& birkhoff_diamond, ColorRepresentation* color) {
  return colorInteriorDFS(birkhoff_diamond, birkhoff_diamond.boundarySize(), color);
}/// BirkhoffDiamondColorer::colorInterior

bool BirkhoffDiamondColorer::colorInteriorDFS(const BirkhoffDiamond& birkhoff_diamond, const size_t cur_index, ColorRepresentation* color) {
  if (cur_index == birkhoff_diamond.size()) return true;
  const auto& ibn = birkhoff_diamond.getIBN(cur_index);/// interior backward neighbors
  std::vector<size_t> used_colors(birkhoff_diamond.size(), UNDEF_COLOR);
  map<size_t>(ibn, color->getVector(), &used_colors);
  const std::vector<size_t> all_colors(id<size_t>(COLORS));
  std::vector<size_t> unused_colors;
  diff<size_t>(all_colors, used_colors, &unused_colors);
  for (const auto unused_color : unused_colors) {
    color->set(cur_index, unused_color);
    bool res = colorInteriorDFS(birkhoff_diamond, cur_index + 1, color);
    if (res) return true;
    color->reset(cur_index);
  }/// for unused_colors
  return false;
}/// Colorer::colorInteriorDFS

void BirkhoffDiamondColorer::colorBoundary(const Graph& birkhoff_diamond, ColorResult* output) {
  if (PGC__DEBUG_MODE) {
    PGC__SHOW_ENDL("start colorBoundary")
  }
  const BirkhoffDiamond& derived = dynamic_cast<const BirkhoffDiamond&>(birkhoff_diamond);
  std::vector<size_t> state(derived.size(), UNDEF_COLOR);
  colorBoundaryDFS(derived, state, 0, output);
  if (PGC__DEBUG_MODE) {
    PGC__SHOW_ENDL("output:")
    output->show(20);
    PGC__SHOW_ENDL("end colorBoundary")
  }
}/// BirkhoffDiamondColorer::colorBoundary

void BirkhoffDiamondColorer::colorBoundaryDFS(const BirkhoffDiamond& birkhoff_diamond, std::vector<size_t>& state, const size_t cur_index, ColorResult* output) {
  DEBUG << "colorBoundaryDFS cur_index: " << cur_index << "\n";
  if (cur_index == birkhoff_diamond.boundarySize()) {
    output->append(state);
    return;
  }
  const auto& bbn = birkhoff_diamond.getBBN(cur_index);/// boundary_backward_neighbors
  std::vector<size_t> used_colors(bbn.size(), UNDEF_COLOR);
  map<size_t>(bbn, state, &used_colors);
  const std::vector<size_t> all_colors(id<size_t>(COLORS));
  std::vector<size_t> unused_colors;
  diff<size_t>(all_colors, used_colors, &unused_colors);
  for (const auto unused_color : unused_colors) {
    state[cur_index] = unused_color;
    colorBoundaryDFS(birkhoff_diamond, state, cur_index + 1, output);
    state[cur_index] = UNDEF_COLOR;
  }/// for unused_colors
}/// BirkhoffDiamondColorer::colorBoundaryDFS

}/// namespace PlanarGraphColoring
