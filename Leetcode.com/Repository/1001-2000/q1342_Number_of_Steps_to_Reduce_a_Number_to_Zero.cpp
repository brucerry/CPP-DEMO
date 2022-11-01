// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

// time: O(1)
// space: O(1)

class Solution {
public:
  int numberOfSteps(int num) {
    int result = 0;
    while (num) {
      result += num & 1 ? 2 : 1;
      num >>= 1;
    }
    return max(0, result - 1);
  }
};