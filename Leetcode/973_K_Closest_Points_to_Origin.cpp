// https://leetcode.com/problems/k-closest-points-to-origin/


#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;


// QuickSelect algorithm
// time: O(n)
// space: O(1)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quickSelect(points, k);
    }
    
private:
    vector<vector<int>> quickSelect(vector<vector<int>>& points, int k) {
        int left = 0, right = points.size() - 1;
        int pivotIndex = points.size();
        while (pivotIndex != k) {
            // Repeatedly partition the vector
            // while narrowing in on the kth element
            pivotIndex = partition(points, left, right);
            if (pivotIndex < k) {
                left = pivotIndex;
            } else {
                right = pivotIndex - 1;
            }
        }
        
        // Return the first k elements of the partially sorted vector
        return vector<vector<int>>(points.begin(), points.begin() + k);
    };

    int partition(vector<vector<int>>& points, int left, int right) {
        vector<int>& pivot = choosePivot(points, left, right);
        int pivotDist = squaredDistance(pivot);
        while (left < right) {
            // Iterate through the range and swap elements to make sure
            // that all points closer than the pivot are to the left
            if (squaredDistance(points[left]) >= pivotDist) {
                points[left].swap(points[right]);
                right--;
            } else {
                left++;
            }
        }
        
        // Ensure the left pointer is just past the end of
        // the left range then return it as the new pivotIndex
        if (squaredDistance(points[left]) < pivotDist)
            left++;
        return left;
    };

    vector<int>& choosePivot(vector<vector<int>>& points, int left, int right) {
        // Choose a pivot element of the vector
        return points[left + (right - left) / 2];
    }
    
    int squaredDistance(vector<int>& point) {
        // Calculate and return the squared Euclidean distance
        return point[0] * point[0] + point[1] * point[1];
    }
};


class _Solution {
public:
  // class pair_{
      
  //     public:
  //     int distance;
  //     int index;
      
  //     pair_(int distance, int index)
  //     {
  //         this->distance = distance;
  //         this->index = index;
  //     }
  // };
  
  // struct comp{ //Construction of Min Heap
      
  //     bool operator()(pair_ &a, pair_ &b)
  //     {
  //         return a.distance > b.distance;
  //     }
  // };


  // time: O(n * log(k))
  // space: O(k)
  // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  //   // build a max heap with k capacity
  //   priority_queue<tuple<int, int>> maxHeap;

  //   for (int i = 0; i < points.size(); i++) {
  //     int distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
  //     if (maxHeap.size() < k) {
  //       maxHeap.push({distance, i});
  //     } else {
  //       auto [ maxDistance, index ] = maxHeap.top();
  //       if (distance < maxDistance) {
  //         maxHeap.pop();
  //         maxHeap.push({distance, i});
  //       }
  //     }
  //   }

  //   vector<vector<int>> result;

  //   while (maxHeap.size()) {
  //     auto [ distance, i ] = maxHeap.top();
  //     maxHeap.pop();
  //     result.push_back({points[i][0], points[i][1]});
  //   }

  //   return result;
  // }



  // time: O(n * log(n))
  // space: O(log(n)) to O(n) for the extra space required by the sorting process
  // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  //   sort(points.begin(), points.end(), [&](vector<int>& a, vector<int>& b) {
  //     return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
  //   });

  //   return vector<vector<int>>(points.begin(), points.begin() + k);
  // }


  // time: O(n * log(n))
  // space: O(n)
  // vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  //   priority_queue<pair_, vector<pair_>, comp> minHeap;

  //   for (int i = 0; i < points.size(); i++) {
  //     int x = points[i][0], y = points[i][1];
  //     int distance = x * x + y * y;
  //     minHeap.push(pair_(distance, i));
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