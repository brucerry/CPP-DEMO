// https://leetcode.com/problems/second-minimum-time-to-reach-destination/

#include <vector>
#include <queue>
using namespace std;

// time: O(e + n)
// space: O(e + n)

class Solution {
public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> graph (n + 1);
    for (const auto& edge : edges) {
      int node1 = edge[0], node2 = edge[1];
      graph[node1].emplace_back(node2);
      graph[node2].emplace_back(node1);
    }
    
    vector<int> minSteps (n + 1, n + 1);
    
    queue<int> queue; // node
    queue.emplace(1);
    
    int step = 0;
    while (queue.size() and step <= minSteps[n] + 1) {
      for (int size = queue.size(); size; size--) {
        int node = queue.front();
        queue.pop();
        
        if (step == minSteps[node] or step > minSteps[node] + 1) // case found the minimum step or more than the second minimum
          continue;
        
        minSteps[node] = min(minSteps[node], step);
        
        if (node == n and step > minSteps[node]) // case found exactly the second minimum
          return calculateTime(step, time, change);
        
        for (const int& neighbor : graph[node])
          queue.emplace(neighbor);
      }
      step++;
    }
    
    return calculateTime(minSteps[n] + 2, time, change);
  }
  
private:
  int calculateTime(int step, int time, int change) {
    int mins = 0;
    while (--step) {
      mins += time;
      if (mins / change % 2) // red signal
        mins = (mins / change + 1) * change;
    }
    return mins + time;
  }
};