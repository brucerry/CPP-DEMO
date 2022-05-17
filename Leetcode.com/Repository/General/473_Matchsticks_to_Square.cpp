// https://leetcode.com/problems/matchsticks-to-square/

#include <vector>
#include <algorithm>
using namespace std;

// time: O(n * 2^n)
// space: O(2^n)

class Solution {
public:
  bool makesquare(vector<int>& matchsticks) {
    int n = matchsticks.size();
    
    int sum = 0;
    for (const int& len : matchsticks)
      sum += len;
    
    if (sum % 4)
      return false;
    
    int targetLen = sum >> 2;
    int all = (1 << n) - 1;
    vector<char> memo (all, -1);
    
    sort(matchsticks.rbegin(), matchsticks.rend()); // slightly speed optimized
    
    return solve(matchsticks, targetLen, all, memo, 4, 0, 0);
  }
  
private:
  bool solve(vector<int>& matchsticks, int targetLen, int all, vector<char>& memo, int side, int usedMask, int curLen) {
    if (curLen == targetLen) {
      curLen = 0;
      side--;
    }
    
    if (all == usedMask)
      return curLen == 0 and side == 0;
    
    if (memo[usedMask] != -1)
      return memo[usedMask];
    
    for (int i = 0; i < matchsticks.size(); i++) {
      if (curLen + matchsticks[i] <= targetLen and (usedMask & (1 << i)) == 0 and solve(matchsticks, targetLen, all, memo, side, usedMask | (1 << i), curLen + matchsticks[i]))
        return memo[usedMask] = true;
    }
    
    return memo[usedMask] = false;
  }
};