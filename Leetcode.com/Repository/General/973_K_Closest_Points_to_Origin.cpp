// https://leetcode.com/problems/k-closest-points-to-origin/


#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(k))
// space: O(k)

class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, int>> maxHeap; // dist, index
    for (int i = 0; i < points.size(); i++) {
      int x = points[i][0];
      int y = points[i][1];
      int dist = x * x + y * y;
      if (maxHeap.size() < k)
        maxHeap.emplace(dist, i);
      else if (dist < maxHeap.top().first) {
        maxHeap.pop();
        maxHeap.emplace(dist, i);
      }
    }
    
    vector<vector<int>> result (k);
    for (int i = 0; i < k; i++) {
      auto [ _, index ] = maxHeap.top();
      maxHeap.pop();
      result[i] = points[index];
    }
    
    return result;
  }
};