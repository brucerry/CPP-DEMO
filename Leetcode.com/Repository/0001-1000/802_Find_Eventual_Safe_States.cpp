// https://leetcode.com/problems/find-eventual-safe-states/

#include <vector>
using namespace std;

// n = # of nodes
// e = # of edges
// time: O(n + e)
// space: O(n)

class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<char> states (n, -1); // -1: not visited, 0: unsafe, 1: safe
    
    vector<int> safeNodes;
    for (int node = 0; node < n; node++) {
      if (traverse(graph, node, states))
        safeNodes.emplace_back(node);
    }
    
    return safeNodes;
  }
  
private:
  bool traverse(vector<vector<int>>& graph, int node, vector<char>& states) {
    if (states[node] != -1)
      return states[node];
    
    states[node] = 0;
    
    for (const int& neighbor : graph[node]) {
      if (!traverse(graph, neighbor, states))
        return 0;
    }
    
    return states[node] = 1;
  }
};