// https://leetcode.com/problems/k-closest-points-to-origin/


#include <vector>
#include <queue>
using namespace std;

class _Solution {
public:
  // time: O(n * log(k))
  // space: O(k)
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // build a max heap with k capacity
    priority_queue<pair<int, int>> maxHeap;

    for (int i = 0; i < points.size(); i++) {
      int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
      if (maxHeap.size() < k) {
        maxHeap.push({distance, i});
      }
      else {
        auto [ maxDistance, index ] = maxHeap.top();
        if (distance < maxDistance) {
          maxHeap.pop();
          maxHeap.push({distance, i});
        }
      }
    }

    vector<vector<int>> result;

    while (maxHeap.size()) {
      auto [ distance, i ] = maxHeap.top();
      maxHeap.pop();
      result.push_back({points[i][0], points[i][1]});
    }

    return result;
  }


  // time: O(n * log(n))
  // space: O(n)
  // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  //   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

  //   for (int i = 0; i < points.size(); i++) {
  //     int x = points[i][0], y = points[i][1];
  //     int distance = x * x + y * y;
  //     minHeap.push({distance, i});
  //   }

  //   vector<vector<int>> result;

  //   while (k--) {
  //     int i = minHeap.top().index;
  //     minHeap.pop();
  //     int x = points[i][0];
  //     int y = points[i][1];
  //     result.push_back({x, y});
  //   }

  //   return result;
  // }
};