// https://leetcode.com/problems/minimum-number-of-refueling-stops/

#include <vector>
#include <queue>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    stations.push_back({ target, 0 });
    priority_queue<int> maxHeap; // refuel
    
    int stops = 0, curPos = 0, curFuel = startFuel;
    for (const auto& station : stations) {
      int pos = station[0];
      int refuel = station[1];
      int diff = pos - curPos;
      while (maxHeap.size() and diff > curFuel) {
        curFuel += maxHeap.top();
        maxHeap.pop();
        stops++;
      }
      if (diff > curFuel)
        return -1;
      curFuel -= diff;
      curPos = pos;
      maxHeap.emplace(refuel);
    }
    return stops;
  }
};