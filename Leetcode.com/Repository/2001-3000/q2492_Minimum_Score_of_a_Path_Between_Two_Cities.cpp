// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/

#include <vector>
#include <climits>
using namespace std;

// e = size of roads
// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  int minScore(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> graph (n + 1);
    for (const auto& r : roads) {
      int u = r[0], v = r[1], dist = r[2];
      graph[u].emplace_back(v, dist);
      graph[v].emplace_back(u, dist);
    }
    
    int res = INT_MAX;
    vector<int> visited (n + 1);
    dfs(graph, visited, 1, res);
    
    return res;
  }
  
private:
  void dfs(vector<vector<pair<int, int>>>& graph, vector<int>& visited, int node, int& res) {
    if (visited[node])
      return;
    visited[node] = 1;
    
    for (const auto& [ neighbor, dist ] : graph[node]) {
      res = min(res, dist);
      dfs(graph, visited, neighbor, res);
    }
  }
};