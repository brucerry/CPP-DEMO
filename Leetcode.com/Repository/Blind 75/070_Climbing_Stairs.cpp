// https://leetcode.com/problems/climbing-stairs/

// time: O(n)
// space: O(1)

class Solution {
public:
  int climbStairs(int n) {
    int one = 1, two = 1;
    
    for (int i = 2; i <= n; i++) {
      int tmp = one + two;
      one = two;
      two = tmp;
    }
    
    return two;
  }
};