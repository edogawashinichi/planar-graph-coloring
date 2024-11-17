/// digraph_searcher.cxx

#include "digraph_searcher.h"
#include "dijktra/dijkstra.h"

namespace PlanarGraphColoring {

void DigraphSearcher::dfs(const Structure& structure, SearcherResult* searcher_result) {
  auto digraph = dynamic_cast<const Digraph&>(structure);
  auto digraph_searcher_result = dynamic_cast<DigraphSearcherResult*>(searcher_result);
  const size_t n = digraph.size();
  std::vector<int> visited(n, 0);
  for (size_t vertex = 0; vertex < n; ++vertex) {
    if (visited[vertex]) continue;
    visited[vertex] = 1;
    digraph_searcher_result->appendWeakComponent(vertex);
    dfsHelper(digraph, vertex, visited, digraph_searcher_result);
  }
}/// DigraphSearcher::dfs

void DigraphSearcher::dfsHelper(const Digraph& digraph, const size_t vertex, std::vector<int>& visited, DigraphSearcherResult* digraph_searcher_result) {
  for (const auto succ : digraph.getSuccessors(vertex)) {
    if (visited[succ]) continue;
    visited[succ] = 1;
    digraph_searcher_result->extendWeakComponent(succ);
    dfsHelper(digraph, succ, visited, digraph_searcher_result);
  }
  for (const auto pred : digraph.getPredecessors(vertex)) {
    if (visited[pred]) continue;
    visited[pred] = 1;
    digraph_searcher_result->extendWeakComponent(pred);
    dfsHelper(digraph, pred, visited, digraph_searcher_result);
  }
}/// DigraphSearcher::dfsHelper

void DigraphSearcher::bfs(const Structure& structure, SearcherResult* searcher_result) {
  /// TODO
}/// DigraphSearcher::bfs

void DigraphSearcher::greedy(const Structure& structure, SearcherResult* searcher_result) {
  /// TODO
}/// DigraphSearcher::greedy

void DigraphSearcher::dijkstra(const Structure& structure, SearcherResult* searcher_result) {
  /// TODO
  auto digraph = dynamic_cast<const Digraph&>(structure);
  auto digraph_searcher_result = dynamic_cast<DigraphSearcherResult*>(searcher_result);
  Dijktra dijkstra;
  dijkstra.run(digraph, digraph_searcher_result);
}/// DigraphSearcher::dijkstra

}/// namespace PlanarGraphColoring
