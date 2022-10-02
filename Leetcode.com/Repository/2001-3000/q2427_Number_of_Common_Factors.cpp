// https://leetcode.com/problems/number-of-common-factors/

// time: O(n)
// space: O(1)

class Solution {
public:
  int commonFactors(int a, int b) {
    int result = 0;
    for (int f = 1; f <= min(a, b); f++) {
      if (a % f == 0 and b % f == 0)
        result++;
    }
    return result;
  }
};