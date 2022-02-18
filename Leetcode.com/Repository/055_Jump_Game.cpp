// https://leetcode.com/problems/jump-game/

#include <vector>
using namespace std;

class Solution {
private:
  // time: O(n^2)
  // space: O(n)
  // bool canJump(vector<int>& nums, int idx, vector<int>& dp) {
  //   if (dp[idx] != -1) return dp[idx];
  //   if (idx >= nums.size()) return false;

  //   for (int step = 1; step <= nums[idx]; step++) {
  //     if (canJump(nums, idx + step, dp)) {
  //       dp[idx] = 1;
  //       return dp[idx];
  //     }
  //   }

  //   dp[idx] = 0;
  //   return dp[idx];
  // }

public:
  // time: O(n)
  // space: O(1)
  bool canJump(vector<int>& nums) {
    int goalIndex = nums.size() - 1;
    for (int i = goalIndex - 1; i >= 0; i--) {
      int dist = goalIndex - i;
      if (nums[i] >= dist) {
        goalIndex = i;
      }
    }
    return goalIndex == 0;
  }

  // bool canJump(vector<int>& nums) {
  //   vector<int> dp (nums.size(), -1);
  //   dp.back() = 1;
  //   return canJump(nums, 0, dp);
  // }
};
