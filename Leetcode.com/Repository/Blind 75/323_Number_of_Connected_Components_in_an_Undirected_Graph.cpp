// https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n)
class UnionFind {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> parents (n);
    vector<int> ranks (n, 1);

    for (int node = 0; node < n; node++) {
      parents[node] = node;
    }

    for (const auto& edge : edges) {      
      n -= unionNodes(parents, ranks, edge);
    }

    return n;
  }

private:
  int findParent(vector<int>& parents, int node) {
    while (node != parents[node]) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }

  int unionNodes(vector<int>& parents, vector<int>& ranks, const vector<int>& edge) {
    int node1 = edge[0];
    int node2 = edge[1];
    
    int parent1 = findParent(parents, node1);
    int parent2 = findParent(parents, node2);

    if (parent1 == parent2)
      return 0;

    if (ranks[parent1] > ranks[parent2]) {
      parents[parent2] = parent1;
      ranks[parent1] += ranks[parent2];
    }
    else {
      parents[parent1] = parent2;
      ranks[parent2] += ranks[parent1];
    }

    return 1;
  }
};

// time: O(n + e)
// space: O(n)
class DFS {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph (n);
    for (const auto& edge : edges) {
      int a = edge[0];
      int b = edge[1];
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

    int component = 0;
    vector<char> visited (n);

    for (int node = 0; node < n; node++) {
      if (explore(graph, node, visited))
        component++;
    }

    return component;
  }

private:
  bool explore(vector<vector<int>>& graph, int node, vector<char>& visited) {
    if (visited[node])
      return false;

    visited[node] = 1;

    for (const int& neighbor : graph[node]) {
      explore(graph, neighbor, visited);
    }

    return true;
  }
};