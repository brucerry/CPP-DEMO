// https://leetcode.com/problems/jump-game-ii/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int jump(vector<int>& nums) {
    int jumpCount = 0;
    int l = 0, r = 0;
    
    while (r < nums.size() - 1) {
      int furthestIndex = 0;
      for (int i = l; i <= r; i++) {
        furthestIndex = max(furthestIndex, i + nums[i]);
      }
      l = r + 1;
      r = furthestIndex;
      jumpCount++;
    }
    
    return jumpCount;
  }
};