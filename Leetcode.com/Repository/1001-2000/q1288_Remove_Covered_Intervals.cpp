// https://leetcode.com/problems/remove-covered-intervals/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * log(n))
// space: O(log(n)) for sorting
class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });
    
    vector<int> largerInterval;
    int remain = 0;
    for (const auto& interval : intervals) {
      if (remain == 0 or largerInterval[1] < interval[1]) {
        largerInterval = interval;
        remain++;
      }
    }
    
    return remain;
  }
};

// time: O(n * log(n))
// space: O(n)
class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });
    
    vector<vector<int>> largerIntervals;
    for (const auto& interval : intervals) {
      if (largerIntervals.size() == 0 or largerIntervals.back()[1] < interval[1])
        largerIntervals.emplace_back(interval);
    }
    
    return largerIntervals.size();
  }
};

// time: O(n * log(n))
// space: O(n)
class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    
    vector<vector<int>> remain;
    for (const auto& interval : intervals) {
      while (remain.size() and interval[0] <= remain.back()[0] and remain.back()[1] <= interval[1])
        remain.pop_back();
      if (remain.size() and remain.back()[0] <= interval[0] and interval[1] <= remain.back()[1])
        continue;
      remain.emplace_back(interval);
    }
    
    return remain.size();
  }
};