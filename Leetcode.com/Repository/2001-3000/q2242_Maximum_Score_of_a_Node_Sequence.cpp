// https://leetcode.com/problems/maximum-score-of-a-node-sequence/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
    int n = scores.size();
    
    vector<vector<int>> graph (n);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
    
    for (auto& neighbors : graph) {
      partial_sort(neighbors.begin(), neighbors.begin() + min(3, (int)neighbors.size()), neighbors.end(), [&](const int& node1, const int& node2) {
        return scores[node1] > scores[node2];
      });
      neighbors.resize(min(3, (int)neighbors.size()));
    }

    int result = -1;
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      for (const int& unei : graph[u]) {
        for (const int& vnei : graph[v]) {
          if (unei != vnei and unei != v and vnei != u)
            result = max(result, scores[u] + scores[v] + scores[unei] + scores[vnei]);
        }
      }
    }

    return result;
  }
};