// https://leetcode.com/problems/network-delay-time/

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// n = # of nodes
// e = # of edges
// time: O(e * log(n))
// space: O(n)

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    unordered_map<int, vector<pair<int, int>>> graph;

    for (auto& data : times) {
      int startNode = data[0];
      int endNode = data[1];
      int timeSpend = data[2];
      graph[startNode].push_back({timeSpend, endNode});
    }

    unordered_set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, k}); // { timeSpend, currentNode }

    int totalTime = 0;

    while (pq.size()) {
      auto [ timeSpend, currentNode ] = pq.top();
      pq.pop();

      if (visited.count(currentNode)) continue;
      visited.insert(currentNode);

      totalTime = max(totalTime, timeSpend);

      if (visited.size() == n) return totalTime;
      
      for (auto& [ time, neighbor ] : graph[currentNode]) {
        if (visited.count(neighbor) == 0) {
          pq.push({time + timeSpend, neighbor});
        }
      }
    }

    return -1;
  }
};