// https://leetcode.com/problems/house-robber/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int rob(vector<int>& nums) {
    // index: 0, 1, 2, 3, ..., nums.size() - 1, rob1, rob2

    int rob1 = 0;
    int rob2 = 0;

    for (int i = nums.size() - 1; i >= 0; i--) {
      int tmp = max(rob1, nums[i] + rob2);
      rob2 = rob1;
      rob1 = tmp;
    }

    return rob1;
  }
};