// https://leetcode.com/problems/powx-n/

// time: O(log(n))
// space: O(log(n))

class Solution {
public:
  double myPow(double x, int n) {
    double ans = solve(x, abs(n));
    return n < 0 ? 1 / ans : ans;
  }
  
private:
  double solve(double x, int n) {
    if (!x)
      return 0;
    
    if (!n || x == 1)
      return 1;
    
    double ans = solve(x * x, n / 2);
    
    return n % 2 ? x * ans : ans;
  }
};