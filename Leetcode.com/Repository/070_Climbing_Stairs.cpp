// https://leetcode.com/problems/climbing-stairs/

// time: O(n)
// space: O(1)

class Solution {
public:
  int climbStairs(int n) {
    if (n < 3) return n;

    int first = 1;
    int second = 2;
    int ans;

    for (int i = 3; i <= n; i++) {
      ans = first + second;
      first = second;
      second = ans;
    }

    return ans;
  }
};