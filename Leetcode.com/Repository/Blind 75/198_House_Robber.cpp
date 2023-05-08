// https://leetcode.com/problems/house-robber/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for (int num : nums) {
            int tmp = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }
};

class InPlace {
public:
  int rob(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
      int val = i - 2 < 0 ? 0 : nums[i-2];
      nums[i] = max(nums[i] + val, nums[i-1]);
    }
    return nums.back();
  }
};