// https://leetcode.com/problems/find-eventual-safe-states/

#include <vector>
using namespace std;

// n = # of nodes
// e = # of edges
// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> states (n, -1); // -1: not visited, 0: unsafe, 1: safe
    
    vector<int> safeNodes;
    for (int node = 0; node < n; node++) {
      if (traverse(graph, states, node))
        safeNodes.emplace_back(node);
    }
    
    return safeNodes;
  }
  
private:
  bool traverse(vector<vector<int>>& graph, vector<int>& states, int node) {
    if (states[node] != -1)
      return states[node];
    
    states[node] = false;
    
    for (const int& neighbor : graph[node]) {
      if (!traverse(graph, states, neighbor))
        return false;
    }
    
    return states[node] = true;
  }
};