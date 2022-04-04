// https://leetcode.com/problems/graph-valid-tree/
// https://www.lintcode.com/problem/178/

#include <vector>
#include <unordered_set>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
private:
  bool explore(vector<vector<int>>& graph, int node, int prevNode, unordered_set<int> &visited) {
    if (visited.count(node)) return false;
    visited.insert(node);

    for (const int& neighbor : graph[node]) {
      if (neighbor != prevNode && !explore(graph, neighbor, node, visited)) return false;
    }

    return true;
  }

public:
  bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph (n, vector<int>());

    for (const auto& edge : edges) {
      int a = edge[0];
      int b = edge[1];
      graph[a].emplace_back(b);
      graph[b].emplace_back(a);
    }

    unordered_set<int> visited;

    bool valid = explore(graph, 0, -1, visited);

    return valid && visited.size() == n;
  }
};