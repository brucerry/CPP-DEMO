// https://leetcode.com/problems/jump-game/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
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
};
