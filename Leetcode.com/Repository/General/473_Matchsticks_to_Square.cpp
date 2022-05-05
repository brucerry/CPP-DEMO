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
    for (const int& len : matchsticks) {
      sum += len;
    }
    
    if (sum % 4)
      return false;
    
    int target = sum >> 2;
    int all = (1 << matchsticks.size()) - 1;
    vector<char> memo (all, -1);
    
    sort(matchsticks.rbegin(), matchsticks.rend()); // slightly speed optimized
    
    return solve(matchsticks, target, all, memo, 4, 0, 0);
  }
  
private:
  bool solve(vector<int>& matchsticks, int target, int all, vector<char>& memo, int count, int subsum, int usedMask) {
    if (subsum == target) {
      count--;
      subsum = 0;
    }
    
    if (usedMask == all)
      return count == 0 and subsum == 0;
    
    if (memo[usedMask] != -1)
      return memo[usedMask];
    
    for (int i = 0; i < matchsticks.size(); i++) {
      if (subsum + matchsticks[i] <= target and (usedMask & (1 << i)) == 0 and solve(matchsticks, target, all, memo, count, subsum + matchsticks[i], usedMask | (1 << i))) {
        return memo[usedMask] = true;
      }
    }
    
    return memo[usedMask] = false;
  }
};