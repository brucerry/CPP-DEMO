// https://leetcode.com/problems/insert-interval/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;

    for (int i = 0; i < intervals.size(); i++) {
      int newStart = newInterval[0];
      int newEnd = newInterval[1];
      int currentStart = intervals[i][0];
      int currentEnd = intervals[i][1];
      
      if (newEnd < currentStart) {
        result.push_back(newInterval);
        result.insert(result.end(), intervals.begin() + i, intervals.end());
        return result;
      } else if (currentEnd < newStart) {
        result.push_back(intervals[i]);
      } else {
        newInterval = {min(currentStart, newStart), max(currentEnd, newEnd)};
      }
    }

    result.push_back(newInterval);

    return result;
  }
};