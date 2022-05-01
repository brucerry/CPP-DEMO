// https://leetcode.com/problems/car-pooling/

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// time: O(n)
// space: O(1)
class BruteForce {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> passChange (1001);
    
    for (const auto& trip : trips) {
      int numPass = trip[0];
      int start = trip[1];
      int end = trip[2];
      
      passChange[start] -= numPass;
      passChange[end] += numPass;
    }
    
    for (const int& pc : passChange) {
      capacity += pc;
      if (capacity < 0)
        return false;
    }
    
    return true;
  }
};

// time: O(n * log(n))
// space: O(n)
class SortandMinHeap {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
      return a[1] < b[1];
    });
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap; // end, numPass 
    
    for (const auto& trip : trips) {
      int numPass = trip[0];
      int start = trip[1];
      int end = trip[2];
      
      while (minHeap.size() and minHeap.top().first <= start) {
        capacity += minHeap.top().second;
        minHeap.pop();
      }
      
      capacity -= numPass;
      
      if (capacity < 0)
        return false;
      
      minHeap.emplace(end, numPass);
    }
    
    return true;
  }
};