// https://leetcode.com/problems/min-cost-to-connect-all-points/

#include <vector>
#include <queue>
using namespace std;

// time: O(n^2)
// space: O(n)
class PrimsAlgoOptimized {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    
    vector<int> minCosts (n, INT_MAX);
    minCosts[0] = 0;
    
    vector<char> visited (n);
    int visitedCount = 0;
    
    int totalCost = 0;
    while (visitedCount < n) {
      int curNode = -1;
      int curMin = INT_MAX;
      for (int node = 0; node < n; node++) {
        if (visited[node] == 0 and minCosts[node] < curMin) {
          curMin = minCosts[node];
          curNode = node;
        }
      }
      
      visited[curNode] = 1;
      visitedCount++;
      totalCost += curMin;
      
      for (int neighbor = 0; neighbor < n; neighbor++) {
        int dist = distance(points, curNode, neighbor);
        if (visited[neighbor] == 0 and dist < minCosts[neighbor])
          minCosts[neighbor] = dist;
      }
    }
    
    return totalCost;
  }
  
private:
  int distance(vector<vector<int>>& points, int a, int b) {
    return abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]);
  }
};

// time: O(n^2 * log(n^2)) => O(n^2 * log(n))
// space: O(n^2)
class PrimsAlgo {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    
    vector<char> visited (n);
    int visitedCount = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // cost, node
    minHeap.emplace(0, 0);
    
    int totalCost = 0;
    while (visitedCount < n) {
      auto [ cost, node ] = minHeap.top();
      minHeap.pop();
      
      if (visited[node])
        continue;
      visited[node] = 1;
      visitedCount++;
      
      totalCost += cost;
      
      for (int neighbor = 0; neighbor < n; neighbor++) {
        if (visited[neighbor] == 0)
          minHeap.emplace(distance(points, node, neighbor), neighbor);
      }
    }
    
    return totalCost;
  }
  
private:
  int distance(vector<vector<int>>& points, int a, int b) {
    return abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]);
  }
};