// https://leetcode.com/problems/matchsticks-to-square/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * 2^n)
// space: O(2^n)

class Solution {
public:
  bool makesquare(vector<int>& matchsticks) {
    int sum = 0;
    for (const int& matchstick : matchsticks)
      sum += matchstick;
    
    if (sum % 4)
      return false;
    
    int target = sum >> 2;
    int n = matchsticks.size();
    int all = (1 << n) - 1;
    vector<char> memo (all + 1, -1);
    
    sort(matchsticks.rbegin(), matchsticks.rend()); // slightly speed optimized
    
    return solve(matchsticks, target, all, memo, 4, 0, 0);
  }
  
private:
  bool solve(vector<int>& matchsticks, int target, int all, vector<char>& memo, int side, int subsum, int usedMask) {
    if (target == subsum) {
      subsum = 0;
      side--;
    }
    
    if (side == 0)
      return usedMask == all;
    
    if (memo[usedMask] != -1)
      return memo[usedMask];
    
    for (int i = 0; i < matchsticks.size(); i++) {
      if ((usedMask & (1 << i)) == 0 and subsum + matchsticks[i] <= target and solve(matchsticks, target, all, memo, side, subsum + matchsticks[i], usedMask | (1 << i)))
        return memo[usedMask] = true;
    }
    
    return memo[usedMask] = false;
  }
};