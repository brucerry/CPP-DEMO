// https://leetcode.com/problems/jump-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int goalIndex = n - 1;
    
    for (int i = n - 2; i >= 0; i--) {
      if (i + nums[i] >= goalIndex)
        goalIndex = i;
    }
    
    return goalIndex == 0;
  }
};