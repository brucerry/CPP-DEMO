// https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

#include <unordered_map>
using namespace std;

// time: O(log(n))
// space: O(log(n))

class Solution {
public:
  int minDays(int n) {
    unordered_map<int, int> memo;    
    return solve(n, memo);
  }
  
private:
  int solve(int n, unordered_map<int, int>& memo) {
    if (n <= 1)
      return n;
    
    if (memo.count(n))
      return memo[n];
    
    int div_2 = 1 + (n & 1) + solve(n >> 1, memo);
    int div_3 = 1 + (n % 3) + solve(n / 3, memo);
    
    return memo[n] = min(div_2, div_3);
  }
};