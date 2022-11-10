// https://leetcode.com/problems/shortest-path-visiting-all-nodes/

#include <vector>
#include <queue>
#include <array>
using namespace std;

// time: O(n * 2^n)
// space: O(n * 2^n)

class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    
    queue<array<int, 3>> queue; // node, dist, mask
    char visited[12][5000] {};
    for (int node = 0; node < n; node++) {
      visited[node][1 << node] = 1;
      queue.push({ node, 0, 1 << node });
    }

    while (queue.size()) {
      auto [ node, dist, mask ] = queue.front();
      queue.pop();
      if (mask == (1 << n) - 1)
        return dist;
      for (const auto& neighbor : graph[node]) {
        int new_mask = mask | (1 << neighbor);
        if (visited[neighbor][new_mask] == 0) {
          visited[neighbor][new_mask] = 1;
          queue.push({ neighbor, dist + 1, new_mask });
        }
      }
    }

    return -1;
  }
};