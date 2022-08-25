// https://leetcode.com/problems/jump-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size(), goalIndex = n - 1;
    for (int cur = n - 2; cur >= 0; cur--) {
      if (cur + nums[cur] >= goalIndex)
        goalIndex = cur;
    }
    return goalIndex == 0;
  }
};