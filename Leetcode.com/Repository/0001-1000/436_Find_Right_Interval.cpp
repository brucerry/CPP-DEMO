// https://leetcode.com/problems/find-right-interval/

#include <vector>
#include <map>
using namespace std;

// time: O(n * log(n))
// space: O(n)

class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    map<int, int> startIndex;
    for (int i = 0; i < intervals.size(); i++) {
      startIndex[intervals[i][0]] = i;
    }

    vector<int> result;
    for (const auto& itv : intervals) {
      auto it = startIndex.lower_bound(itv[1]);
      result.emplace_back(it == startIndex.end() ? -1 : it->second);
    }

    return result;
  }
};