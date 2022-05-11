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
    for (const auto& t : times) {
      int src = t[0];
      int dst = t[1];
      int cost = t[2];
      graph[src].emplace_back(cost, dst);
    }
    
    vector<char> visited (n + 1);
    int visitedCount = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // cost, node
    minHeap.emplace(0, k);
    
    int totalTime = 0;
    while (minHeap.size()) {
      auto [ cost, node ] = minHeap.top();
      minHeap.pop();
      
      if (visited[node])
        continue;
      
      visited[node] = 1;
      visitedCount++;
      
      totalTime = max(totalTime, cost);
      
      for (const auto& [ t, neighbor ] : graph[node]) {
        if (visited[neighbor] == 0)
          minHeap.emplace(cost + t, neighbor);
      }
    }
    
    return visitedCount == n ? totalTime : -1;
  }
};