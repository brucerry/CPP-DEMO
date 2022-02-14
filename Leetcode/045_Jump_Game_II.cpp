// https://leetcode.com/problems/jump-game-ii/

#include <vector>
using namespace std;

class Solution {
public:
  // time: O(n)
  // space: O(1)
  int jump(vector<int>& nums) {
    int steps = 0;
    int left = 0;
    int right = 0;

    while (right < nums.size() - 1) {
      int farthest = 0;
      for (int i = left; i <= right; i++) {
        farthest = max(farthest, i + nums[i]);
      }
      left = right + 1;
      right = farthest;
      steps++;
    }

    return steps;
  }
};