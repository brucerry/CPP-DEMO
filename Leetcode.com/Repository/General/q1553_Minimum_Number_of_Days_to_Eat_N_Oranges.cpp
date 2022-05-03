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
    if (n <= 2)
      return n;
    
    if (memo.count(n))
      return memo[n];
    
    int divisible_2 = 1 + (n % 2) + solve(n >> 1, memo);
    int divisible_3 = 1 + (n % 3) + solve(n / 3, memo);
    
    return memo[n] = min(divisible_2, divisible_3);
  }
};