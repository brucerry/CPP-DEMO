// https://leetcode.com/problems/min-max-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int minMaxGame(vector<int>& nums) {
    for (int n = nums.size(); n > 1; n /= 2) {
      for (int i = 0; i < n / 2; i++) {
        nums[i] = i % 2 ? max(nums[2*i], nums[2*i+1]) : min(nums[2*i], nums[2*i+1]);
      }
    }
    return nums[0];
  }
};