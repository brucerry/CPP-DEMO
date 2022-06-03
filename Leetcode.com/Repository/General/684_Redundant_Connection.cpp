// https://leetcode.com/problems/redundant-connection/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    
    vector<int> parents (n + 1);
    vector<int> ranks (n + 1, 1);
    for (int node = 1; node <= n; node++)
      parents[node] = node;
    
    for (const auto& edge : edges) {
      int node1 = edge[0];
      int node2 = edge[1];
      if (!unionNodes(parents, ranks, node1, node2))
        return edge;
    }
    
    return {};
  }
  
private:
  bool unionNodes(vector<int>& parents, vector<int>& ranks, int node1, int node2) {
    int parent1 = findParent(parents, node1);
    int parent2 = findParent(parents, node2);
    
    if (parent1 == parent2)
      return false;
    
    if (ranks[parent1] > ranks[parent2]) {
      ranks[parent1] += ranks[parent2];
      parents[parent2] = parent1;
    }
    else {
      ranks[parent2] += ranks[parent1];
      parents[parent1] = parent2;
    }
    
    return true;
  }
  
  int findParent (vector<int>& parents, int node) {
    while (node != parents[node]) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }
};