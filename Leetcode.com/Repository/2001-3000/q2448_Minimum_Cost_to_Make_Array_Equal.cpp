// https://leetcode.com/problems/minimum-cost-to-make-array-equal/

#include <vector>
using namespace std;

// max = max of nums
// time: O(n * log(max))
// space: O(1)

class Solution {
public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    long l = 1, r = 1e6, result = 0;
    while (l < r) {
      long m = l + (r - l) / 2;
      long c1 = search(nums, cost, m), c2 = search(nums, cost, m + 1);
      result = min(c1, c2);
      if (c1 < c2)
        r = m;
      else
        l = m + 1;
    }
    return result;
  }

private:
  long search(vector<int>& nums, vector<int>& cost, long x) {
    long totalcost = 0;
    for (int i = 0; i < nums.size(); i++) {
      totalcost += abs(nums[i] - x) * cost[i];
    }
    return totalcost;
  }
};