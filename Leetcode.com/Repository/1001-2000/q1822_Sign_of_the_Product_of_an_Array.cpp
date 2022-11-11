// https://leetcode.com/problems/sign-of-the-product-of-an-array/

#include <vector>
using namespace std;

// time: O(n)
// space: O(1)

class Solution {
public:
  int arraySign(vector<int>& nums) {
    int sign = 1;
    for (const int& num : nums) {
      if (!num)
        return 0;
      if (num < 0)
        sign *= -1;
    }
    return sign;
  }
};