// https://leetcode.com/problems/number-of-good-paths/

#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// time: O(n)
// space: O(n)

class UnionFind {
public:
  UnionFind(int n) {
    for (int node = 0; node < n; node++) {
      parents.emplace_back(node);
      ranks.emplace_back(1);
    }
  }

  void unionNodes(int node1, int node2) {
    int parent1 = findParent(node1), parent2 = findParent(node2);
    if (parent1 == parent2)
      return;

    if (ranks[parent1] > ranks[parent2]) {
      ranks[parent1] += ranks[parent2];
      parents[parent2] = parent1;
    }
    else {
      ranks[parent2] += ranks[parent1];
      parents[parent1] = parent2;
    }
  }

  int findParent(int node) {
    while (node != parents[node]) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }

private:
  vector<int> parents, ranks;
};

class Solution {
public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int n = vals.size();

    map<int, vector<int>> valGroups;
    for (int node = 0; node < n; node++) {
      valGroups[vals[node]].emplace_back(node);
    }

    vector<vector<int>> graph (n);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      if (vals[u] >= vals[v])
        graph[u].emplace_back(v);
      else if (vals[v] >= vals[u])
        graph[v].emplace_back(u);
    }

    UnionFind uf (n);

    int goodPaths = 0;
    unordered_map<int, int> parentCount;
    
    for (const auto& [ _, nodes ] : valGroups) {
      for (const int& node : nodes) {
        for (const int& neighbor : graph[node]) {
          uf.unionNodes(node, neighbor);
        }
      }

      parentCount = {};
      for (const int& node : nodes) {
        parentCount[uf.findParent(node)]++;
      }

      goodPaths += nodes.size();
      for (const auto& [ _, count ] : parentCount) {
        goodPaths += count * (count - 1) / 2;
      }
    }

    return goodPaths;
  }
};