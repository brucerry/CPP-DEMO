// https://leetcode.com/problems/bitwise-and-of-numbers-range/

// time: O(31)
// space: O(1)

class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    for (; left < right; right &= (right - 1));
    return right;
  }
};