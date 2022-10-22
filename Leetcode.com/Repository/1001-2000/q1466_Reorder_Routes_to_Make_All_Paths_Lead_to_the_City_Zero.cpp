// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph (n);
    for (const auto& conn : connections) {
      graph[conn[0]].emplace_back(conn[1]);
      graph[conn[1]].emplace_back(-conn[0]);
    }
    return dfs(graph, 0, 0);
  }

private:
  int dfs(vector<vector<int>>& graph, int prev, int node) {
    int change = 0;
    for (const int& neighbor : graph[node]) {
      if (prev != abs(neighbor))
        change += dfs(graph, node, abs(neighbor)) + (neighbor > 0);
    }
    return change;
  }
};