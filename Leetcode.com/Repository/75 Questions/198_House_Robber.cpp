// https://leetcode.com/problems/house-robber/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int rob(vector<int>& nums) {
    // rob1, rob2, 0, 1, 2, 3, ..., nums.size() - 1

    int rob1 = 0, rob2 = 0;

    for (int& num : nums) {
      int tmp = max(num + rob1, rob2);
      rob1 = rob2;
      rob2 = tmp;
    }

    return rob2;
  }
};