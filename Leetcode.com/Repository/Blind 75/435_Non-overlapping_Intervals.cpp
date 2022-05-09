// https://leetcode.com/problems/non-overlapping-intervals/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    int count = 0;

    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i-1][1] > intervals[i][0]) {
        intervals[i][1] = min(intervals[i-1][1], intervals[i][1]);
        count++;
      }
    }

    return count;
  }
};