// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include <vector>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1)
      return -1;

    vector<vector<int>> graph (n);
    for (const auto& conn : connections) {
      int u = conn[0], v = conn[1];
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }

    vector<char> visited (n);
    int groups = 0;
    for (int node = 0; node < n; node++) {
      groups += traverse(graph, visited, node);
    }

    return groups - 1;
  }

private:
  bool traverse(vector<vector<int>>& graph, vector<char>& visited, int node) {
    if (visited[node])
      return false;
    visited[node] = true;

    for (const int& neighbor : graph[node]) {
      traverse(graph, visited, neighbor);
    }

    return true;
  }
};