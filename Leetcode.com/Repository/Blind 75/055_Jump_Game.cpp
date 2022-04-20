// https://leetcode.com/problems/jump-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int goalIndex = nums.size() - 1;
    
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] >= goalIndex - i)
        goalIndex = i;
    }
    
    return goalIndex == 0;
  }
};