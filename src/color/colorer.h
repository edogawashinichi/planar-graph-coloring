/// colorer.h

#pragma once

#include "../topology/ring.h"
#include "ring_coloring_result.h"

namespace PlanarGraphColoring {

class Colorer {
public:
  inline void run(const Ring& ring, RingColoringResult* colorings) {
    this->colorBoundary(ring, colorings);
    this->colorInterior(ring, colorings);
  }/// run
  inline void colorBoundary(const Ring& ring, RingColoringResult* colorings) {
    DEBUG_START(Colorer::colorBoundary)
    RingColoring coloring(ring.boundarySize(), ring.interiorSize());
    this->colorBoundaryDFS(ring, 0, &coloring, colorings);
    DEBUG_END(Colorer::colorBoundary)
  }/// colorBoundary
  inline void colorInterior(const Ring& ring, RingColoringResult* colorings) {
    DEBUG_START(Colorer::colorInterior)
    for (size_t i = 0; i < colorings->size(); ++i) {
      DEBUG_VAR(i)
      this->colorInterior(ring, &(colorings->get(i)));
    }
    DEBUG_END(Colorer::colorInterior)
  }/// colorInterior
  inline bool colorInterior(const Ring& ring, RingColoring* coloring) {
    DEBUG_START(Colorer::colorInterior)
    const bool res = this->colorInteriorDFS(ring, ring.boundarySize(), coloring);
    DEBUG_END(Colorer::colorInterior)
    return res;
  }/// colorInterior
protected:
  inline void getUnusedColors(const Ring& ring, const RingColoring& coloring, const size_t vertex, VI* unused_colors) {
    const VI& neighbors = ring.getNeighbors(vertex);
    DEBUG_VEC(neighbors)
    VI used_colors;
    map<size_t>(neighbors, coloring.copyData(), &used_colors);
    DEBUG_VEC(used_colors)
    diff<size_t>(id<size_t>(COLORS.size()), used_colors, unused_colors);
    DEBUG_VEC(*unused_colors)
  }/// getUnusedColors
  inline bool colorInteriorDFS(const Ring& ring, const size_t start_vertex, RingColoring* coloring) {
    DEBUG_START(Colorer::colorInteriorDFS)
    DEBUG_VAR(start_vertex)
    if (start_vertex == ring.size()) {
      DEBUG_(*coloring)
      DEBUG_END(Colorer::colorInteriorDFS)
      return true;
    }
    bool res = false;
    VI unused_colors;
    this->getUnusedColors(ring, *coloring, start_vertex, &unused_colors);
    for (const size_t color : unused_colors) {
      coloring->get(start_vertex) = std::move(Color(color));
      res = this->colorInteriorDFS(ring, start_vertex + 1, coloring);
      if (res) break;
      coloring->get(start_vertex) = std::move(Color(UNDEF_COLOR));
    }/// for
    DEBUG_END(Colorer::colorInteriorDFS)
    return res;
  }/// colorInteriorDFS
  inline void colorBoundaryDFS(const Ring& ring, const size_t start_vertex, RingColoring* coloring, RingColoringResult* colorings) {
    DEBUG_START(Colorer::colorBoundaryDFS)
    DEBUG_VAR(start_vertex)
    if (start_vertex == coloring->boundarySize()) {
      colorings->append(*coloring);
      DEBUG_(*coloring)
      DEBUG_VAR(colorings->size())
      DEBUG_END(Colorer::colorBoundaryDFS)
      return;
    }
    VI unused_colors;
    this->getUnusedColors(ring, *coloring, start_vertex, &unused_colors);
    for (const size_t color : unused_colors) {
      coloring->get(start_vertex) = std::move(Color(color));
      this->colorBoundaryDFS(ring, start_vertex + 1, coloring, colorings);
      coloring->get(start_vertex) = std::move(Color(UNDEF_COLOR));
    }/// for
    DEBUG_END(Colorer::colorBoundaryDFS)
  }/// colorBoundaryDFS
};/// class Colorer

}/// namespace PlanarGraphColoring
