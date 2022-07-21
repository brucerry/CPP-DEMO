// https://leetcode.com/problems/a-number-after-a-double-reversal/

// time: O(1)
// space: O(1)

class Solution {
public:
  bool isSameAfterReversals(int num) {
    return num == 0 or num % 10;
  }
};