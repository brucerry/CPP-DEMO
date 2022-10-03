// https://leetcode.com/problems/the-time-when-the-network-becomes-idle/

#include <vector>
#include <queue>
using namespace std;

// time: O(n + e)
// space: O(n + e)

class Solution {
public:
  int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
    int n = patience.size();

    vector<vector<int>> graph (n);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }

    vector<char> visited (n);
    visited[0] = 1;

    queue<int> queue;
    queue.emplace(0);
    int second = 1, result = 0;

    while (queue.size()) {
      int size = queue.size();
      while (size--) {
        int node = queue.front();
        queue.pop();
        for (const int& neighbor : graph[node]) {
          if (visited[neighbor] == 0) {
            visited[neighbor] = 1;
            result = max(result, second * 2 + (second * 2 - 1) / patience[neighbor] * patience[neighbor]);
            queue.emplace(neighbor);
          }
        }
      }
      second++;
    }

    return result + 1;
  }
};