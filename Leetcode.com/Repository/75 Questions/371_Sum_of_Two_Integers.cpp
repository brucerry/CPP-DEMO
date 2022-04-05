// https://leetcode.com/problems/sum-of-two-integers/

// time: O(1)
// space: O(1)

class Solution {
public:
  int getSum(int a, int b) {
    while (b) {
      int tmp = (unsigned int)(a & b) << 1; // carry
      a ^= b;
      b = tmp;
    }
    return a;
  }
};