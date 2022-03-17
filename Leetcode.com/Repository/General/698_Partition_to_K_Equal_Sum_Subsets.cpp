// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// time: O(k * (2 ^ n))
// space: O(2 ^ n)

class Solution {
private:
  int n;
  int avg;
  int all;
  vector<int> nums;
  vector<int> memo;

  bool isPossible(int k, int mask, int subsetSum) {
    if (subsetSum == avg) {
      k--;
      subsetSum = 0;
    }

    if (k < 0 || subsetSum > avg) return false;
    if (mask == all) return k == 0 && subsetSum == 0;
    if (memo[mask] != -1) return memo[mask];

    bool ans = false;
    for (int i = 0; i < n; i++) {
      if ((mask & (1 << i)) == 0) {
        ans = ans || isPossible(k, mask | (1 << i), subsetSum + nums[i]);
      }
    }

    return memo[mask] = ans;
  }

public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    this->nums = nums;
    int sum = accumulate(this->nums.begin(), this->nums.end(), 0);
    if (sum % k) return false;
    // sort(this->nums.begin(), this->nums.end(), [](int x, int y) -> bool {
    //   return x > y;
    // });

    n = this->nums.size();
    avg = sum / k;
    all = (1 << n) - 1;
    memo = vector<int>(all, -1);

    return isPossible(k, 0, 0);
  }
};