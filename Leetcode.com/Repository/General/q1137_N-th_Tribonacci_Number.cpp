// https://leetcode.com/problems/n-th-tribonacci-number/

// time: O(n)
// space: O(1)

class Solution {
public:
  int tribonacci(int n) {
    if (n < 2) return n;
    
    int one = 0, two = 1, ans = 1;
    
    for (int i = 2; i < n; i++) {
      int tmp = ans;
      ans += one + two;
      one = two;
      two = tmp;
    }
    
    return ans;
  }
};