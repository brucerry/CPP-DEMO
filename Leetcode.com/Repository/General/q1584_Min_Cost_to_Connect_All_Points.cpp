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
    
    vector<char> visited (n);
    int visitedCount = 0;
    
    vector<int> minCost (n, INT_MAX);
    minCost[0] = 0;
    
    int totalCost = 0;
    while (visitedCount < n) {
      int curCost = INT_MAX;
      int curNode = -1;
      for (int node = 0; node < n; node++) {
        if (visited[node] == 0 and minCost[node] < curCost) {
          curCost = minCost[node];
          curNode = node;
        }
      }
      
      visited[curNode] = 1;
      visitedCount++;
      
      totalCost += curCost;
      
      for (int neighbor = 0; neighbor < n; neighbor++) {
        int cost = distance(points[curNode], points[neighbor]);
        if (visited[neighbor] == 0 and cost < minCost[neighbor])
          minCost[neighbor] = cost;
      }
    }
    
    return totalCost;
  }
  
private:
  int distance(const vector<int>& a, const vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }
};

// time: O(n^2 * log(n^2)) => O(n^2 * log(n))
// space: O(n^2)
class PrimsAlgo {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // cost, index
    minHeap.emplace(0, 0);
    
    vector<char> visited (n);
    int visitedCount = 0;
    
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
        if (!visited[neighbor])
          minHeap.emplace(distance(points[node], points[neighbor]), neighbor);
      }
    }
    
    return totalCost;
  }
  
private:
  int distance(vector<int>& a, vector<int>& b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
  }
};