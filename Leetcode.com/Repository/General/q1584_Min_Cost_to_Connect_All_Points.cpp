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
    
    int visitedCount = 0;
    vector<char> visited (n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // cost, node
    minHeap.emplace(0, 0);
    
    int ans = 0;
    
    while (visitedCount < n) {
      auto [ cost, node ] = minHeap.top();
      minHeap.pop();
      
      if (visited[node])
        continue;
      
      visited[node] = 1;
      visitedCount++;
      ans += cost;
      
      for (int nextNode = 0; nextNode < n; nextNode++) {
        if (!visited[nextNode]) {
          int c = abs(points[node][0] - points[nextNode][0]) + abs(points[node][1] - points[nextNode][1]);
          minHeap.emplace(c, nextNode);
        }
      }
    }
    
    return ans;
  }
};