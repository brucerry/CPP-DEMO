// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

// time: O(n)
// space: O(1)

class Solution {
public:
  int concatenatedBinary(int n) {
    long shift = 0, result = 0;
    for (int num = 1; num <= n; num++) {
      if ((num & (num - 1)) == 0)
        shift++;
      result = ((result << shift) | num) % 1000000007;
    }
    return result;
  }
};