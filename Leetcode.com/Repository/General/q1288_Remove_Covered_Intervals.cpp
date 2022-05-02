// https://leetcode.com/problems/remove-covered-intervals/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) to O(n) for sorting

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });
    
    vector<vector<int>> largerIntervals;
    
    for (const auto& interval : intervals) {
      if (largerIntervals.size() and largerIntervals.back()[0] <= interval[0] and interval[1] <= largerIntervals.back()[1])
        continue;
      largerIntervals.emplace_back(interval);
    }
    
    return largerIntervals.size();
  }
};