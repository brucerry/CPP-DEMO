// https://leetcode.com/problems/redundant-connection-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    
    vector<int> parents (n + 1), edge_first, edge_second;
    for (auto& edge : edges) {
      int& parent = edge[0];
      int& child = edge[1];
      if (parents[child] == 0)
        parents[child] = parent;
      else {
        edge_first = { parents[child], child };
        edge_second = edge;
        child = 0;
        break;
      }
    }
    
    for (int node = 1; node <= n; node++)
      parents[node] = node;
    
    for (const auto& edge : edges) {
      int parent = edge[0];
      int child = edge[1];
      if (child == 0)
        continue;
      int root = findRoot(parents, parent);
      if (root == parents[child]) {
        return edge_first.size() ? edge_first : edge;
      }
      parents[child] = root;
    }
    
    return edge_second;
  }
  
private:
  int findRoot(vector<int>& parents, int node) {
    while (node != parents[node]) {
      parents[node] = parents[parents[node]];
      node = parents[node];
    }
    return node;
  }
};