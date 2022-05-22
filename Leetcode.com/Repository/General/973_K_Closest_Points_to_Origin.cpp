// https://leetcode.com/problems/k-closest-points-to-origin/


#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(k))
// space: O(k)

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    int n = points.size();
    
    priority_queue<pair<int, int>> maxHeap; // distance, index
    for (int i = 0; i < n; i++) {
      int x = points[i][0];
      int y = points[i][1];
      int dist = x * x + y * y;
      
      if (maxHeap.size() < k) {
        maxHeap.emplace(dist, i);
      }
      else if (dist < maxHeap.top().first) {
        maxHeap.pop();
        maxHeap.emplace(dist, i);
      }
    }
    
    vector<vector<int>> kClosest;
    while (maxHeap.size()) {
      auto [ _, i ] = maxHeap.top();
      maxHeap.pop();
      kClosest.emplace_back(points[i]);
    }
    
    return kClosest;
  }
};