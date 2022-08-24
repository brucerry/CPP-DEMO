// https://leetcode.com/problems/power-of-three/

// time: O(1)
// space: O(1)

class Solution {
public:
  bool isPowerOfThree(int n) {
    if (n <= 0)
      return false;
    
    double x = log10(n) / log10(3);
    return x == int(x);
  }
};