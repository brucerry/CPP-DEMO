// https://leetcode.com/problems/k-closest-points-to-origin/


#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(k))
// space: O(k)

class Solution {
private:
  struct Point {
    int dist, i;
  };
  
  struct comp {
    bool operator()(const Point& a, const Point& b) {
      return a.dist < b.dist;
    }
  };
  
  int distance(const vector<int>& point) {
    return point[0] * point[0] + point[1] * point[1];
  }
  
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    // build a max heap with k capacity
    priority_queue<Point, vector<Point>, comp> maxHeap;
    
    for (int i = 0; i < points.size(); i++) {
      Point p = { distance(points[i]), i };
      if (maxHeap.size() < k) {
        maxHeap.emplace(p);
      }
      else if (p.dist < maxHeap.top().dist) {
        maxHeap.pop();
        maxHeap.emplace(p);
      }
    }
    
    vector<vector<int>> ans;
    
    while (maxHeap.size()) {
      const Point& p = maxHeap.top();
      ans.push_back(points[p.i]);
      maxHeap.pop();
    }
    
    return ans;
  }
};

// time: O(n * log(n))
// space: O(n)
// class _Solution {
// public:
//   vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

//     for (int i = 0; i < points.size(); i++) {
//       int x = points[i][0], y = points[i][1];
//       int distance = x * x + y * y;
//       minHeap.push({distance, i});
//     }

//     vector<vector<int>> result;

//     while (k--) {
//       int i = minHeap.top().index;
//       minHeap.pop();
//       int x = points[i][0];
//       int y = points[i][1];
//       result.push_back({x, y});
//     }

//     return result;
//   }
// };