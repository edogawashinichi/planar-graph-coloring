/// graph.cxx

#include "graph.h"
#include "notation.h"
#include "math.h"

#define INSERT(u, v) \
if (neighbors_.count(u)) {\
  neighbors_[u].push_back(v);\
} else {\
  neighbors_.insert({u, {v}});\
}

namespace PlanarGraphColoring {

void Graph::deleteVertex(const size_t vertex, const bool resize) {
  VERBOSE_START(Graph::deleteVertex)
  auto iter = neighbors_.begin();
  while (iter != neighbors_.end()) {
    if (iter->first == vertex) {
      neighbors_.erase(iter++);/// WARNING
    } else {
      auto jter = iter->second.begin();
      while (jter != iter->second.end()) {
        if (*jter == vertex) {
          iter->second.erase(jter);/// WARNING
        } else {
          ++jter;/// WARNING
        }/// *jter != vertex
      }/// while jter
      ++iter;/// WARNING
    }/// else iter->first != vertex
  }/// while iter
  if (resize && (vertex == n_ - 1)) {
    --n_;
  }
  VERBOSE_END(Graph::deleteVertex)
}/// Graph::deleteVertex
void Graph::deleteVertices(const VI& vertices, const bool resize) {
  VERBOSE_START(Graph::deleteVertices)
  auto iter = neighbors_.begin();
  while (iter != neighbors_.end()) {
    if (std::find(vertices.begin(), vertices.end(), iter->first) != vertices.end()) {
      neighbors_.erase(iter++);/// WARNING
    } else {
      auto jter = iter->second.begin();
      while (jter != iter->second.end()) {
        if (std::find(vertices.begin(), vertices.end(), *jter) != vertices.end()) {
          iter->second.erase(jter);/// WARNING
        } else {
          ++jter;/// WARNING
        }/// else
      }/// while jter
      ++iter;/// WARNING
    }/// else iter->first notin vertices
  }/// while iter
  if (resize && (std::find(vertices.begin(), vertices.end(), n_ - 1) != vertices.end())) {
    --n_;
  }
  VERBOSE_END(Graph::deleteVertices)
}/// Graph::deleteVertices
void Graph::deleteVerticesAtLeast(const size_t vertex, const bool resize) {
  VERBOSE_START(Graph::deleteVerticesAtLeast)
  auto iter = neighbors_.begin();
  while (iter != neighbors_.end()) {
    if (iter->first >= vertex) {
      VERBOSE << "if\n";
      neighbors_.erase(iter++);/// WARNING
    } else {
      VERBOSE << "else\n";
      auto jter = iter->second.begin();
      while (jter != iter->second.end()) {
        if (*jter >= vertex) {
          iter->second.erase(jter);/// WARNING
        } else {
          ++jter;/// WARNING
        }/// *jter < vertex
      }/// while jter
      ++iter;/// WARNING
    }/// else iter->first < vertex
  }/// while iter
  if (resize) {
    n_ = vertex;
  }
  VERBOSE_END(Graph::deleteVerticesAtLeast)
}

bool Graph::isPlanarGraph() const {
  /// TODO: isPlanarGraph
  return true;
}/// Graph::isPlanarGraph

bool Graph::isRing(const size_t k) const {
  bool res = true;
  for (int i = 0; i < static_cast<int>(k); ++i) {
    if (this->containEdge(i, (i + 1) % static_cast<int>(k))) continue;
    res = false;
    break;
  }/// for
  return res;
}/// Graph::isRing

void Graph::setSize(const size_t n) {
  n_ = n;
  auto it = neighbors_.begin();
  while (it != neighbors_.end()) {
    if (it->first >= n) {
      neighbors_.erase(it++);/// WARNING
    } else {
      auto jt = it->second.begin();
      while (jt != it->second.end()) {
        if (*jt >= n) {
          it->second.erase(jt);/// WARNING
        } else {
          ++jt;
        }/// else *jt < n
      }/// while jt
      ++it;
    }/// else it->first < n
  }/// while it
}/// Graph::setSize 

void Graph::addEdge(const size_t i, const size_t j) {
  this->addUniNeighbor(i, j);
  this->addUniNeighbor(j, i);
}/// Graph::addEdge

void Graph::addUniNeighbor(const size_t i, const size_t j) {
  if (neighbors_.count(i)) {
    neighbors_[i].emplace_back(j);
  } else {
    neighbors_[i] = {j};
  }
}/// Graph::addUniNeighbor

bool Graph::containEdge(const size_t i, const size_t j) const {
  bool res = false;
  if (neighbors_.count(i)) {
    for (const auto& ele : neighbors_.at(i)) {
      if (ele != j) continue;
      res = true;
      break;
    }/// for
  }/// if
  return res;
}/// Graph::containEdge

const std::vector<std::vector<size_t>> Graph::getNeighborsInfo() const {
  VERBOSE_START(Graph::getNeighborsInfo)
  std::vector<std::vector<size_t>> res(n_, std::vector<size_t>());
  for (const auto& kv : neighbors_) {
    std::vector<size_t> vec(kv.second);
    std::sort(vec.begin(), vec.end());
    res[kv.first] = vec;
  }/// for
  //dict_sort(res); /* WARNING: radix sort */
  VERBOSE_END(Graph::getNeighborsInfo)
  return res;
}/// Graph::getNeighborsInfo

VII Graph::getEdges() const {
  VII res;
  for (const auto& kv : neighbors_) {
    const size_t u = kv.first;
    for (const auto& v : kv.second) {
      if (u >= v) continue;
      res.emplace_back(std::pair<size_t, size_t>({u, v}));
    }/// v
  }/// for kv
  dict_sort(res);
  return res;
}/// Graph::getEdges

void Graph::clear() {
  n_ = 0;
  neighbors_.clear();
}/// Graph::clear

bool Graph::contain(const size_t u, const size_t v) const {
  bool res = false;
  if (neighbors_.count(u)) {
    for (const auto& w : neighbors_.at(u)) {
      if (w != v) continue;
      res = true;
      break;
    }
  }
  return res;
}/// Graph::contain

void Graph::insert(const size_t u, const size_t v) {
  if (neighbors_.count(u)) {
    neighbors_[u].emplace_back(v);
  } else {
    neighbors_[u] = std::vector<size_t>({v});
  }
}/// Graph::insert

Graph::Graph(const Graph& rhs) {
  n_ = rhs.n_;
  neighbors_ = rhs.neighbors_;
}/// Graph::Graph deepcopy
Graph::Graph(Graph&& rhs) {
  std::swap(n_, rhs.n_);
  neighbors_.swap(rhs.neighbors_);
}/// Graph::Graph movecopy
Graph& Graph::operator=(const Graph& rhs) {
  n_ = rhs.n_;
  neighbors_ = rhs.neighbors_;
  return *this;
}/// Graph::operator= assignment deepcopy
Graph& Graph::operator=(Graph&& rhs) {
  std::swap(n_, rhs.n_);
  neighbors_.swap(rhs.neighbors_);
  return *this;
}/// Graph::operator= assignment movecopy

Graph::Graph(const std::vector<std::vector<size_t>>& edges) {
  n_ = 0;
  neighbors_.clear();
  for (const auto& edge : edges) {
    const size_t u = edge[0];
    const size_t v = edge[1];
    n_ = max(n_, u + 1, v + 1);
    INSERT(u, v)
    INSERT(v, u)
  }
}/// Graph::Graph

Graph::Graph(const size_t n, const std::vector<std::vector<size_t>>& edges) {
  n_ = n;
  neighbors_.clear();
  for (const auto& edge : edges) {
    const size_t u = edge[0];
    const size_t v = edge[1];
    INSERT(u, v)
    INSERT(v, u)
  }
}/// Graph::Graph

/*
void Graph::show() const {
  TEST_INFO
  std::cout << "number of vertices: " << n_ << "\n";
  std::cout << "neighbors:\n";
  const std::vector<std::vector<size_t>> neighbors(this->getNeighborsInfo());
  VERBOSE_VAR(neighbors.size())
  for (size_t i = 0; i < neighbors.size(); ++i) {
    const auto& vec = neighbors[i];
    std::cout << i << ": { ";
    for (const auto v : vec) {
      std::cout << v << " ";
    }
    std::cout << "}\n";
  }
}/// Graph::show
*/

void Graph::show(std::ostream& cout) const {
  TEST_INFO
  cout << "number of vertices: " << n_ << "\n";
  const VII& edges = this->getEdges();
  cout << "edges:  ";
  for (const auto& edge : edges) {
    cout << "(" << edge.first << "," << edge.second << ") ";
  }/// for
  cout << "\n";
}/// Graph::show

void Graph::show(std::ostream& cout, const size_t n) const {
  TEST_INFO
  cout << "number of vertices: " << n_ << "\n";
  cout << "neighbors:\n";
  size_t i = 0;
  for (const auto& kv : neighbors_) {
    if (i++ >= n) break;
    cout << kv.first << ": { ";
    for (const auto v : kv.second) {
      cout << v << " ";
    }
    cout << "}\n";
  }
}/// Graph::show

std::vector<size_t> Graph::getNeighbors(const size_t vertex) const{
  return neighbors_.count(vertex) ? neighbors_.at(vertex) : std::vector<size_t>();
}/// Graph::getNeighbors

}/// namespace PlanarGraphColoring
