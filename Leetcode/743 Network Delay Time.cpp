/*
  https://leetcode.com/problems/network-delay-time/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
using namespace std;


class Solution {
public:

  // helper functions
  unordered_map<int, vector<tuple<int, int>>> makeGraph(vector<vector<int>> times) {
    unordered_map<int, vector<tuple<int, int>>> graph;
    for (auto data : times) {
      int startNode = data[0];
      int endNode = data[1];
      int timeSpend = data[2];
      graph[startNode].push_back({timeSpend, endNode});
    }
    return graph;
  }
  // helper functions

  int networkDelayTime(vector<vector<int>> times, int n, int k) {
    unordered_map<int, vector<tuple<int, int>>> graph = makeGraph(times);
    unordered_set<int> visited;
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> minHeap;
    minHeap.push({0, k}); // { timeSpend, currentNode }

    int totalTime = 0;

    while (minHeap.size()) {
      auto [ timeSpend, currentNode ] = minHeap.top();
      minHeap.pop();
      if (visited.count(currentNode)) continue;
      visited.insert(currentNode);
      totalTime = max(totalTime, timeSpend);
      
      for (auto [ time, neighbor ] : graph[currentNode]) {
        if (visited.count(neighbor) == 0) {
          minHeap.push({time + timeSpend, neighbor});
        }
      }
    }

    return visited.size() == n ? totalTime : -1;
  }
};

int main() {
  Solution sol;
  cout << sol.networkDelayTime({{2,1,1}, {2,3,1}, {3,4,1}}, 4, 2) << endl;
  cout << sol.networkDelayTime({{1,2,1}}, 2, 1) << endl;
  cout << sol.networkDelayTime({{1,2,1}}, 2, 2) << endl;
  cout << sol.networkDelayTime({{1,2,1}, {2,1,3}}, 2, 2) << endl;
  cout << sol.networkDelayTime({{1,2,1}, {2,3,2}, {1,3,2}}, 3, 1) << endl;
}