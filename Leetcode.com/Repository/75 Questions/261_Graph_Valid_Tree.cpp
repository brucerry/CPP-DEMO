// https://leetcode.com/problems/graph-valid-tree/

// https://www.lintcode.com/problem/178/
// https://www.youtube.com/watch?v=bXsUuownnoQ

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
private:
  unordered_map<int, vector<int>> buildGraph(vector<vector<int>> edges) {
    unordered_map<int, vector<int>> graph;
    for (auto& edge : edges) {
      int a = edge[0];
      int b = edge[1];
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    return graph;
  }

  bool exploreAllNodes(unordered_map<int, vector<int>>& graph, int node, int prevNode, unordered_set<int> &visited) {
    if (visited.count(node)) return false;
    visited.insert(node);

    for (auto neighbor : graph[node]) {
      if (neighbor != prevNode && !exploreAllNodes(graph, neighbor, node, visited)) return false;
    }

    return true;
  }

public:
  bool validTree(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> graph = buildGraph(edges);
    unordered_set<int> visited;

    bool valid = exploreAllNodes(graph, 0, -1, visited);

    return valid && visited.size() == n;
  }
};