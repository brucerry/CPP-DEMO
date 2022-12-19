// https://leetcode.com/problems/find-if-path-exists-in-graph/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
    vector<int> graph[200000];
    int visited[200000] {};
    for (const auto& e : edges) {
      int u = e[0], v = e[1];
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
    return solve(graph, visited, src, dest);
  }

private:
  bool solve(vector<int>* graph, int* visited, int src, int dest) {
    if (src == dest)
      return true;

    if (visited[src])
      return false;
    visited[src] = 1;

    for (const int& neighbor : graph[src]) {
      if (solve(graph, visited, neighbor, dest))
        return true;
    }

    return false;
  }
};