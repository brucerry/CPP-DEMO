// https://leetcode.com/problems/valid-perfect-square/

// time: O(log(n))
// space: O(1)

class Solution {
public:
  bool isPerfectSquare(int num) {
    long l = 1, r = num;
    
    while (l < r) {
      long m = l + ((r - l) >> 1);
      
      if (num <= m * m)
        r = m;
      else
        l = m + 1;
    }
    
    return l * l == num;
  }
};