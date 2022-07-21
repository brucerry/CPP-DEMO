// https://leetcode.com/problems/minimum-number-of-refueling-stops/

#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> maxHeap; // fuel
    stations.push_back({ target, 0 });
    
    int cur = 0, remain = startFuel, stop = 0;
    for (const auto& station : stations) {
      int pos = station[0];
      int fuel = station[1];
      int dist = pos - cur;
      remain -= dist;
      while (maxHeap.size() and remain < 0) {
        remain += maxHeap.top();
        maxHeap.pop();
        stop++;
      }
      if (remain < 0)
        return -1;
      maxHeap.emplace(fuel);
      cur = pos;
    }
    
    return stop;
  }
};