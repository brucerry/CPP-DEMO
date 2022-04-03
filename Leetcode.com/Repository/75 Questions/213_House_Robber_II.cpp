// https://leetcode.com/problems/house-robber-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
private:
  int houseRobber1(vector<int>& nums, int left, int right) {
    // index: 0, 1, 2, 3, ..., nums.size() - 1, rob1, rob2

    int rob1 = 0;
    int rob2 = 0;

    for (int i = right; i >= left; i--) {
      int tmp = max(rob1, nums[i] + rob2);
      rob2 = rob1;
      rob1 = tmp;
    }

    return rob1;
  }

public:
  int rob(vector<int>& nums) {
    int result1 = houseRobber1(nums, 0, nums.size() - 2);
    int result2 = houseRobber1(nums, 1, nums.size() - 1);
    return max({ nums[0], result1, result2 });
  }
};