// https://leetcode.com/problems/climbing-stairs/

// time: O(n)
// space: O(1)

class Solution {
public:
  int climbStairs(int n) {
    if (n < 3) return n;
    
    int one = 1, ans = 2;
    
    for (int i = 3; i <= n; i++) {
      int tmp = ans;
      ans += one;
      one = tmp;
    }
    
    return ans;
  }
};