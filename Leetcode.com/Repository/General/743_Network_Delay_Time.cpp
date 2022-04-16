// https://leetcode.com/problems/network-delay-time/

#include <vector>
#include <queue>
using namespace std;

// time: O(e * log(n))
// space: O(n)

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph (n + 1);
    
    for (const auto& time : times) {
      graph[time[0]].emplace_back(time[2], time[1]);
    }
    
    vector<char> visited (n + 1, 0);
    int visitedCount = 0;
    int ans = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    minHeap.emplace(0, k);
    
    while (minHeap.size()) {
      auto [ time, node ] = minHeap.top();
      minHeap.pop();
      
      if (visited[node])
        continue;
      
      visited[node] = 1;
      visitedCount++;
      ans = max(ans, time);
      
      for (const auto& [ t, neighbor ] : graph[node]) {
        if (!visited[neighbor]) {
          minHeap.emplace(time + t, neighbor);
        }
      }
    }
    
    return visitedCount == n ? ans : -1;
  }
};