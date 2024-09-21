# Python code is deleted accidently
# continue to realize cpp version

dijkstraReasonIsomorphism(index1, index2)
    if res:
      print(self.explainPath())
    print("finish reason isomorphism from " + str(coloring1) + " to " + str(coloring2))
  def dijkstraReasonIsomorphism(self, start, end):
    print("start dijkstra start:" + str(start) + " end:" + str(end))
    visited = [0] * self.N()
    inQ = [0] * self.N()
    prev = [-1] * self.N()
    nodes = [DijkstraNode(i, 0) for i in range(self.N())]
    Q = queue.PriorityQueue()
    Q.put(nodes[start])
    visited[start], inQ[start], SIZE = 1, 1, 1
    while not Q.empty():
      print("Q size: " + str(SIZE))
      top = Q.get()
      inQ[top.index] = 0
      SIZE -= 1
      print("pop: " + str(top.index) + "/" + str(top.dist))
      for neighbor in self.neighbors[top.index]:
        v, w = neighbor[0], neighbor[1]
        if 0 == visited[v]:
          nodes[v].dist = top.dist + 1
          Q.put(nodes[v])
          SIZE += 1
          visited[v], inQ[v] = 1, 1
          print("put: " + str(v) + "/" + str(nodes[v].dist))
        elif 1 == inQ[v]:
          old = nodes[v].dist
          nodes[v].dist = min(nodes[v].dist, top.dist + 1)
          print("update: " + str(v) + " from " + str(old) + " to " + str(nodes[v].dist))
    print("finish dijkstra start:" + str(start) + " end:" + str(end))
  def dfsReasonIsomorphism(self, index1, index2):
    # TODO: refine DFS to Dijkstra
    print("dfs " + str(index1) + " -> " + str(index2))
    self.path.append(index1)
    self.visited[index1] = 1
    if index1 == index2:
      return True
    for neighbor in self.neighbors[index1]:
      v, w = neighbor[0], neighbor[1]
      if self.visited[v] == 1:
        continue
      self.path.append([index1, v, w])
      res = self.dfsReasonIsomorphism(v, index2)
      if res:
        return True
      self.path.pop()
    self.path.pop()
    return False
  def component(self):
    n = len(self.colorer.colorings)
    self.visited = [0] * n
    for i in range(n):
      if 0 == self.visited[i]:
        self.comps.append([])
        self.dfs(i)
  def dfs(self, vertex):
    self.comps[-1].append(vertex)
    self.visited[vertex] = 1
    for edge in self.edges:
      u, v = edge[0], edge[1]
      if u == vertex and 0 == self.visited[v]:
        self.dfs(v)
      if v == vertex and 0 == self.visited[u]:
        self.dfs(u)
  def explainPath(self):
    path = []
    for i in range(len(self.path)):
      if i % 2 == 0:
        coloring = self.colorer.colorings[self.path[i]]
        path.append(copy.deepcopy(coloring))
      else:
        msg = self.path[i][2]
        path.append(copy.deepcopy(msg))
    return path
  def reasonReducibleAllIndex(self):
    n = len(self.colorer.colorings)
    for i in range(n):
      self.reasonReducibleIndex(i)
  def reasonReducibleIndex(self, index):
    print("reason reducible index: " + str(index))
    coloring = self.colorer.colorings[index]
    self.reasonReducible(coloring)
  def reasonReducible(self, coloring):
    index = self.colorer.index(coloring)
    self.path = []
    self.visited = [0] * len(self.colorer.colorings)
    res = self.dfsReason(index)
    print("reason reducible: " + str(res) + " for " + str(coloring))
    if res and len(self.path) > 2:
      path = self.explainPath()
      print(path)
  def dfsReason(self, index):
    self.path.append(index)
    self.visited[index] = 1
    if self.reducible[index] == 1:
      return True
    for edge in self.edges:
      u, v, w = edge[0], edge[1], edge[2]
      if u == index and 0 == self.visited[v]:
        self.path.append(edge)
        res = self.dfsReason(v)
        if res:
          return True
      elif v == index and 0 == self.visited[u]:
        self.path.append(edge)
        res = self.dfsReason(u)
        if res:
          return True
    return False
    
  def showCompsReducible(self):
    print("start show component reducible size: " + str(len(self.comps)))
    __show_each_with_size_and_attr__(self.comps, self.reducible)
    print("finish show component reducible size: " + str(len(self.comps)))
  def showReducible(self):
    print("start show reducible size: " + str(len(self.reducible)))
    __show1__(self.reducible)
    print("finish show reducible size: " + str(len(self.reducible)))
  def showComps(self):
    print("start show component size: " + str(len(self.comps)))
    __show_each_with_size__(self.comps)
    print("finish show component size: " + str(len(self.comps)))
  def showColorings(self, n):
    print("start show random " + str(n) + " of " + str(len(self.colorer.colorings)) + " colorings:")
    __show_random__(self.colorer.colorings, n)
    print("finish show random " + str(n) + " of " + str(len(self.colorer.colorings)) + " colorings:")
  def showEdges(self, n):
    print("start show random " + str(n) + " of " + str(len(self.edges)) + " edges:")
    __show_random__(self.edges, n)
    print("finish show random " + str(n) + " of " + str(len(self.edges)) + " edges:")

if __name__ == '__main__':
  symmetry_graph = SymmetryGraph()
  symmetry_graph.showColorings(20)
  symmetry_graph.showEdges(10)
  symmetry_graph.showComps()
  symmetry_graph.showReducible()
  symmetry_graph.showCompsReducible()
  #symmetry_graph.reasonReducible([1,0,1,0,1,0])
  #symmetry_graph.reasonReducible([0,1,2,3,0,1])
  #symmetry_graph.reasonReducibleAllIndex()
  symmetry_graph.reasonIsomorphismIndex(39, 692)
