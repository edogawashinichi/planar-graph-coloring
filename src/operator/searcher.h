/// searcher.h

#pragma once

#include "../basic/structure.h"
#include "searcher_result.h"

namespace PlanarGraphColoring {

class Searcher {
public:
  virtual void dfs(const Structure& structure, SearcherResult* searcher_result) = 0;
  virtual void bfs(const Structure& structure, SearcherResult* searcher_result) = 0;
  virtual void greedy(const Structure& structure, SearcherResult* searcher_result) = 0;
  virtual void dijkstra(const Structure& structure, SearcherResult* searcher_result) = 0;
};/// class Searcher

}/// namespace PlanarGraphColoring
