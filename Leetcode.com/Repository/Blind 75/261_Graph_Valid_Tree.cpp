// https://leetcode.com/problems/graph-valid-tree/
// https://www.lintcode.com/problem/178/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  bool validTree(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph (n);
    for (const auto& edge : edges) {
      int a = edge[0];
      int b = edge[1];
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

    unordered_set<int> visited;
    return !hasCycle(graph, -1, 0, visited) and visited.size() == n;
  }

private:
  bool hasCycle(vector<vector<int>>& graph, int prev, int node, unordered_set<int>& visited) {
    if (visited.count(node))
      return true;

    visited.emplace(node);

    for (const int& neighbor : graph[node]) {
      if (prev != neighbor and hasCycle(graph, node, neighbor, visited))
        return true;
    }

    return false;
  }
};