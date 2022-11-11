// https://leetcode.com/problems/sum-of-square-numbers/

// time: O(sqrt(c) * log(c))
// space: O(1)

class Solution {
public:
  bool judgeSquareSum(int c) {
    for (long a = 0; a * a <= c; a++) {
      if (isPerfectSquare(c - a * a))
        return true;
    }
    return false;
  }

private:
  bool isPerfectSquare(int b_square) {
    long l = 0, r = b_square;
    while (l <= r) {
      long m = l + (r - l) / 2;
      long ans = m * m;
      if (ans < b_square)
        l = m + 1;
      else if (ans > b_square)
        r = m - 1;
      else
        return true;
    }
    return false;
  }
};