// https://leetcode.com/problems/merge-intervals/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> result;
    for (const auto& interval : intervals) {
      if (result.size() and interval[0] <= result.back()[1])
        result.back()[1] = max(result.back()[1], interval[1]);
      else
        result.emplace_back(interval);
    }
    
    return result;
  }
};