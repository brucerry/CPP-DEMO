// https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/

// time: O(n)
// space: size of the recursive call stack

class Solution {
public:
  int smallestValue(int n) {
    int copy = n, sum = 0;
    for (int factor = 2; factor <= n; factor++) {
      while (copy % factor == 0) {
        sum += factor;
        copy /= factor;
      }
    }
    return sum == n ? n : smallestValue(sum);
  }
};