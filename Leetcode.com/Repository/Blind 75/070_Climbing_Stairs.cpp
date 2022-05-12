// https://leetcode.com/problems/climbing-stairs/

// time: O(n)
// space: O(1)

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    
    int one = 1, two = 2;
    for (int i = 3; i <= n; i++) {
      int tmp = one + two;
      one = two;
      two = tmp;
    }
    
    return two;
  }
};