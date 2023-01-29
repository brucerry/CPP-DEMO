// https://leetcode.com/problems/powx-n/

// time: O(log(n))
// space: O(log(n))

class Solution {
public:
  double myPow(double x, int n) {
    double result = solve(x, abs(n));
    return n < 0 ? 1 / result : result;
  }
  
private:
  double solve(double x, int n) {
    if (!x)
      return 0;
    
    if (x == 1 or !n)
      return 1;
    
    // double result = solve(x, n / 2);
    // result *= result;
    double result = solve(x * x, n / 2);
    
    return n & 1 ? result * x : result;
  }
};