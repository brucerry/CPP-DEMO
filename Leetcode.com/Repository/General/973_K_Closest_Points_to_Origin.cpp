// https://leetcode.com/problems/k-closest-points-to-origin/


#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(k))
// space: O(k)

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> closestPoints;
    
    priority_queue<pair<int, int>> maxHeap;
    
    for (int i = 0; i < points.size(); i++) {
      int dist = distance(points[i]);
      
      if (maxHeap.size() < k) {
        maxHeap.emplace(dist, i);
      }
      else if (dist < maxHeap.top().first) {
        maxHeap.pop();
        maxHeap.emplace(dist, i);
      }
    }
    
    while (maxHeap.size()) {
      auto [ _, i ] = maxHeap.top();
      maxHeap.pop();
      
      closestPoints.emplace_back(points[i]);
    }
    
    return closestPoints;
  }
  
private:  
  int distance(const vector<int>& p) {
    return p[0] * p[0] + p[1] * p[1];
  }
};