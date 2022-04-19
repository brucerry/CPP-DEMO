// https://leetcode.com/problems/merge-intervals/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) to O(n) from sorting

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> result;

    for (const auto& interval : intervals) {
      if (result.empty() || result.back()[1] < interval[0]) {
        result.emplace_back(interval);
      }
      else {
        result.back()[1] = max(result.back()[1], interval[1]);
      }
    }

    return result;
  }
};