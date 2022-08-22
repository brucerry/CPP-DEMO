// https://leetcode.com/problems/power-of-four/

// time: O(1)
// space: O(1)

class Solution {
public:
  bool isPowerOfFour(int n) {
    if (n <= 0)
      return false;
    
    double x = log(n) / log(4);
    return x == int(x);
  }
};