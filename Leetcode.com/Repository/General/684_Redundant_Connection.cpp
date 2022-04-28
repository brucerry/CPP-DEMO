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
    
    for (int i = 1; i <= n; i++) {
      parents[i] = i;
    }
    
    for (const auto& edge : edges) {
      if (!unionNodes(parents, ranks, edge))
        return edge;
    }
    
    return {};
  }
  
private:
  int findParent(vector<int>& parents, int node) {
    while (node != parents[node]) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }
  
  bool unionNodes(vector<int>& parents, vector<int>& ranks, const vector<int>& edge) {
    const int& node1 = edge[0];
    const int& node2 = edge[1];
    int parent1 = findParent(parents, node1);
    int parent2 = findParent(parents, node2);
  
    if (parent1 == parent2)
      return false;
    
    if (ranks[parent1] > ranks[parent2]) {
      parents[parent2] = parent1;
      ranks[parent1] += ranks[parent2];
    }
    else {
      parents[parent1] = parent2;
      ranks[parent2] += ranks[parent1];
    }
    
    return true;
  }
};