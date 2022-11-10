// https://leetcode.com/problems/sqrtx/

// time: O(log(x))
// space: O(1)

class Solution {
public:
  int mySqrt(int x) {
    long l = 0, r = x;
    while (l < r) {
      long m = l + (r - l + 1) / 2;
      if (m * m <= x)
        l = m;
      else
        r = m - 1;
    }
    return l;
  }
};