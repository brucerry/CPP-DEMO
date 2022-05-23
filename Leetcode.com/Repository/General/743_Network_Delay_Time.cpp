// https://leetcode.com/problems/network-delay-time/

#include <vector>
#include <queue>
using namespace std;

// time: O(e * log(n))
// space: O(n)

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph (n + 1); // cost, dst
    for (const auto& time : times) {
      int src = time[0];
      int dst = time[1];
      int cost = time[2];
      graph[src].emplace_back(cost, dst);
    }
    
    vector<char> visited (n + 1);
    int visitedCount = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // cost, node
    minHeap.emplace(0, k);
    
    int time = 0;
    while (minHeap.size()) {
      auto [ cost, node ] = minHeap.top();
      minHeap.pop();
      
      if (visited[node])
        continue;
      visited[node] = 1;
      visitedCount++;
      
      time = max(time, cost);
      
      if (visitedCount == n)
        return time;
      
      for (const auto& [ c, neighbor ] : graph[node]) {
        if (visited[neighbor] == 0)
          minHeap.emplace(cost + c, neighbor);
      }
    }
    
    return -1;
  }
};