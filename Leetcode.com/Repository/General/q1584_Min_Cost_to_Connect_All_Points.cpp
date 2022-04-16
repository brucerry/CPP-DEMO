// https://leetcode.com/problems/min-cost-to-connect-all-points/

#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

// time: O(n^2 * log(n))
// space: O(n^2)

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    
    vector<vector<pair<int, int>>> graph (n); // node, neighbors of (dist, node)
    
    for (int i = 0; i < n; i++) {
      int x1 = points[i][0];
      int y1 = points[i][1];
      
      for (int j = i + 1; j < n; j++) {
        int x2 = points[j][0];
        int y2 = points[j][1];
        
        int dist = abs(x1 - x2) + abs(y1 - y2);
        graph[i].emplace_back(dist, j);
        graph[j].emplace_back(dist, i);
      }
    }
    
    unordered_set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    minHeap.emplace(0, 0);
    
    int ans = 0;
    
    while (visited.size() < n) {
      auto [ dist, node ] = minHeap.top();
      minHeap.pop();
      
      if (visited.count(node))
        continue;
      
      visited.emplace(node);
      
      ans += dist;
      
      for (const auto& [ _, neighbor ] : graph[node]) {
        if (visited.count(neighbor) == 0)
          minHeap.emplace(_, neighbor);
      }
    }
    
    return ans;
  }
};