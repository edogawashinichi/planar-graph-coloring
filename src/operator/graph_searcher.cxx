/// graph_searcher.cxx

#include "graph_searcher.h"
#include "graph_searcher_result.h"
#include "../basic/graph.h"
#include "../basic/random.h"
#include <queue>
#include <unordered_set>

namespace PlanarGraphColoring {

void GraphSearcher::dfs(const Structure& structure, SearcherResult* searcher_result) {
  /// TODO: GraphSearcher::dfs
}/// GraphSearcher::dfs

void GraphSearcher::bfs(const Structure& structure, SearcherResult* searcher_result) {
  /// TODO: GraphSearcher::bfs
}/// GraphSearcher::bfs

void GraphSearcher::bibfs(const Structure& structure, const II& vertex_pair, SearcherResult* searcher_result) {
  /// assuming: vertex_pair distinct
  DEBUG_START(GraphSearcher::bibfs)
  DEBUG_PAIR(vertex_pair)
  auto graph = dynamic_cast<const Graph&>(structure);
  auto graph_searcher_result = dynamic_cast<GraphSearcherResult*>(searcher_result);
  const size_t u = vertex_pair.first;
  const size_t v = vertex_pair.second;
  std::queue<size_t> qu, qv;
  std::unordered_set<size_t> compu, compv;
  VI visited(graph.size(), 0);
  qu.push(u);
  qv.push(v);
  compu.insert(u);
  compv.insert(v);
  visited[u] = visited[v] = 1;
  bool connected = false;
  while (!qu.empty() || !qv.empty()) {
    float probability = 0.5f;
    if (qu.empty()) {
      probability = 0.0f;
    } else if (qv.empty()) {
      probability = 1.0f;
    }
    if (bet(probability)) {
      const auto front = qu.front();
      qu.pop();
      for (const auto neighbor : graph.getNeighbors(front)) {
        if (neighbor == v) connected = true;
        if (visited[neighbor]) continue;
        qu.push(neighbor);
        compu.insert(neighbor);
        visited[neighbor] = 1;
      }/// for neighbor
    } else {
      const auto front = qv.front();
      qv.pop();
      for (const auto neighbor : graph.getNeighbors(front))  {
      if (neighbor == u) connected = true;
      if (visited[neighbor]) continue;
      qv.push(neighbor);
      compv.insert(neighbor);
      visited[neighbor] = 1;
      /// TODO: use macro
      }/// for neighbor
    }
  }/// while
  if (connected) {
    compu.insert(compv.begin(), compv.end());
    graph_searcher_result->appendComponent(compu);
  } else {
    graph_searcher_result->appendComponent(compu);
    graph_searcher_result->appendComponent(compv);
  }
  DEBUG_END(GraphSearcher::bibfs)
}/// GraphSearcher::bibfs

void GraphSearcher::greedy(const Structure& structure, SearcherResult* searcher_result) {
  /// TODO
}/// GraphSearcher::greedy

void GraphSearcher::dijkstra(const Structure& structure, SearcherResult* searcher_result) {
  /// TODO
}/// GraphSearcher::dijkstra

}/// namespace PlanarGraphColoring
