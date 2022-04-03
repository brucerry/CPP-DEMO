// https://leetcode.com/problems/network-delay-time/

#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// time: O(e * log(n))
// space: O(n)

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph (n + 1, vector<pair<int, int>>());

    for (const auto& data : times) {
      int start = data[0];
      int end = data[1];
      int time = data[2];
      graph[start].emplace_back(time, end);
    }

    unordered_set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, k); // { timeSpend, node }
    
    int totalTime = 0;

    while (pq.size()) {
      auto [ timeSpend, node ] = pq.top();
      pq.pop();

       if (visited.count(node)) continue;
       visited.emplace(node);

      totalTime = max(totalTime, timeSpend);

      if (visited.size() == n) return totalTime;
      
      for (const auto& [ time, neighbor ] : graph[node]) {
        if (visited.count(neighbor) == 0) {
          pq.emplace(time + timeSpend, neighbor);
        }
      }
    }

    return -1;
  }
};