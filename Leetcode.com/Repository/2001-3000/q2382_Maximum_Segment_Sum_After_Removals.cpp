// https://leetcode.com/problems/maximum-segment-sum-after-removals/

#include <vector>
using namespace std;

// time: O(n)
// space: O(n)

class Solution {
public:
  vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
    int n = nums.size();
    vector<long long> result (n), values (n, INT_MAX);
    
    // values:
    // A non-negative value is an index of the set "parent". A negative value is the negated sum of all elements in the set.
    
    for (int i = n - 1; i; i--) {
      int rqi = removeQueries[i];
      values[rqi] = -nums[rqi];
      if (rqi - 1 >= 0 and values[rqi - 1] != INT_MAX)
        unions(values, rqi, rqi - 1);
      if (rqi + 1 < n and values[rqi + 1] != INT_MAX)
        unions(values, rqi, rqi + 1);
      result[i - 1] = max(result[i], -values[findParent(values, rqi)]);
    }
    
    return result;
  }
  
private:
  int findParent(vector<long long>& values, int idx) {
    while (values[idx] >= 0) {
      idx = values[idx];
    }
    return idx;
  }
  
  void unions(vector<long long>& values, int cur, int unionTo) {
    int p1 = findParent(values, cur), p2 = findParent(values, unionTo);
    values[p2] += values[p1];
    values[p1] = p2;
  }
};