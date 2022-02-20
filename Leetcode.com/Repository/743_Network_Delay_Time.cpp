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
private:
  unordered_map<int, vector<tuple<int, int>>> buildGraph(vector<vector<int>> times) {
    unordered_map<int, vector<tuple<int, int>>> graph;
    for (auto data : times) {
      int startNode = data[0];
      int endNode = data[1];
      int timeSpend = data[2];
      graph[startNode].push_back({timeSpend, endNode});
    }
    return graph;
  }

public:
  int networkDelayTime(vector<vector<int>> times, int n, int k) {
    unordered_map<int, vector<tuple<int, int>>> graph = buildGraph(times);
    unordered_set<int> visited;
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> pq;
    pq.push({0, k}); // { timeSpend, currentNode }

    int totalTime = 0;

    while (pq.size()) {
      auto [ timeSpend, currentNode ] = pq.top();
      pq.pop();
      if (visited.count(currentNode)) continue;
      visited.insert(currentNode);
      totalTime = max(totalTime, timeSpend);
      
      for (auto [ time, neighbor ] : graph[currentNode]) {
        if (visited.count(neighbor) == 0) {
          pq.push({time + timeSpend, neighbor});
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