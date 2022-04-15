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
      graph[edge[0]].emplace_back(edge[1]);
      graph[edge[1]].emplace_back(edge[0]);
    }

    unordered_set<int> visited;

    return !hasCycle(graph, 0, -1, visited) && visited.size() == n;
  }

private:
  bool hasCycle(vector<vector<int>>& graph, int node, int prevNode, unordered_set<int>& visited) {
    if (visited.count(node))
      return true;

    visited.emplace(node);

    for (const int& neighbor : graph[node]) {
      if (neighbor != prevNode && hasCycle(graph, neighbor, node, visited))
        return true;
    }

    return false;
  }
};