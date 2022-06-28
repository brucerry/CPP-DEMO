// https://leetcode.com/problems/furthest-building-you-can-reach/

#include <vector>
#include <queue>
using namespace std;

// n = size of heights
// k = ladders
// time: O(n * log(k))
// space: O(k)

class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    int n = heights.size();
    priority_queue<int, vector<int>, greater<>> minHeap; // bricks needed
    
    for (int i = 0; i < n - 1; i++) {
      int cur = heights[i], next = heights[i+1];
      int need = next - cur;
      if (need > 0) {
        minHeap.emplace(need);
        if (minHeap.size() > ladders) {
          bricks -= minHeap.top();
          minHeap.pop();
          if (bricks < 0)
            return i;
        }
      }
    }
    
    return n - 1;
  }
};