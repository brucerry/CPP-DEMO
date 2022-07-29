// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#include <vector>
#include <queue>
using namespace std;

// n = # of nodes
// e = size of roads = # of edges
// time: O(e + n^2 * log(n))
// space: O(n^2)

class Solution {
public:
  int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> graph (n); // node, time
    for (const auto& road : roads) {
      int node1 = road[0];
      int node2 = road[1];
      int time = road[2];
      graph[node1].emplace_back(node2, time);
      graph[node2].emplace_back(node1, time);
    }
    
    vector<long> ways (n, 1), costs (n, LONG_MAX);
    costs[0] = 0;
    
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>> minHeap; // cost, node
    minHeap.emplace(0, 0);
    
    while (minHeap.size()) {
      auto [ cost, node ] = minHeap.top();
      minHeap.pop();
      
      if (cost > costs[node])
        continue;
      
      for (const auto& [ neighbor, time ] : graph[node]) {
        long addedCost = cost + time;
        if (addedCost < costs[neighbor]) {
          costs[neighbor] = addedCost;
          ways[neighbor] = ways[node];
          minHeap.emplace(addedCost, neighbor);
        }
        else if (addedCost == costs[neighbor]) {
          ways[neighbor] = (ways[neighbor] + ways[node]) % 1000000007;
        }
      }
    }
    
    return ways[n - 1];
  }
};