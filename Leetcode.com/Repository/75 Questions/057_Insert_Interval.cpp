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
      if (newInterval[1] < intervals[i][0]) {
        result.emplace_back(newInterval);
        result.insert(result.end(), intervals.begin() + i, intervals.end());
        return result;
      }
      else if (intervals[i][1] >= newInterval[0]) {
        newInterval = { min(intervals[i][0], newInterval[0]), max(intervals[i][1], newInterval[1]) };
      }
      else {
        result.emplace_back(intervals[i]);
      }
    }
    
    result.emplace_back(newInterval);
    
    return result;
  }
};